/*
 * Author:     Marshall Jamison
 * Program:    Box Office Analytics
 * Purpose:    This program analyzes the box office performance of movies with the data 
                stored in arrays
 * Reflection: The trickiest part to get right in my opinion was figuring out how to pass
                arrays properly through functions.
 */



#include <stdio.h>

void calculateRevenue(int[], float[], int, float[]);
float calculateTotal(int[], float[], int);
float calculateAverage(int[], float[], int);
int findHighest(float[], int);
int findLowest(float[], int);
int findPopular(int[], int);

int main()
{
    int ticketsSold[5] = {400, 400, 400, 400, 400};
    float ticketPrices[5] = {10.00, 10.00, 10.00, 10.00, 10.00};

    int count = sizeof(ticketsSold) / sizeof(int);

    float revenues[count];
    
    calculateRevenue(ticketsSold, ticketPrices, count, revenues);

    for(int i = 0; i < count; i++)
    {
        printf("Movie %d: Total Revenue = $%0.2f\n", i + 1, revenues[i]);
    }

    printf("\nTotal Revenue for All Movies: $%0.2f\n", calculateTotal(ticketsSold, ticketPrices, count));
    printf("Average Revenue per Movie: $%0.2f\n", calculateAverage(ticketsSold, ticketPrices, count));

    int highestIndex = findHighest(revenues, count);
    printf("\nMovie with Highest Revenue: Movie %d   Revenue: $%0.2f\n", highestIndex + 1, revenues[highestIndex]);

    int lowestIndex = findLowest(revenues, count);
    printf("Movie with Lowest Revenue: Movie %d   Revenue: $%0.2f\n", lowestIndex + 1, revenues[lowestIndex]);

    int ticketsIndex = findPopular(ticketsSold, count);
    printf("Movie with the Most Tickets Sold: Movie %d   Tickets Sold: %d\n", ticketsIndex + 1, ticketsSold[ticketsIndex]);

    return 0;
}

void calculateRevenue(int amount[], float price[], int len, float arr[])
{
    for(int i = 0; i < len; i++)
    {
        float totalRevenue = amount[i] * price[i];

        arr[i] = totalRevenue;
    }
}

float calculateTotal(int amount[], float price[], int len)
{
    float sum = 0;

    for(int i = 0; i < len; i++)
    {
        float totalRevenue = amount[i] * price[i];

        sum += totalRevenue;
    }

    return sum;
}

float calculateAverage(int amount[], float price[], int len)
{
    float sum = calculateTotal(amount, price, len);

    return sum / len;
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

int findLowest(float arr[], int len)
{
    float lowest = arr[0];
    int lowestIndex = 0;

    for(int i = 0; i < len; i++)
    {
        if(arr[i] < lowest)
        {
            lowest = arr[i];
            lowestIndex = i;
        }
    }

    return lowestIndex;
}

int findPopular(int arr[], int len)
{
    int highest = arr[0];
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