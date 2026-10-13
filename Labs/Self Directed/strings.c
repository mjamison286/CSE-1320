// Author: Marshall Jamison
// Program: The Text Forensics Lab
// Purpose: This program takes in a string and allows the user to do different operations to it.
// Reflection: The trickiest part of this program to get right was definitely the thinking towards
// normalizing the space amounts.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 500

void letterCounter(const char[], int[], int);
void wordSearch(const char[]);
void titleCase(const char[]);
void substringExtraction(const char[]);
void normalizeSpaces(const char[]);

int main()
{
    char str[MAX];

    printf("Enter a text: ");
    fgets(str, MAX, stdin);

    str[strcspn(str, "\n")] = '\0';

    while(1)
    {
        printf("\nChoose an option for your string:\n");
        printf("1. Count characters\n");
        printf("2. Find word frequency\n");
        printf("3. Convert to title case\n");
        printf("4. Extract a substring\n");
        printf("5. Replace multiple spaces\n");
        printf("6. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                int counterArray[26];
                letterCounter(str, counterArray, 26);
                break;
            case 2:
                wordSearch(str);
                break;
            case 3: 
                titleCase(str);
                break;
            case 4:
                substringExtraction(str);
                break;
            case 5:
                normalizeSpaces(str);
                break;
            case 6:
                printf("Exiting.");
                return 0;
            default:
                printf("Please enter an actual menu option.\n");
                break;
        }
    }

    return 0;
}

void letterCounter(const char input[], int counter[], int len)
{
    for(int i = 0; i < len; i++)
    {
        counter[i] = 0;
    }

    int length = strlen(input) + 1;

    char string[length];

    for(int i = 0; i < length - 1; i++)
    {
        string[i] = tolower(input[i]);
    }

    string[length - 1] = '\0';

    for(int i = 0; i < length - 1; i++)
    {
        int counterIndex = string[i];

        counter[counterIndex - 97]++;
    }

    for(int i = 0; i < len; i++)
    {
        printf("Number of %c: %d\n", i + 97, counter[i]);
    }
}

void wordSearch(const char input[])
{
    char stringToSearch[20];
    int counter = 0;

    printf("Enter the word to search for: ");
    scanf("%s", &stringToSearch);

    int searchLength = strlen(stringToSearch);
    int inputLength = strlen(input);

    char string[inputLength + 1];

    for(int i = 0; i < searchLength; i++)
    {
        stringToSearch[i] = tolower(stringToSearch[i]);
    }

    for(int i = 0; i < inputLength + 1; i++)
    {
        string[i] = tolower(input[i]);
    }

    for(int i = 0; i < inputLength; i++)
    {
        if(string[i] == stringToSearch[0])
        {
            char possibleMatch[searchLength + 1];

            for(int j = 0; j < searchLength; j++)
            {
                possibleMatch[j] = string[i + j];
            }

            possibleMatch[searchLength] = '\0';

            int comparisonResult = strcmp(stringToSearch, possibleMatch);

            if(comparisonResult == 0)
            {
                counter++;
            }
        }
    }

    printf("The word '%s' appears %d times.", stringToSearch, counter);
}

void titleCase(const char input[])
{
    int inputLength = strlen(input) + 1;

    char string[inputLength];

    for(int i = 0; i < inputLength; i++)
    {
        string[i] = tolower(input[i]);
    }

    if(isalpha(string[0]))
    {
        string[0] = toupper(string[0]);
    }

    for(int i = 0; i < inputLength; i++)
    {
        if(string[i] == ' ')
        {
            string[i + 1] = toupper(string[i + 1]);
        }
    }

    printf("Title case: %s", string);
}

void substringExtraction(const char input[])
{
    int inputLength = strlen(input);

    int startIndex;
    printf("Enter the starting index: ");
    scanf("%d", &startIndex);

    int substringLength;
    printf("Enter the length of the substring: ");
    scanf("%d", &substringLength);

    char result[substringLength + 1];

    if(startIndex + substringLength <= inputLength - 1)
    {
        for(int i = 0; i < substringLength; i++)
        {
            result[i] = input[startIndex + i];
        }
    }
    else 
    {
        printf("Substring ending index out of range of the string.");
        return;
    }

    result[substringLength] = '\0';

    printf("Extracted substring: %s", result);
}

void normalizeSpaces(const char input[])
{
    int inputLength = strlen(input) + 1;

    char builtString[inputLength];

    int index = 0;

    for(int i = 0; i < inputLength; i++)
    {
        if(input[i] == ' ')
        {
            builtString[index] = input[i];

            for(int j = 0; j < inputLength - i; j++)
            {
                if(input[i + j] != ' ')
                {
                    i += j - 1;
                    break;
                }
            }
        }
        else
        {
            builtString[index] = input[i];
        }

        index++;
    }

    builtString[inputLength - 1] = '\0';

    printf("The rebuilt string is: %s\n", builtString);
}