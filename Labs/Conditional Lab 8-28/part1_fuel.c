#include <stdio.h>

int main()
{
    float fuelPercent;

    printf("Enter the percentage of fuel left in the system: ");
    scanf("%f", &fuelPercent);

    if(fuelPercent >= 90)
    {
        printf("FUEL CHECK: PASS - cleared for ignition.");
    }

    return 0;
}