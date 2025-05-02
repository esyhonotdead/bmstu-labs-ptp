#include <stdbool.h>
#include <stdio.h>

#define MAX_WORD_LEN 25 + 1

// #pragma pack(push, 1)
typedef struct
{
    char bookName[MAX_WORD_LEN];
    char bookAuthor[MAX_WORD_LEN];
    int bookPages;
    bool isReaded;
} Book;
// #pragma pack(pop)

int main(void)
{
    Book book_about_c = {
        .bookName = "The C Programmin Language",
        .bookAuthor = "K&R",
        .bookPages = 274,
        .isReaded = false,
    };
    return 0;
}