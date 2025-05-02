#ifndef ARRAY_TOOLS__
#define ARRAY_TOOLS__

#include <stddef.h>

void fill_array(double array[], size_t arr_len);
void process(double array[], size_t arrays_capacity, size_t max_iter, void (*sort_type)(double[], size_t));

#endif
