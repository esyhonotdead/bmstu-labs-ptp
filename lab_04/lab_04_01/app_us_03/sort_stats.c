#define _POSIX_C_SOURCE 200112L
#include <math.h>
#include <stddef.h>
#include <time.h>

#define TO_US_SECONDS 1e6
#define TO_US_NSECONDS 1e3

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
double calculate_time(double filled_array[], size_t arr_len, void (*sort_type)(double[], size_t))
{
    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    sort_type(filled_array, arr_len);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double elapsed = (end.tv_sec - start.tv_sec) * TO_US_SECONDS;
    elapsed += (end.tv_nsec - start.tv_nsec) / TO_US_NSECONDS;
    return elapsed;
}

// минимальное/максимальное время
void find_min_max_time(double curr_time, double *min_time, double *max_time)
{
    *min_time = curr_time;
    *max_time = curr_time;

    if (curr_time < *min_time)
        *min_time = curr_time;
    if (curr_time > *max_time)
        *max_time = curr_time;
}
