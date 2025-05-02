#include <stdio.h>

typedef union {
    int age;
    char gender;
    float height;
} Human;

int main(void)
{
    Human you = {you.height = 183.761};
    return 0;
}