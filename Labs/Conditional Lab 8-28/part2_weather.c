#include <stdio.h>

int main()
{
    int windSpeed;

    printf("Enter the wind speed: ");
    scanf("%i", &windSpeed);

    if(windSpeed < 40)
    {
        printf("WEATHER: GO - conditions are safe.");
    }
    else
    {
        printf("WEATHER: NO-GO - wind speed too high.");
    }

    return 0;
}