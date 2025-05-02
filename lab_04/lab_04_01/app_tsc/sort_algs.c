#include <stddef.h>

// доступ через a[i]
void insertion_sort_ind(double array[], size_t len)
{
    for (size_t i = 1; i < len; i++)
    {
        double temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

// доступ через память
void insertion_sort_mem(double array[], size_t len)
{
    for (size_t i = 1; i < len; i++)
    {
        double temp = *(array + i);
        int j = i - 1;
        while (j >= 0 && *(array + j) > temp)
        {
            *(array + j + 1) = *(array + j);
            j--;
        }
        *(array + j + 1) = temp;
    }
}

// доступ через указатели
void insertion_sort_ptr(double array[], size_t len)
{
    double *end = array + len;
    for (double *ptr = array + 1; ptr < end; ptr++)
    {
        double temp = *ptr;
        double *current = ptr - 1;
        while (current >= array && *current > temp)
        {
            *(current + 1) = *current;
            current--;
        }
        *(current + 1) = temp;
    }
}
