#include <stdio.h>

int main()
{
    int CurrMonth;
    int CurrDay;
    int CurrYear;
    int BirthMonth;
    int BirthDay;
    int BirthYear;
    int NumYears;
    char Discard;
    
    printf("Please enter the current date (MM/DD/YYYY): ");
    scanf("%d %c%d %c%d", &CurrMonth, &Discard ,&CurrDay, &Discard, &CurrYear);

    printf("Please enter your birth date (MM/DD/YYYY): ");
    scanf("%d %c%d %c%d", &BirthMonth, &Discard ,&BirthDay, &Discard, &BirthYear);

    if((CurrMonth > 12 || CurrMonth < 1) || (BirthMonth > 12 || BirthMonth < 1))
    {
        printf("One of the entered dates had an invalid month.");
        return 1;
    }

    if((CurrDay > 31 || CurrDay < 1) || (BirthDay > 31 || BirthDay < 1))
    {
        printf("One of the entered dates had an invalid day.");
        return 1;
    }

    if(CurrMonth > BirthMonth)
    {
        NumYears = CurrYear - BirthYear;
    } 
    else if(CurrMonth == BirthMonth)
    {
        if(CurrDay >= BirthDay)
        {
            NumYears = CurrYear - BirthYear;
        }
        else
        {
            NumYears = CurrYear - BirthYear - 1;
        }
    }
    else 
    {
        NumYears = CurrYear - BirthYear - 1;
    }

    printf("You are %d years old ", NumYears);

    switch (BirthMonth)
    {
        case 12:
        case 1:
        case 2:
            printf("and were born in Winter. Brrr.\n");
            break;
        case 3:
        case 4:
        case 5:
            printf("and were born in Spring.\n");
            break;
        case 6:
        case 7:
        case 8:
            printf("and were born in Summer.\n");
            break;
        case 9:
        case 10:
        case 11:
            printf("and were born in Fall.\n");
            break;
    }

    return 0;
}