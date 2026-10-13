#include <stdio.h>

#define MAX_STUDENTS 10

struct Student
{
    char* name;
    int age;
    char* major;
    float gpa;
};

struct Student addStudent();
void displayStudents(struct Student[], int);
double calculateAverageGPA(struct Student[], int);

int main()
{
    struct Student baseArr[MAX_STUDENTS];

    int counter = 0;

    for(int i = 0; i < MAX_STUDENTS; i++)
    {
        baseArr[i] = addStudent();

        char ans;

        printf("Would you like to add another student? (Y/N)");
        scanf(" %c", &ans);

        ans = tolower(ans);

        if(ans == 'n')
        {
            break;
        }
        else
        {
            counter++;
        }
    }

    struct Student arr[counter];

    for(int i = 0; i < counter; i++)
    {
        arr[i] = baseArr[i];
    }

    

    return 0;
}

struct Student addStudent()
{
    struct Student student;

    printf("Enter the student's name: ");
    scanf("%s", &student.name);

    while(1)
    {
        printf("Enter the student's age: ");
        scanf("%d", &student.age);

        if(student.age > 0)
        {
            break;
        }
        else
        {
            printf("Please enter a proper age.\n");
        }
    }

    printf("Enter the student's major: ");
    scanf("%s", &student.major);

    printf("Enter the student's GPA (0.0 - 4.0): ");
    scanf("%f", &student.gpa);

    return student;
}

void displayStudents(struct Student students[], int len)
{
    printf("Student Records:\n");
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