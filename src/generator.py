#!/usr/bin/env python3

"""
benchmark_asm.S -- Benchmark

Copyright (C) 2016 copyright Samuel Riolo

This software may be modified and distributed under the terms
of the MIT license.  See the LICENSE file for details.
"""

import os
import sys
import configparser
from collections import defaultdict


LOOP_COUNT = 2147483648

def main():
    config = configparser.RawConfigParser(dict_type=lambda: defaultdict(list))
    config.sections()
    subdir = sys.argv[1]
    config.read(os.path.join((subdir, 'benchmark_data.ini')))

    gen_asm(config)
    gen_asm_header(config)
    gen_bind(config)
    gen_bind_header(config)

    print('ASM code generated')

def license(filename):
    return LICENSE_C % dict(filename=filename)

def ident(value):
    value = value if value else ''
    return '\n'.join(['  %s' %i.strip() for i in value.split('\n') if i])

def default_content(filename, content=None):
    di = dict(license=license(filename),
              auto_gen=AUTO_GEN)
    if content:
        di['content'] = content
    return di

def gen_asm(config):
    asm_part=dict(galileo=ASM_PART_GALILEO, raspberry=ASM_PART_RASPBERRY)[sys.argv[1]]
    filename = 'benchmark_asm.S'
    content = ''
    for sec in config.sections():
        data = dict(func_name=sec,
                    pre=ident(config.get(sec, 'pre')),
                    post=ident(config.get(sec, 'post')),
                    bench=ident(config.get(sec, 'bench')),
                    loop_count=LOOP_COUNT)
        content += asm_part % data
    
    data = default_content(filename, content)
    with open(filename, 'w') as f:
        f.write((ASM_BODY % data).strip() + '\n\n')
    
def gen_asm_header(config):
    filename = 'benchmark_asm.h'
    content = ''
    for sec in config.sections():
        content += 'void benchmark_%s(void);\n' % sec 
    data = default_content(filename, content)
    filedata = '%(license)s\n\n%(auto_gen)s\n\n\n%(content)s' % data
    with open(filename, 'w') as f:
        f.write((filedata).strip() + '\n\n')

def gen_bind(config):
    filename = 'benchmark_bind.c'
    content = '#include "benchmark_asm.h"\n#include <linux/seq_file.h>\n#include <linux/jiffies.h> \n\n'
    content = BIND_CONTENT
    for sec in config.sections():
        content += BIND_PART % dict(func_name=sec)
    data = default_content(filename, content)
    filedata = '%(license)s\n\n%(auto_gen)s\n\n\n%(content)s' % data
    with open(filename, 'w') as f:
        f.write((filedata).strip() + '\n\n')

def gen_bind_header(config):
    filename = 'benchmark_bind.h'
    content = '#include <linux/seq_file.h>\n\n'
    for sec in config.sections():
        content += 'int benchmark_show_%s(struct seq_file*, void*);\n' % sec
    functions = ',\n'.join(['benchmark_show_%s' % i for i in config.sections()])
    function_names = ',\n'.join([ '"%s"' % i for i in config.sections()])
    content += BIND_ARRAY % dict(functions=functions,
                                 function_names=function_names,
                                 benchmark_length=len(config.sections()))
    data = default_content(filename, content)
    filedata = '%(license)s\n\n%(auto_gen)s\n\n\n%(content)s' % data
    with open(filename, 'w') as f:
        f.write((filedata).strip() + '\n\n')


LICENSE_C="""
/* %(filename)s -- Benchmark
 *
 * Copyright (C) 2016 copyright Samuel Riolo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

"""

AUTO_GEN="""
/* do not modify this file because it was generated automatically */
"""

ASM_BODY="""
%(license)s

%(auto_gen)s



.section .text
%(content)s

"""

ASM_PART_GALILEO="""
.global benchmark_%(func_name)s
.type benchmark_%(func_name)s, @function

benchmark_%(func_name)s:
  push %%ecx
  movl $%(loop_count)s, %%ecx
%(pre)s
loop_benchmark_%(func_name)s:
%(bench)s
  loop loop_benchmark_%(func_name)s
%(post)s
  pop %%ecx
  ret
"""

ASM_PART_RASPBERRY="""

.global benchmark_%(func_name)s

benchmark_%(func_name)s:
  stmfd    sp!, {r0-r5}
  ldr r1, =%(loop_count)s  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
%(pre)s
loop_benchmark_%(func_name)s:
%(bench)s
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_%(func_name)s       /* branch if r1 >= 100 */
%(post)s
  ldmfd    sp!, {r0-r5}
  bx  lr

"""

BIND_CONTENT="""
#include "benchmark_asm.h"
#include <linux/seq_file.h>
#include <linux/interrupt.h>
#include <linux/time.h>
#ifdef RASPBERRY
#include <linux/timekeeping.h>
#endif


#ifdef RASPBERRY
#define REPEAT_BENCHMARK 10
#endif

#ifdef GALILEO
#define REPEAT_BENCHMARK 3
#endif


unsigned long timer_end(struct timeval start_time)
{
    struct timeval end_time;
    do_gettimeofday(&end_time);
    return((end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec)/1000) ;
}

struct timeval timer_start(void)
{
    struct timeval start_time;
    do_gettimeofday(&start_time);
    return start_time;
}


"""


BIND_PART="""
int benchmark_show_%(func_name)s(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_%(func_name)s();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%%lu\\n", exec_time);
    return 0;
}
"""

BIND_ARRAY="""

typedef int(*benchmark_show_bind)(struct seq_file*, void*);
const benchmark_show_bind BENCHMARK_SHOW_BIND[] = { %(functions)s };
const char* BENCHMARK_SHOW_NAME[] = {%(function_names)s};
const int BENCHMARK_SHOW_LENGTH = %(benchmark_length)s;


"""

if __name__ == "__main__":
    main()
