/* benchmark_bind.c -- Benchmark
 *
 * Copyright (C) 2016 copyright Samuel Riolo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */




/* do not modify this file because it was generated automatically */




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



int benchmark_show_xor_32(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_xor_32();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_nop_nop(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_nop_nop();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_and_0(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_and_0();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_or_0(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_or_0();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_imull_32(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_imull_32();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_shl_0(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_shl_0();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_shl_32(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_shl_32();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_dec_8(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_dec_8();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_xor_0(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_xor_0();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_addl_0(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_addl_0();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_addl_32(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_addl_32();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_nop(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_nop();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_shr_32(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_shr_32();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_nop_nop_nop(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_nop_nop_nop();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_shr_0(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_shr_0();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_and_32(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_and_32();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_or_32(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_or_32();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_imull_0(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_imull_0();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_inc_8(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_inc_8();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_subl_0(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_subl_0();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

int benchmark_show_subl_32(struct seq_file* m, void* v)
{
    int i;
    unsigned long flags; 
    struct timeval start_time;
    unsigned long  exec_time;
    
    local_irq_save(flags);
    start_time = timer_start();
    for (i = 0; i < REPEAT_BENCHMARK; i++)
        benchmark_subl_32();
    exec_time = timer_end(start_time);
    local_irq_restore(flags);
    seq_printf(m, "%lu\n", exec_time);
    return 0;
}

