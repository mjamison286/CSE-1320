/*
 * Author:     Marshall Jamison
 * Program:    Classroom Command Center
 * Purpose:    This program collects and displays some data of students.
 * Reflection: The trickiest part of this program was figuring out how to the double array
 *             as my first thought would have been to use char*[] rather than char[][].
 */

#include <stdio.h>

int count;

void displayStudents(char names[][20], int rollNumbers[], float marks[]);
float calculateAverage(float[]);
float findHighest(float[]);
float findLowest(float[]);

int main()
{
    printf("Enter the amount of students: ");
    scanf("%i", &count);

    char names[count][20];
    int rollNumbers[count];
    float marks[count];

    for(int i = 0; i < count; i++)
    {
        printf("Enter details for student %i:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", &names[i]);
        printf("Enter roll number: ");
        scanf("%i", &rollNumbers[i]);
        printf("Enter marks (out of 100): ");
        scanf("%f", &marks[i]);
    }

    displayStudents(names, rollNumbers, marks);

    printf("Average marks: %f\n", calculateAverage(marks));
    printf("Highest marks: %f\n", findHighest(marks));
    printf("Lowest marks: %f\n", findLowest(marks));

    return 0;
}

void displayStudents(char names[][20], int rollNumbers[], float marks[])
{
    printf("Student Details: \n");
    for(int i = 0; i < count; i++)
    {
        printf("Student %i - Name: %s   Roll Number: %i   Marks: %f\n", i + 1, names[i], rollNumbers[i], marks[i]);
    }
}

float calculateAverage(float marks[])
{
    float sum = 0;

    for(int i = 0; i < count; i++)
    {
        sum += marks[i];
    }

    return sum / count;
}

float findHighest(float marks[])
{
    float highest = marks[0];

    for(int i = 1; i < count; i++)
    {
        if(marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

float findLowest(float marks[])
{
    float lowest = marks[0];

    for(int i = 1; i < count; i++)
    {
        if(marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}