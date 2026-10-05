#include <stdio.h>

float* sort(float*, int);
void printArr(float*, int);

int main()
{
    float a[8] = {4.35, 4.532, 4.1234, 3.0449, 2.34543, 1.345, 9.34, 6.765};

    int count = sizeof(a) / sizeof(a[0]);   
    
    printArr(a, count);

    float* b = sort(a, count);

    printArr(b, count);
}

int findHighest(float arr[], int len)
{
    float highest = arr[0];
    int highestIndex = 0;

    for(int i = 0; i < len; i++)
    {
        if(arr[i] > highest)
        {
            highest = arr[i];
            highestIndex = i;
        }
    }

    return highestIndex;
}

float* sort(float arr[], int len)
{
    float* sorted;

    sorted[0] = arr[findHighest(arr, len)];

    float arrToSearch[len];

    for(int i = 1; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(arr[j] == sorted[i - 1])
            {
                arrToSearch[j] = -1000.0f;
            }
            else 
            {
                arrToSearch[j] = arr[j];
            }
        }

        sorted[i] = findHighest(arrToSearch, len);
    }

    return sorted;
}

void printArr(float* arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}