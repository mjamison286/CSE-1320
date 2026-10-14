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

struct Student addStudent();
void displayStudents(struct Student[], int);
double calculateAverageGPA(struct Student[], int);

int main()
{
    struct Student baseArr[MAX_STUDENTS];

    int counter = 0;

    while(counter < MAX_STUDENTS)
    {
        printf("Entering data for student %d.\n", counter + 1);
        baseArr[counter] = addStudent();

        counter++;

        if(counter != MAX_STUDENTS)
        {
            char ans;
            
            printf("Would you like to add another student? (Y/N): ");
            scanf(" %c", &ans);
            while(getchar() != '\n');

            ans = tolower(ans);

            if(ans == 'n')
            {
                break;
            }
        }  
    }

    struct Student arr[counter];

    for(int i = 0; i < counter; i++)
    {
        arr[i] = baseArr[i];
    }

    displayStudents(arr, counter);

    double average = calculateAverageGPA(arr, counter);

    printf("\nAverage GPA of all students: %0.2lf", average);

    return 0;
}

struct Student addStudent()
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