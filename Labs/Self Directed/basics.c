// Author: Marshall Jamison
// Program: Payroll Printer
// Purpose: Takes in employee data to print out a neat chart showing all of the data.
// Reflection: The hardest part of this lab was trying to make the table itself look good.
// Everything else was pretty self explanatory.

#include <stdio.h>

//amount of employees whose data needs to be displayed
int employeeCount = 3;

int main()
{
    //constant string so that I would not have to type it over and over again
    const char tableString[] = "+----------------------+-----+------------+\n";

    //struct to hold all of the employee data neatly
    struct Employee
    {
        char name[20];
        int age;
        float salary;
    };

    //array which actually stores the data given through scanf
    struct Employee array[employeeCount];

    for(int i = 0; i < employeeCount; i++)
    {
        printf("Enter details for Employee %i:\n", i + 1);

        printf("Name: ");
        scanf("%s", &array[i].name);

        printf("Age: ");
        scanf("%i", &array[i].age);

        printf("Salary: ");
        scanf("%f", &array[i].salary);
    }

    printf("%s",tableString);
    printf("| Name                 | Age | Salary     |\n");
    printf("%s", tableString);

    for(int i = 0; i < employeeCount; i++)
    {
        printf("| %-20s | %-+3i | %-+10.2f |\n", array[i].name, array[i].age, array[i].salary);
    }

    printf("%s", tableString);

    return 0;
}