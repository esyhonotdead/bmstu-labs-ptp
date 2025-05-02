#ifndef SORT_STATISTICS__
#define SORT_STATISTICS__

#include <stddef.h>
#include <x86intrin.h>

double time_avg(double sum, size_t iter_i);
double calculate_rse(double sum, double sum_sq, size_t iter_i);
double calculate_time(double filled_array[], size_t arr_len, void (*sort_type)(double[], size_t));
void find_min_max_time(double time, double *min_time, double *max_time);

#endif
