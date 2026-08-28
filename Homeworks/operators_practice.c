#include <stdio.h>

//Part 1
void quarterChange()
{
    int cents;

    printf("Enther amount of cents: ");
    scanf("%i", &cents);

    int numQuarters = cents / 25;
    cents %= 25;

    int numDimes = cents / 10;
    cents %= 10;

    int numNickels = cents / 5;
    cents %= 5;

    printf("Quarters: %i\n", numQuarters);
    printf("Dimes: %i\n", numDimes);
    printf("Nickels: %i\n", numNickels);
    printf("Pennies: %i\n", cents);
}

//Part 2
void roomRenovationCost()
{
    int roomLength;
    int roomWidth;
    double flooringCost;
    double paintCost;

    double subtotal = 0;

    printf("Enter room length (ft): ");
    scanf("%i", &roomLength);

    printf("Enter room width (ft): ");
    scanf("%i",  &roomWidth);

    printf("Enter flooring cost per square foot: ");
    scanf("%lf", &flooringCost);

    printf("Enter paint cost per square foot: ");
    scanf("%lf", &paintCost);

    double room = roomLength * roomWidth;

    printf("Room Area: %0.2lf\n", room);

    subtotal += room * flooringCost;

    printf("Flooring cost: $%0.2lf\n", room * flooringCost);

    subtotal += room * paintCost;

    printf("Paint cost: $%0.2lf\n", room * paintCost);

    printf("Subtotal: $%0.2lf\n", subtotal);

    printf("Total with 8.25%% tax: $%0.2lf\n", subtotal *= 1.0825);
}

//Part 3
void scholarshipChecker()
{
    float gpa;
    int creditHours;
    int serviceHours;

    printf("Enter GPA: ");
    scanf("%f", &gpa);

    printf("Enter completed credit hours: ");
    scanf("%i", &creditHours);

    printf("Enter community service hours: ");
    scanf("%i", &serviceHours);

    int eligible = (gpa >= 3.5 && creditHours >= 60) || (gpa >= 3.0 && serviceHours >= 100);

    printf("Eligible for scholarship: ");

    if(eligible)
    {
        printf("YES\n");
    }
    else 
    {
        printf("NO\n");
    }
}

//Part 4
void mysteryExpression()
{
    //Predicted value is 13.
    int result = 20 - 4 * 2 + 18 / 3 % 4 - 1;

    printf("result = %i\n\n", result);

    printf("Intermediate steps:\n");

    int step1 = 4 * 2;
    printf("step1 (4 * 2) = %i\n", step1);

    int step2 = 18 / 3;
    printf("step2 (18 / 3) = %i\n", step2);

    int step3 = 6 % 4;
    printf("step3 (6 %% 4) = %i\n", step3);

    int step4 = 20 - step1;
    printf("step4 (20 - step1) = %i\n", step4);

    int step5 = step4 + step3;
    printf("step5 (step4 + step3) = %i\n", step5);

    int step6 = step5 - 1;
    printf("step6 (step5 - 1) = %i\n", step6);
}

//Part 5
void countdownClicker()
{
    int clicks = 5;

    //used postfix so that it prints the initial value of clicks
    //rather than the incremented value. Prints 5. Value of clicks after
    //the line is 6.
    printf("%i\n", clicks++);

    //used prefix so that clicks increments and then prints. Prints 7. 
    //Value of clicks after the line is 7.
    printf("%i\n", ++clicks);

    //used postfix so that it prints the value of clicks before decrementing.
    //Prints 7. Value of clicks after the line is 6.
    printf("%i\n", clicks--);

    //used prefix so that it prints the further decremented value of clicks.
    //Prints 5. Value of clicks after the line is 5.
    printf("%i\n", --clicks);

    printf("Final value: %i\n", clicks);
}

int main()
{
    quarterChange();

    roomRenovationCost();

    scholarshipChecker();

    mysteryExpression();

    countdownClicker();

    return 0;
}