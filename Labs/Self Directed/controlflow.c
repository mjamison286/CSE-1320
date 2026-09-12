// Author: Marshall Jamison
// Program: Corner Store Simulator
// This program allows you to simulate a corner store through the command line.
// The trickiest part of this program to get right would be making sure that the 
// code was not repeated too many times.

#include <stdio.h>

double total = 0;

double quantityCalculation(float, char*);

void clearBuffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}

int main()
{
    float applePrice = 2.5f;
    float bananaPrice = 1.2f;
    float carrotPrice = 3.0f;
    float orangePrice = 2.0f;

    while(1)
    {
        int menuChoice;

        printf("Welcome to the CLI Shopping System!\n");

        printf("1. Apples - %0.2f each\n", applePrice);
        printf("2. Bananas - %0.2f each\n", bananaPrice);
        printf("3. Carrots - %0.2f each\n", carrotPrice);
        printf("4. Oranges - %0.2f each\n", orangePrice);

        printf("5. Exit\n\n");

        printf("Enter the number of the product that you want to buy: ");

        scanf("%i", &menuChoice);
        clearBuffer();

        switch (menuChoice) 
        {
            case (1):
                quantityCalculation(applePrice, "Apples");
                break;
            case (2):
                quantityCalculation(bananaPrice, "Bananas");
                break;
            case (3):
                quantityCalculation(carrotPrice, "Carrots");
                break;
            case (4):
                quantityCalculation(orangePrice, "Oranges");
                break;
            case (5):
                goto clean;
                break;
            
            default:
                printf("Invalid selection.\n");
                break;
        }

        if(menuChoice == 5)
        {
            clean: 
                if(total >= 100)
                {
                    total /= 10;
                    total *= 9;

                    printf("A 10%% discount has been applied!\n");
                    printf("Your final total is: $%0.2lf", total);
                }
                break;
        }
    }

    return 0;
}

double quantityCalculation(float price, char* product)
{
    int quantity;

    while(1)
    {
        printf("Enter the quantity: ");

        if(!scanf("%i", &quantity))
        {
            printf("Invalid quantity.\n");
            clearBuffer();
            continue;
        }

        clearBuffer();

        if(quantity < 0)
        {
            printf("Invalid quantity.\n");
            continue;
        }
        else
        {
            break;
        }
    }

    total += quantity * price;
    printf("Added %i %s to your cart. Total so far: $%0.2lf\n", quantity, product, total);
}