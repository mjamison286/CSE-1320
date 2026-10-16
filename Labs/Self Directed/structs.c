// Author: Marshall Jamison
// Program: Registrar's Office, Struct Edition
// Purpose: This program takes in data for students and allows to view many student's data all at once.
// Reflection: I would say that the trickiest part to get right would be all of the input validation.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STUDENTS 10

struct Student
{
    char name[20];
    int age;
    char major[50];
    float gpa;
};

struct Student readStudent();
void displayStudents(struct Student[], int);
double calculateAverageGPA(struct Student[], int);

int main()
{
    struct Student students[MAX_STUDENTS];

    int studentCount = 0;

    while(studentCount < MAX_STUDENTS)
    {
        printf("Entering data for student %d.\n", studentCount + 1);
        students[studentCount] = readStudent();

        studentCount++;

        if(studentCount != MAX_STUDENTS)
        {
            char answer;
            
            printf("Would you like to add another student? (Y/N): ");
            scanf(" %c", &answer);
            while(getchar() != '\n');

            answer = tolower(answer);

            if(answer == 'n')
            {
                break;
            }
        }  
    }

    displayStudents(students, studentCount);

    double average = calculateAverageGPA(students, studentCount);

    printf("\nAverage GPA of all students: %0.2lf", average);

    return 0;
}

struct Student readStudent()
{
    struct Student student;

    printf("Enter the student's name: ");
    fgets(student.name, sizeof(student.name), stdin);
    student.name[strcspn(student.name, "\n")] = '\0';

    while(1)
    {
        printf("Enter the student's age: ");
        scanf("%d", &student.age);
        while(getchar() != '\n');

        if(student.age <= 0)
        {
            printf("Please enter a valid age.\n");
        }
        else
        {
            break;
        }
    }

    printf("Enter the student's major: ");
    fgets(student.major, sizeof(student.major), stdin);
    student.major[strcspn(student.major, "\n")] = '\0';

    while(1)
    {
        printf("Enter the student's GPA (0.0 - 4.0): ");
        scanf("%f", &student.gpa);  
        while(getchar() != '\n');

        if(student.gpa < 0 || student.gpa > 4)
        {
            printf("Please enter a valid GPA.\n");
        }
        else
        {
            break;
        }
    }

    return student;
}

void displayStudents(struct Student students[], int len)
{
    printf("\nStudent Records:\n");
    for(int i = 0; i < len; i++)
    {
        printf("Student %d: Name: %s   Age: %d   Major: %s   GPA: %0.2f\n", i + 1, students[i].name, students[i].age, students[i].major, students[i].gpa);
    }
}

double calculateAverageGPA(struct Student students[], int len)
{
    double sum = 0;

    for(int i = 0; i < len; i++)
    {
        sum += students[i].gpa;
    }

    return sum / len;
}