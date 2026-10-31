#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int bookID;
    char title[50];
    char author[50];
    int year;
    struct Book* next;
};

struct Book* addBook(struct Book*);
struct Book* removeBook(struct Book*);
void searchByID(struct Book*);
void searchByTitle(struct Book*);
void displayBooks(struct Book*);

int main()
{
    int choice;
    struct Book* head = NULL;

    printf("Library Management System\n");
    printf("1. Add a book\n");
    printf("2. Remove a book\n");
    printf("3. Search by BookID\n");
    printf("4. Search by Title\n");
    printf("5. Display all books\n");
    printf("6. Exit\n\n");

    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice)
        {
            case 1:
                if(head == NULL)
                {
                    head = addBook(NULL);
                }
                else
                {
                    addBook(head);
                }
                break;
            case 2:
                head = removeBook(head);
                break;
            case 3:
                searchByID(head);
                break;
            case 4:
                searchByTitle(head);
                break;
            case 5:
                displayBooks(head);
                break;
            case 6:
                printf("Exiting...\n");

                struct Book* nextPointer = head;
                struct Book* currPointer;

                while(nextPointer != NULL)
                {
                    currPointer = nextPointer;
                    nextPointer = nextPointer->next;
                    free(currPointer);
                }

                return 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}

struct Book* addBook(struct Book* head)
{
    struct Book* book = malloc(sizeof(struct Book));

    if(book == NULL)
    {
        printf("Failed to allocate memory for the new book.");
        return NULL;
    }

    printf("Enter BookID: ");
    scanf("%d", &(book->bookID));
    while(getchar() != '\n');

    printf("Enter title: ");
    fgets(book->title, sizeof(book->title), stdin);
    book->title[strcspn(book->title, "\n")] = '\0';

    printf("Enter author: ");
    fgets(book->author, sizeof(book->author), stdin);
    book->author[strcspn(book->author, "\n")] = '\0';

    printf("Enter year: ");
    scanf("%d", &(book->year));
    while(getchar() != '\n');

    book->next = NULL;

    if(head != NULL)
    {
        struct Book* nextPointer = head;
        struct Book* currPointer = head;

        while(nextPointer != NULL)
        {
            currPointer = nextPointer;
            nextPointer = nextPointer->next;
        }

        currPointer->next = book;
    }

    return book;
}

struct Book* removeBook(struct Book* head)
{
    struct Book* nextPointer = head;
    struct Book* previousPointer;
    struct Book* temp;

    int id;

    printf("Enter the id of the book you want to remove: ");
    scanf("%d", &id);
    while(getchar() != '\n');

    if(head->bookID == id)
    {
        struct Book* temp = head->next;
        free(head);
        return temp;
    }

    while(nextPointer->next != NULL)
    {
        if(nextPointer->next->bookID == id)
        {
            temp = nextPointer->next;
            nextPointer->next = nextPointer->next->next;
            free(temp);

            return head;
        }

        previousPointer = nextPointer;
        nextPointer = nextPointer->next;
    }

    if(nextPointer->bookID == id)
    {
        previousPointer->next = NULL;
        free(nextPointer);
        return head;
    }
    
    printf("Did not find a book to remove with the matching BookID.\n");
    return head;
}

void searchByID(struct Book* head)
{
    struct Book* nextPointer = head;

    int id;

    printf("Enter the id of the book you want to search: ");
    scanf("%d", &id);
    while(getchar() != '\n');

    while(nextPointer != NULL)
    {
        if(nextPointer->bookID == id)
        {
            printf("BookID: %d   Title: %s   Author: %s   Year: %d\n", nextPointer->bookID, nextPointer->title, nextPointer->author, nextPointer->year);
            return;
        }

        nextPointer = nextPointer->next;
    }

    printf("Book not found by ID.\n");
}

void searchByTitle(struct Book* head)
{
    struct Book* nextPointer = head;

    char title[50];

    printf("Enter the title of the book you want to search: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    while(nextPointer != NULL)
    {
        if(strcmp(nextPointer->title, title) == 0)
        {
            printf("BookID: %d   Title: %s   Author: %s   Year: %d\n", nextPointer->bookID, nextPointer->title, nextPointer->author, nextPointer->year);
            return;
        }

        nextPointer = nextPointer->next;
    }

    printf("Book not found by title.\n");
}

void displayBooks(struct Book* head)
{
    struct Book* nextPointer = head;

    while(nextPointer != NULL)
    {
        printf("BookID: %d   Title: %s   Author: %s   Year: %d\n", nextPointer->bookID, nextPointer->title, nextPointer->author, nextPointer->year);
        nextPointer = nextPointer->next;
    }
}