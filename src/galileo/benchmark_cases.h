#ifndef BENCHMARK_CASES_H_
#define BENCHMARK_CASES_H_

void benchmark_add_simple();


typedef void (*benchmark_handler)(void);
const benchmark_handler BENCHMARK_FUNCTIONS[] = { benchmark_add_simple };

#endif

