#include <math.h>
#include <stddef.h>
#include <x86intrin.h>

#include "errors.h"

double time_avg(double sum, size_t iter_i)
{
    return sum / iter_i;
}

double calculate_rse(double sum, double sum_sq, size_t iter_i)
{
    if (iter_i < 2)
        return UNEXPECTED_ERR;

    const double mean = sum / iter_i;
    if (fabs(mean) < 1e-12)
        return RANGE_ERR;

    return (sqrt(fmax(sum_sq - sum * sum / iter_i, 0.0) / (iter_i - 1)) / sqrt(iter_i) / mean * 100);
}

// подсчет времени выполнения
double calculate_time(double filled_array[], const size_t arr_len, void (*sort_type)(double[], size_t))
{
    double t_beg, t_end;
    t_beg = __rdtsc();
    sort_type(filled_array, arr_len);
    t_end = __rdtsc();
    return t_end - t_beg;
}

// минимальное/максимальное время
void find_min_max_time(double curr_time, double *min_time, double *max_time)
{
    if (curr_time < *min_time)
        *min_time = curr_time;
    if (curr_time > *max_time)
        *max_time = curr_time;
}
