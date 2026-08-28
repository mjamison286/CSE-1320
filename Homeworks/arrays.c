#include <stdio.h>
#include <stdbool.h>

#define NUM_OF_ELEMENTS 10

//loops through the given array using a for loop, printing each item within the array in one line.
void printArray(int intArray[], int size)
{
    printf("The array contains: ");

    for(int i = 0; i < size; i++)
    {
        printf("%i ", intArray[i]);
    }

    printf("\n");
}

//calculates the sum of all elements in the array by looping through the array and adding it to a total variable named sum.
int calculateSum(int intArray[], int size)
{
    int sum = 0;
    
    for(int i = 0; i < size; i++)
    {
        sum += intArray[i];
    }

    return sum;
}

//calculates the average value of all elements in the array by taking the sum of all elements and dividing it by the length of the array.
float calculateAverage(int intArray[], int size)
{
    int sum = calculateSum(intArray, size);

    float average = (float) sum / size;

    return average;
}

//reverses the values of each element of the array. Further comments below.
void reverseValues(int intArray[], int size)
{
    printf("Reversing the values.\n");

    for(int i = 0; i < size; i++)
    {
        int num = intArray[i]; //selects the element from the array and saves it to a local variable.
        int newNum = 0; //creates a temporary variable used to create the reversed element.

        int maxPlaceValue = 1; //variable indicating which place value we are taking from the element.
        int currentPlaceValue = 1; //another variable indicating which place value we are taking from the element.

        bool isNegative = false; //variable denoting if the element is negative or not.

        //this loop finds the highest place value the element has.
        while(num % maxPlaceValue != num)
        {
            //every time the modulo operator returns a value
            //not equal to the element, this place value is incremented.
            maxPlaceValue *= 10;
        }

        //the place value after the previous loop is going to be one more than
        //the needed place value, so we decrement once.
        maxPlaceValue /= 10;

        //same style loop as before, except with the newer variable.
        while(num % currentPlaceValue != num)
        {
            //this line uses integer division to isolate the digit in the place value given by
            //max place value. Then it multiplies it by the current place value that we are trying 
            //to add to the result number, giving us the digit that we need in the correct place
            //value. Finally, we modulo by any digit above the place value that we need to get
            //rid of any leading numbers that are left by the previous operations.
            int res = (num / maxPlaceValue * currentPlaceValue) % (currentPlaceValue * 10);

            newNum += res; //add the resulting number to the total

            //decrements the maxPlaceValue, which is being used to select the numerical digit
            //that we need, and currentPlaceValue is incremented so that it can be multiplied to 
            //the resulting numerical digit to get the proper place value.
            maxPlaceValue /= 10;
            currentPlaceValue *= 10;
        }

        if(isNegative)
        {
            newNum *= -1; //flips the number negative if it was originally negative.
        }

        intArray[i] = newNum; //assigns the new reversed number to the same index as the original.
    }
}

int main()
{   
    int array[NUM_OF_ELEMENTS];

    printf("Enter %i integers: ", NUM_OF_ELEMENTS);

    //loops the amount of times that the array needs to be completely filled.
    //this loop allows for the user to enter not only one single line with 10 values,
    //but also 10 different lines with one value each.
    for(int i = 0; i < NUM_OF_ELEMENTS; i++)
    {
        scanf("%i", &array[i]);
    }

    printArray(array, NUM_OF_ELEMENTS);

    printf("The sum of the array elements is %i\n", calculateSum(array, NUM_OF_ELEMENTS));

    printf("The average of the array elements is %.2f\n", calculateAverage(array, NUM_OF_ELEMENTS));

    reverseValues(array, NUM_OF_ELEMENTS);

    printArray(array, NUM_OF_ELEMENTS);

    return 0;
}