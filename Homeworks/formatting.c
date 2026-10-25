/*
* Your Name
* CSE 1320 – Section ????
* Fall 2026
* Homework: Formatting
*/

#include <stdio.h>

int main()
{
    int cschair, sbechair;
    int csdesk, sbedesk;
    int i = 0;
    float chcost, decost;
    float cscost, sbecost;

    /* Input from user */
    printf("\nORDER FORM FOR OFFICE FURNITURE FOR UTA LABS\n");
    printf("\nEach chair costs $25 and each desk costs $40\n\n");

    printf("Enter the number of chairs and desks required for CS lab: ");
    scanf("%d %d", &cschair, &csdesk);

    printf("Enter the number of chairs and desks required for SBE lab: ");
    scanf("%d %d", &sbechair, &sbedesk);

    chcost = 25.0 * (cschair + sbechair);
    decost = 40.0 * (csdesk + sbedesk);
    cscost = 25.0 * cschair + 40.0 * csdesk;
    sbecost = 25.0 * sbechair + 40.0 * sbedesk;

    /* Printing out the table */
    printf("\n\nLab Chairs Chair cost Desks Desk cost Total for lab\n");
    printf("----- ------ ---------- ----- --------- -------------\n");

    /* CHECK */
    printf("CS %d $%9.2f %5d $%8.2f $%12.2f\n", cschair, 25.0*cschair,
    csdesk, 40.0*csdesk, cscost);

    /* CHECK */
    printf("SBE %6d $%9.2f %5d $%8.2f $%f\n", sbechair, 25.0*sbechair, sbedesk,
    40.0*sbedesk, sbecost);

    for (i = 0; i < 58; i++) printf("-");

    printf("\n");
    
    printf("Total %6d $%9.2f %5d $%8.2f $%12.2f\n", cschair+sbechair, chcost,
    csdesk+sbedesk, decost, chcost+decost);
    for (i = 0; i < 58; i++) printf("-");
    printf("\n");
}