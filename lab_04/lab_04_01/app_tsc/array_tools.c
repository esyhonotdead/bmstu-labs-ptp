#include <math.h>
#include <stdio.h>

#include "sort_stats.h"

// заполнение массива в обр порядке
void fill_array(double array[], size_t arr_len)
{
    for (size_t i = 0; i < arr_len; i++)
    {
        array[i] = arr_len - i;
    }
}

// общая логика
void process(double array[], size_t arrays_capacity, size_t max_iter, void (*sort_type)(double[], size_t))
{
    size_t iter_i = 0;
    double time, sum = 0, sum_sq = 0;
    double rse_num = 100.0;
    double min_time = INFINITY, max_time = -INFINITY;
    do
    {
        fill_array(array, arrays_capacity);
        time = calculate_time(array, arrays_capacity, sort_type);
        sum += time;
        sum_sq += (time * time);
        iter_i++;
        find_min_max_time(time, &min_time, &max_time);
        if (iter_i > 10)
            rse_num = calculate_rse(sum, sum_sq, iter_i);
    } while (iter_i < max_iter && rse_num > 1);
    printf("%zu %6zu %7lf %8lf %9.1lf. %10.1lf\n", arrays_capacity, iter_i, time_avg(sum, iter_i), rse_num, min_time,
           max_time);
}
