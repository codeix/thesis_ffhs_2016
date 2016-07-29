/* benchmark_asm.S -- Benchmark
 *
 * Copyright (C) 2016 copyright Samuel Riolo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */




/* do not modify this file because it was generated automatically */




.section .text


.global benchmark_sadd16_8

benchmark_sadd16_8:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0000FFFF
  ldr r4, = 0x0000FFFF
loop_benchmark_sadd16_8:
  sadd16 r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_sadd16_8       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_lsr_32

benchmark_lsr_32:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0xFFFFFFFF
loop_benchmark_lsr_32:
  lsr r5, r3, #1
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_lsr_32       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_add_32

benchmark_add_32:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0xFFFFFFFF
  ldr r4, = 0xFFFFFFFF
loop_benchmark_add_32:
  add r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_add_32       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_lsl_32

benchmark_lsl_32:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0xFFFFFFFF
loop_benchmark_lsl_32:
  lsl r5, r3, #1
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_lsl_32       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_sub_0

benchmark_sub_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_sub_0:
  sub r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_sub_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_xor_32

benchmark_xor_32:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0xFFFFFFFF
  ldr r4, = 0xFFFFFFFF
loop_benchmark_xor_32:
  eor r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_xor_32       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_and_0

benchmark_and_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_and_0:
  and r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_and_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_sub_32

benchmark_sub_32:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0xFFFFFFFF
  ldr r4, = 0xFFFFFFFF
loop_benchmark_sub_32:
  sub r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_sub_32       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_nop

benchmark_nop:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */

loop_benchmark_nop:
  nop
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_nop       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_lsr_0

benchmark_lsr_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_lsr_0:
  lsr r5, r3, #1
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_lsr_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_nop_nop_nop

benchmark_nop_nop_nop:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */

loop_benchmark_nop_nop_nop:
  nop
  nop
  nop
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_nop_nop_nop       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_or_0

benchmark_or_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_or_0:
  orr r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_or_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_sadd16_0

benchmark_sadd16_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_sadd16_0:
  sadd16 r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_sadd16_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_sadd8_0

benchmark_sadd8_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_sadd8_0:
  sadd8 r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_sadd8_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_add_0

benchmark_add_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_add_0:
  add r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_add_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_mul_0

benchmark_mul_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_mul_0:
  mul r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_mul_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_mul_32

benchmark_mul_32:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0xFFFFFFFF
  ldr r4, = 0xFFFFFFFF
loop_benchmark_mul_32:
  mul r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_mul_32       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_and_32

benchmark_and_32:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0xFFFFFFFF
  ldr r4, = 0xFFFFFFFF
loop_benchmark_and_32:
  and r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_and_32       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_sadd8_8

benchmark_sadd8_8:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x000000FF
  ldr r4, = 0x000000FF
loop_benchmark_sadd8_8:
  sadd8 r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_sadd8_8       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_or_32

benchmark_or_32:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0xFFFFFFFF
  ldr r4, = 0xFFFFFFFF
loop_benchmark_or_32:
  orr r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_or_32       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_xor_0

benchmark_xor_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
  ldr r4, = 0x0
loop_benchmark_xor_0:
  eor r5, r3, r4
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_xor_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_lsl_0

benchmark_lsl_0:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */
  ldr r3, = 0x0
loop_benchmark_lsl_0:
  lsl r5, r3, #1
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_lsl_0       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr



.global benchmark_nop_nop

benchmark_nop_nop:
  stmfd    sp!, {r0-r5}
  ldr r1, =2147483648  /*Pseudo instruction for something like ldr r8, [pc, #offset] */

loop_benchmark_nop_nop:
  nop
  nop
  sub r1, r1, #1      /* r1 ← r1 - 1 */
  cmp r1, #0          /* update cpsr with r1 - 0 */
  bge loop_benchmark_nop_nop       /* branch if r1 >= 100 */

  ldmfd    sp!, {r0-r5}
  bx  lr

