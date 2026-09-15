#include <stdio.h>

double part1()
{
    const int ID_MAX = 999999;
    int id_number;
    float score;
    float average;

    double scoreTotal = 0;

    int studentCount = 0;

    while(1)
    {
        printf("Enter student's ID: ");
        scanf("%i", &id_number);

        if(id_number < 0)
        {
            printf("Invalid input for student id number.\n");
            continue;
        }

        if(id_number > ID_MAX)
        {
            break;
        }

        printf("Enter the student's score on the exam: ");
        scanf("%f", &score);

        if(score < 0)
        {   
            printf("Invalid input for score.\n");
            continue;
        }

        studentCount++;

        scoreTotal += score;
    }

    average = scoreTotal / studentCount;

    return average;
}

double part2(float square)
{
    float x = 0.0;
    float y = 100.0;
    float z;

    do
    {
        z = (x + y) / 2.0;
        if(z * z > square)
        {
            y = z;
        }
        else
        {
            x = z; 
        }
    }
    while (y - x >= 0.001);

    return y;
}

int part3(int days_in_month)
{
    const float FREEZING = 32.0;

    int day;
    int warm_days = 0;
    float temp;

    for(day = 0; day < days_in_month; day++)
    {
        printf("Enter the temperature (in fahrenheit): ");
        scanf("%f", &temp);

        if(temp > FREEZING)
        {
            warm_days++;
        }
    }

    return warm_days;
}

// Part 4:

/*
    while(gravity >= air_pressure)
    {
        gravity -= force;
        if(helium > mercury)
        {
            xxxxxxxx;
        }
        gravity *= deflection;
    }
*/

// When xxxxx is replaced with break, the while loop ends whenever the value of helium is greater
// than the value of mercury.

// When xxxxx is replaced with continue, the while loop skips over the rest of the while loop
// but still stays within the loop itself.

void part5()
{
    int counter = 0;
    int n;
    int value = 1;
    int sum = 1;

    printf("Enter a number: ");
    scanf("%i", &n);
    
    printf("Value    Sum\n");
    while(counter < n)
    {
        printf("%-9i%-12i\n", value, sum);
        value *= 2;
        sum += value;
        counter++;
    }
}

int main()
{
    //where each parts function goes for building and testing
    part5();

    return 0;
}