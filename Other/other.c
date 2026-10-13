#include <stdio.h>
#include <ctype.h>

double basePrice(int);

int main()
{
    int age;
    int showtime;
    char glasses;

    while(1)
    {
        printf("Enter age: ");
        scanf("%d", &age);
        if(age > 0 && age <= 120)
        {
            break;
        }
        else
        {
            printf("Invalid age.\n");
        }
    }

    while(1)
    {
        printf("Showtime (1 = Matinee, 2 = Evening, 3 = Late): ");
        scanf("%d", &showtime);
        if(showtime >= 1 && showtime <= 3)
        {
            break;
        }
        else
        {
            printf("Invalid showtime.\n");
        }
    }

    while(1)
    {
        printf("3D glasses (Y/N): ");
        scanf(" %c", &glasses);
        glasses = tolower(glasses);
        if(glasses == 'y' || glasses == 'n')
        {
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    double totalPrice = basePrice(age);
    printf("Base price: $%0.2lf\n", totalPrice);

    switch(showtime)
    {
        case (1):
            totalPrice += -2.0;
            printf("Showtime adjustment: %+0.2f\n", -2.0);
            break;
        case (2):
            printf("Showtime adjustment: %+0.2f\n", 0.0);
            break;
        case (3):
            totalPrice += 1.5;
            printf("Showtime adjustment: %+0.2f\n", 1.5);
            break;
        default:
            printf("Invalid showtime after check.\n");
            return 1;
    }

    if(glasses == 'y')
    {
        printf("3D glasses: $3.00\n");
        totalPrice += 3.0;
    }
    else
    {
        printf("3D glasses: $0.00\n");
    }
    printf("Ticket total: $%0.2lf\n", totalPrice);
    return 0;
}

double basePrice(int age)
{
    if(age <= 12)
    {
        return 6;
    }
    else if (age > 12 && age < 65) 
    {
        return 11;
    }
    else if (age >= 65) 
    {
        return 7.5;
    }
}