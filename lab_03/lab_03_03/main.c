#include <stdio.h>

#define MAX_WORD_LEN 10

int main(void)
{
    // строка
    char string[] = "Hello, World!";
    printf("%s\n", string);

    // массив строк как матрица
    char words_matrix[][MAX_WORD_LEN] = {"public", "class", "void"};
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n", words_matrix[i]);
    }

    // массив строк как массив указателей
    char *words_pointers[] = {"public", "class", "void"};
    for (size_t i = 0; i < 3; i++)
    {
        printf("%s\n", words_pointers[i]);
    }

    return 0;
}