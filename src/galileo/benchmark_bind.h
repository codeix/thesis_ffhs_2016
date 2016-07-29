/* benchmark_bind.h -- Benchmark
 *
 * Copyright (C) 2016 copyright Samuel Riolo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */




/* do not modify this file because it was generated automatically */



#include <linux/seq_file.h>

int benchmark_show_xor_32(struct seq_file*, void*);
int benchmark_show_nop_nop(struct seq_file*, void*);
int benchmark_show_and_0(struct seq_file*, void*);
int benchmark_show_or_0(struct seq_file*, void*);
int benchmark_show_imull_32(struct seq_file*, void*);
int benchmark_show_shl_0(struct seq_file*, void*);
int benchmark_show_shl_32(struct seq_file*, void*);
int benchmark_show_dec_8(struct seq_file*, void*);
int benchmark_show_xor_0(struct seq_file*, void*);
int benchmark_show_addl_0(struct seq_file*, void*);
int benchmark_show_addl_32(struct seq_file*, void*);
int benchmark_show_nop(struct seq_file*, void*);
int benchmark_show_shr_32(struct seq_file*, void*);
int benchmark_show_nop_nop_nop(struct seq_file*, void*);
int benchmark_show_shr_0(struct seq_file*, void*);
int benchmark_show_and_32(struct seq_file*, void*);
int benchmark_show_or_32(struct seq_file*, void*);
int benchmark_show_imull_0(struct seq_file*, void*);
int benchmark_show_inc_8(struct seq_file*, void*);
int benchmark_show_subl_0(struct seq_file*, void*);
int benchmark_show_subl_32(struct seq_file*, void*);


typedef int(*benchmark_show_bind)(struct seq_file*, void*);
const benchmark_show_bind BENCHMARK_SHOW_BIND[] = { benchmark_show_xor_32,
benchmark_show_nop_nop,
benchmark_show_and_0,
benchmark_show_or_0,
benchmark_show_imull_32,
benchmark_show_shl_0,
benchmark_show_shl_32,
benchmark_show_dec_8,
benchmark_show_xor_0,
benchmark_show_addl_0,
benchmark_show_addl_32,
benchmark_show_nop,
benchmark_show_shr_32,
benchmark_show_nop_nop_nop,
benchmark_show_shr_0,
benchmark_show_and_32,
benchmark_show_or_32,
benchmark_show_imull_0,
benchmark_show_inc_8,
benchmark_show_subl_0,
benchmark_show_subl_32 };
const char* BENCHMARK_SHOW_NAME[] = {"xor_32",
"nop_nop",
"and_0",
"or_0",
"imull_32",
"shl_0",
"shl_32",
"dec_8",
"xor_0",
"addl_0",
"addl_32",
"nop",
"shr_32",
"nop_nop_nop",
"shr_0",
"and_32",
"or_32",
"imull_0",
"inc_8",
"subl_0",
"subl_32"};
const int BENCHMARK_SHOW_LENGTH = 21;

