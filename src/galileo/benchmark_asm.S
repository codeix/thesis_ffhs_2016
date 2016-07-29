/* benchmark_asm.S -- Benchmark
 *
 * Copyright (C) 2016 copyright Samuel Riolo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */




/* do not modify this file because it was generated automatically */




.section .text

.global benchmark_xor_32
.type benchmark_xor_32, @function

benchmark_xor_32:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0xFFFFFFFF, %eax
  movl $0xFFFFFFFF, %ebx
loop_benchmark_xor_32:
  xor %ebx, %eax
  movl $0xFFFFFFFF, %ebx
  loop loop_benchmark_xor_32

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_nop_nop
.type benchmark_nop_nop, @function

benchmark_nop_nop:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx

loop_benchmark_nop_nop:
  nop
  nop
  loop loop_benchmark_nop_nop

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_and_0
.type benchmark_and_0, @function

benchmark_and_0:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0x00000000, %eax
  movl $0x00000000, %ebx
loop_benchmark_and_0:
  and %ebx, %eax
  movl $0x00000000, %ebx
  loop loop_benchmark_and_0

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_or_0
.type benchmark_or_0, @function

benchmark_or_0:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0x00000000, %eax
  movl $0x00000000, %ebx
loop_benchmark_or_0:
  or %ebx, %eax
  movl $0x00000000, %ebx
  loop loop_benchmark_or_0

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_imull_32
.type benchmark_imull_32, @function

benchmark_imull_32:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0xFFFFFFFF, %eax
  movl $0xFFFFFFFF, %ebx
loop_benchmark_imull_32:
  imull %ebx, %eax
  movl $0xFFFFFFFF, %ebx
  loop loop_benchmark_imull_32

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_shl_0
.type benchmark_shl_0, @function

benchmark_shl_0:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0x00000000, %ebx
loop_benchmark_shl_0:
  shl $1, %ebx
  movl $0x00000000, %ebx
  loop loop_benchmark_shl_0

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_shl_32
.type benchmark_shl_32, @function

benchmark_shl_32:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0xFFFFFFFF, %ebx
loop_benchmark_shl_32:
  shl $1, %ebx
  movl $0xFFFFFFFF, %ebx
  loop loop_benchmark_shl_32

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_dec_8
.type benchmark_dec_8, @function

benchmark_dec_8:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0x000000FF, %ebx
loop_benchmark_dec_8:
  dec  %ebx
  movl $0x000000FF, %ebx
  loop loop_benchmark_dec_8

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_xor_0
.type benchmark_xor_0, @function

benchmark_xor_0:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0x00000000, %eax
  movl $0x00000000, %ebx
loop_benchmark_xor_0:
  xor %ebx, %eax
  movl $0x00000000, %ebx
  loop loop_benchmark_xor_0

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_addl_0
.type benchmark_addl_0, @function

benchmark_addl_0:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0, %eax
  movl $0, %ebx
loop_benchmark_addl_0:
  addl %ebx, %eax
  movl $0, %ebx
  loop loop_benchmark_addl_0

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_addl_32
.type benchmark_addl_32, @function

benchmark_addl_32:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0xFFFFFFFF, %eax
  movl $0xFFFFFFFF, %ebx
loop_benchmark_addl_32:
  addl %ebx, %eax
  movl $0xFFFFFFFF, %ebx
  loop loop_benchmark_addl_32

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_nop
.type benchmark_nop, @function

benchmark_nop:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx

loop_benchmark_nop:
  nop
  loop loop_benchmark_nop

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_shr_32
.type benchmark_shr_32, @function

benchmark_shr_32:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0xFFFFFFFF, %ebx
loop_benchmark_shr_32:
  shr $1, %ebx
  movl $0xFFFFFFFF, %ebx
  loop loop_benchmark_shr_32

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_nop_nop_nop
.type benchmark_nop_nop_nop, @function

benchmark_nop_nop_nop:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx

loop_benchmark_nop_nop_nop:
  nop
  nop
  nop
  loop loop_benchmark_nop_nop_nop

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_shr_0
.type benchmark_shr_0, @function

benchmark_shr_0:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0x00000000, %ebx
loop_benchmark_shr_0:
  shr $1, %ebx
  movl $0x00000000, %ebx
  loop loop_benchmark_shr_0

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_and_32
.type benchmark_and_32, @function

benchmark_and_32:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0xFFFFFFFF, %eax
  movl $0xFFFFFFFF, %ebx
loop_benchmark_and_32:
  and %ebx, %eax
  movl $0xFFFFFFFF, %ebx
  loop loop_benchmark_and_32

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_or_32
.type benchmark_or_32, @function

benchmark_or_32:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0xFFFFFFFF, %eax
  movl $0xFFFFFFFF, %ebx
loop_benchmark_or_32:
  or %ebx, %eax
  movl $0xFFFFFFFF, %ebx
  loop loop_benchmark_or_32

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_imull_0
.type benchmark_imull_0, @function

benchmark_imull_0:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0, %eax
  movl $0, %ebx
loop_benchmark_imull_0:
  imull %ebx, %eax
  movl $0, %ebx
  loop loop_benchmark_imull_0

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_inc_8
.type benchmark_inc_8, @function

benchmark_inc_8:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0x000000FF, %ebx
loop_benchmark_inc_8:
  inc  %ebx
  movl $0x000000FF, %ebx
  loop loop_benchmark_inc_8

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_subl_0
.type benchmark_subl_0, @function

benchmark_subl_0:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0, %eax
  movl $0, %ebx
loop_benchmark_subl_0:
  subl %ebx, %eax
  movl $0, %ebx
  loop loop_benchmark_subl_0

  pop %ecx
  pop %eax
  pop %ebx
  ret

.global benchmark_subl_32
.type benchmark_subl_32, @function

benchmark_subl_32:
  push %ecx
  push %eax
  push %ebx
  movl $2147483648, %ecx
  movl $0xFFFFFFFF, %eax
  movl $0xFFFFFFFF, %ebx
loop_benchmark_subl_32:
  subl %ebx, %eax
  movl $0xFFFFFFFF, %ebx
  loop loop_benchmark_subl_32

  pop %ecx
  pop %eax
  pop %ebx
  ret

