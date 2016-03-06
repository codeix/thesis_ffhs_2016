.section .text
.globl benchmark_add_simple
.type benchmark_add_simple, @function

benchmark_add_simple:
  push %ecx
  movl $100000000, %ecx
loop_benchmark_add_simple:
  loop loop_benchmark_add_simple
  pop %ecx
  ret

