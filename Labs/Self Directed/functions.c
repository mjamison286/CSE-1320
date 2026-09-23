// Author: Marshall Jamison
// Program: Airport Currency Kiosk
// Purpose: This program converts your current currency into the currency of the place 
// you are travelling to.
// Reflection: Honestly this program did not really have any challenging portions to it.


#include <stdio.h>

//prototypes
double promptForDouble();

//small functions
double usdToEur(double);
double eurToUsd(double);
double eurToGbp(double);
double gbpToEur(double);
double gbpToUsd(double);
double usdToGbp(double);

int main()
{
    while(1)
    {
        int menuResult;

        printf("\nWelcome to the currency converter!\n\n");
        printf("1. USD to EUR\n");
        printf("2. EUR to USD\n");
        printf("3. USD to GBP\n");
        printf("4. GBP to USD\n");
        printf("5. EUR to GBP\n");
        printf("6. GBP to EUR\n\n");
        printf("Enter your choice: (0 to exit) ");
        
        scanf("%i", &menuResult);
        
        switch(menuResult)
        {
            case (1):
                usdToEur(promptForDouble());
                break;
            case (2):
                eurToUsd(promptForDouble());
                break;
            case (3):
                usdToGbp(promptForDouble());
                break;
            case (4):
                gbpToUsd(promptForDouble());
                break;
            case (5):
                eurToGbp(promptForDouble());
                break;
            case (6):
                gbpToEur(promptForDouble());
                break;
            case (0):
                printf("Exiting.");
                return 1;
                break;
            default:
                printf("Invalid menu choice.\n");
                break;

        }
    }

    return 0;
}

double promptForDouble()
{
    double amount;

    printf("Enter the amount of currency you wish to convert: ");
    scanf("%lf", &amount);

    return amount;
}

double usdToEur(double amount)
{
    double result = amount * 0.85;

    printf("%0.2lf USD is %0.2lf EUR.\n", amount, result);

    return result;
}

double eurToUsd(double amount)
{
    double result = amount * 1.18;

    printf("%0.2lf EUR is %0.2lf USD.\n", amount, result);

    return result;
}

double eurToGbp(double amount)
{
    double result = amount * 0.88;

    printf("%0.2lf EUR is %0.2lf GBP.\n", amount, result);

    return result;
}

double gbpToEur(double amount)
{
    double result = amount * 1.14;

    printf("%0.2lf GBP is %0.2lf EUR.\n", amount, result);

    return result;
}

double gbpToUsd(double amount)
{
    double result = amount * 1.33;

    printf("%0.2lf GBP is %0.2lf USD.\n", amount, result);

    return result;
}

double usdToGbp(double amount)
{
    double result = amount * 0.75;

    printf("%0.2lf USD is %0.2lf GBP.\n", amount, result);

    return result;
}
