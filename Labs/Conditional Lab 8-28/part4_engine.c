#include <stdio.h>

int main()
{
    char enginePass;
    int oxygenPercent;

    printf("Is the engine ready? Y or N: ");
    scanf("%c", &enginePass);

    if(enginePass == 'Y')
    {
        printf("Enter the oxygen percentage: ");
        scanf("%i", &oxygenPercent);

        if(oxygenPercent >= 95)
        {
            printf("LAUNCH SEQUENCE ARMED");
        }
        else
        {
            printf("ABORT: oxygen levels insufficient.");
        }
    }
    else
    {
        printf("ABORT: engine failure - oxygen not checked.");
    }   

    return 0;
}