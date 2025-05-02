#include <stdio.h>

#include "errors.h"
#include "sort_algs.h"

// входные данные
int input_parameters(void (**sort_type)(double[], size_t), size_t *max_iter)
{
    size_t sort_num;
    if (scanf("%zu %zu", &sort_num, max_iter) != 2)
        return IO_ERR;

    switch (sort_num)
    {
    case 0:
        *sort_type = insertion_sort_ind;
        break;
    case 1:
        *sort_type = insertion_sort_mem;
        break;
    case 2:
        *sort_type = insertion_sort_ptr;
        break;
    default:
        return IO_ERR;
    }
    return OK;
}
