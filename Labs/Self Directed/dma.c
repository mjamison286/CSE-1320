// Author: Marshall Jamison
// Program: The Library's Memory Vault
// Purpose: Allows for people to input information about books held in a library.
// Reflection: The hardest part about this assignment was making sure that I was actually accessing the
// data that I meant to access, which means that I was making sure that my pointer symbols and notation was proper.

#include <stdio.h>
#include <stdlib.h>

struct Book 
{
    char title[100];
    char author[100];
    int yearPublished;
    int pages;
};

void printBook(struct Book);
void printBookP(struct Book*);
void printBooks(struct Book[], int);
struct Book initBook();
struct Book* createBook();
void updateBook(struct Book*);

int main()
{
    struct Book book1 = initBook();
    struct Book book2 = initBook();

    printf("-- Statically created books --\n");
    printBook(book1);
    printBook(book2);

    struct Book books[5];
    for(int i = 0; i < 5; i++)
    {
        books[i] = initBook();
    }

    printf("-- Array of 5 Books --\n");
    printBooks(books, 5);

    struct Book* bookp = createBook();

    printf("-- Dynamically allocated book --\n");
    printBookP(bookp);

    updateBook(bookp);

    printf("-- After updating pages --\n");
    printBookP(bookp);

    printf("Freeing dynamically allocated memory...");
    free(bookp);
    printf(" done.\n");

    return 0;
}

void printBook(struct Book book)
{
    printf("Title: %s   Author: %s   Year: %d   Pages: %d\n", book.title, book.author, book.yearPublished, book.pages);
}

void printBookP(struct Book* book)
{
    printf("Title: %s   Author: %s   Year: %d   Pages: %d\n", book->title, book->author, book->yearPublished, book->pages);
}

void printBooks(struct Book books[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printBook(books[i]);
    }
}

struct Book initBook()
{
    struct Book book;

    printf("What is the title of the book? ");
    fgets(book.title, sizeof(book.title), stdin);

    printf("Who is the author of the book? ");
    fgets(book.author, sizeof(book.author), stdin);

    printf("What year was the book published? ");
    scanf("%d", &(book.yearPublished));
    while(getchar() != '\n');

    printf("How many pages does the book have? ");
    scanf("%d", &(book.pages));
    while(getchar() != '\n');

    return book;
}

struct Book* createBook()
{
    struct Book* book = malloc(sizeof(struct Book));

    if(book == NULL)
    {
        printf("There was a problem when allocating the memory for a new book.\n");
        return NULL;
    }

    *book = initBook();

    return book;
}

void updateBook(struct Book* book)
{
    int choice;

    printf("Which element do you want to update?\n");
    printf("1 - Title\n");
    printf("2 - Author\n");
    printf("3 - Year Published\n");
    printf("4 - Number of pages\n");

    scanf("%d", &choice);
    while(getchar() != '\n');

    switch (choice)
    {
        case 1:
            printf("What is the new title of the book? ");
            fgets(book->title, sizeof(book->title), stdin);
            break;
        case 2:
            printf("What is the new author of the book? ");
            fgets(book->author, sizeof(book->author), stdin);
            break;
        case 3:
            printf("What is the new year of publication? ");
            scanf("%d", &(book->yearPublished));
            while(getchar() != '\n');
            break;
        case 4:
            printf("What is the new number of pages? ");
            scanf("%d", &(book->pages));
            while(getchar() != '\n');
            break;
        default:
            printf("Invalid choice. Updated nothing.\n");
            break;
    }
}