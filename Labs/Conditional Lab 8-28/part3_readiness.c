#include <stdio.h>

int main()
{
    int healthScore;

    printf("Enter the astronaut's health score: ");
    scanf("%i", &healthScore);

    if(healthScore >= 90)
    {
        printf("READINESS: ELITE - primary crew.");
    }
    else if(healthScore >= 75)
    {
        printf("READINESS: FLIGHT-READY - cleared for mission.");
    }
    else if(healthScore >= 60)
    {
        printf("READINESS: BACKUP - reserve crew only.");
    }
    else if(healthScore >= 40)
    {
        printf("READINESS: GROUNDED - needs medical review.");
    }
    else
    {
        printf("READINESS: DISQUALIFIED.");
    }

    return 0;
}