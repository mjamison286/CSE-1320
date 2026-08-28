#include <stdio.h>

int main()
{
    int windSpeed;
    int fuelPercent;
    int healthScore;
    char enginePass;
    int oxygenPercent;

    printf("Enter the wind speed: ");
    scanf("%i", &windSpeed);

    if(windSpeed >= 40)
    {
        printf("MISSION SCRUBBED: weather.\n");
        return 1;
    }
    else
    {
        printf("Enter the fuel percent: ");
        scanf("%i", &fuelPercent);

        if(fuelPercent < 90)
        {
            printf("MISSION SCRUBBED: fuel.\n");
            return 1;
        }
        // used a logical operator here because we are evaluating the same variable's value
        else if(fuelPercent >= 90 && fuelPercent <= 92) 
        {
            printf("CAUTION: fuel margin tight.\n");
        }
        printf("FUEL CHECK: PASS\n");
    }

    printf("Enter the health score: ");
    scanf("%i", &healthScore);

    if(healthScore < 40)    
    {
        printf("READINESS: DISQUALIFIED.\n");
        printf("MISSION SCRUBBED - crew readiness.\n");
        return 1;
    }
    else if(healthScore < 60)
    {
        printf("READINESS: GROUNDED - needs medical review.\n");
        printf("MISSION SCRUBBED - crew readiness.\n");
        return 1;
    }
    else if(healthScore < 75)
    {
        printf("READINESS: BACKUP - reserve crew only.\n");
        printf("MISSION SCRUBBED - crew readiness.\n");
        return 1;
    }
    else if(healthScore < 90)
    {
        printf("READINESS: FLIGHT-READY - cleared for mission.\n");
    }
    else 
    {
        printf("READINESS: ELITE - primary crew.\n");
    }
    
    printf("Is the engine ready? Y or N: ");
    scanf(" %c", &enginePass);

    if(enginePass == 'Y')
    {
        printf("Enter the oxygen percentage: ");
        scanf("%i", &oxygenPercent);

        if(oxygenPercent >= 95)
        {
            printf("LAUNCH SEQUENCE ARMED.\n");
        }
        else 
        {
            printf("ABORT: oxygen levels insufficient.\n");
        }
    }
    else
    {
        printf("ABORT: engine failure, oxygen not checked.\n");
    } 

    return 0;
}