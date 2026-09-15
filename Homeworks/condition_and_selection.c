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
    
    printf("Please enter the current date (MM/DD//YYYY): ");
    scanf("%d %c%d %c%d", &CurrMonth, &Discard ,&CurrDay, &Discard, &CurrYear);

    printf("Please enter your birth date (MM/DD//YYYY): ");
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



    return 0;
}