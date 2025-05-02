#include <stdio.h>

#define I 2
#define J 3
#define K 4

int main(void)
{
    int matrix[I][J][K];
    for (size_t i = 0; i < I * J * K; i++)
    {
        (**matrix)[i] = i;
    }
    return 0;
}