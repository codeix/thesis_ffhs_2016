/* benchmark_bind.h -- Benchmark
 *
 * Copyright (C) 2016 copyright Samuel Riolo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */




/* do not modify this file because it was generated automatically */



#include <linux/seq_file.h>

int benchmark_show_sadd16_8(struct seq_file*, void*);
int benchmark_show_lsr_32(struct seq_file*, void*);
int benchmark_show_add_32(struct seq_file*, void*);
int benchmark_show_lsl_32(struct seq_file*, void*);
int benchmark_show_sub_0(struct seq_file*, void*);
int benchmark_show_xor_32(struct seq_file*, void*);
int benchmark_show_and_0(struct seq_file*, void*);
int benchmark_show_sub_32(struct seq_file*, void*);
int benchmark_show_nop(struct seq_file*, void*);
int benchmark_show_lsr_0(struct seq_file*, void*);
int benchmark_show_nop_nop_nop(struct seq_file*, void*);
int benchmark_show_or_0(struct seq_file*, void*);
int benchmark_show_sadd16_0(struct seq_file*, void*);
int benchmark_show_sadd8_0(struct seq_file*, void*);
int benchmark_show_add_0(struct seq_file*, void*);
int benchmark_show_mul_0(struct seq_file*, void*);
int benchmark_show_mul_32(struct seq_file*, void*);
int benchmark_show_and_32(struct seq_file*, void*);
int benchmark_show_sadd8_8(struct seq_file*, void*);
int benchmark_show_or_32(struct seq_file*, void*);
int benchmark_show_xor_0(struct seq_file*, void*);
int benchmark_show_lsl_0(struct seq_file*, void*);
int benchmark_show_nop_nop(struct seq_file*, void*);


typedef int(*benchmark_show_bind)(struct seq_file*, void*);
const benchmark_show_bind BENCHMARK_SHOW_BIND[] = { benchmark_show_sadd16_8,
benchmark_show_lsr_32,
benchmark_show_add_32,
benchmark_show_lsl_32,
benchmark_show_sub_0,
benchmark_show_xor_32,
benchmark_show_and_0,
benchmark_show_sub_32,
benchmark_show_nop,
benchmark_show_lsr_0,
benchmark_show_nop_nop_nop,
benchmark_show_or_0,
benchmark_show_sadd16_0,
benchmark_show_sadd8_0,
benchmark_show_add_0,
benchmark_show_mul_0,
benchmark_show_mul_32,
benchmark_show_and_32,
benchmark_show_sadd8_8,
benchmark_show_or_32,
benchmark_show_xor_0,
benchmark_show_lsl_0,
benchmark_show_nop_nop };
const char* BENCHMARK_SHOW_NAME[] = {"sadd16_8",
"lsr_32",
"add_32",
"lsl_32",
"sub_0",
"xor_32",
"and_0",
"sub_32",
"nop",
"lsr_0",
"nop_nop_nop",
"or_0",
"sadd16_0",
"sadd8_0",
"add_0",
"mul_0",
"mul_32",
"and_32",
"sadd8_8",
"or_32",
"xor_0",
"lsl_0",
"nop_nop"};
const int BENCHMARK_SHOW_LENGTH = 23;

