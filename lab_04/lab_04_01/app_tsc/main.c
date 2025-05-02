#include "array_tools.h"
#include "errors.h"
#include "io.h"
#include "sort_stats.h"

#define MAX_ARRAY_CAPACITY 1000

int main(void)
{
    double array[MAX_ARRAY_CAPACITY];
    void (*sort_type)(double[], size_t);
    int rc;
    size_t max_iter;
    rc = input_parameters(&sort_type, &max_iter);
    if (rc != OK)
    {
        return rc;
    }
    for (size_t arr_capacity = 10; (arr_capacity <= MAX_ARRAY_CAPACITY); (arr_capacity += -(arr_capacity % 50) + 50))
    {
        process(array, arr_capacity, max_iter, sort_type);
    }
    return rc;
}
