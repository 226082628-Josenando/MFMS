#include <stdio.h>

int main()
{
    char department[50];
    int numberOfDepartments;
    float allocatedBudget;
    float expenditure;
    float remainingBudget;

    printf("How many departments do you want to enter? ");
    scanf("%d", &numberOfDepartments);

    for (int i = 0; i < numberOfDepartments; i++)
    {
        printf("\n--- DEPARTMENT %d ---\n", i + 1);

        printf("Enter department name: ");
        scanf(" %s", department);

        printf("Enter allocated budget: N$");
        scanf("%f", &allocatedBudget);

        
        while (allocatedBudget < 0)
        {
            printf("Invalid! Budget cannot be negative.\n");
            printf("Enter allocated budget again: N$");
            scanf("%f", &allocatedBudget);
        }

        printf("Enter expenditure: N$");
        scanf("%f", &expenditure);

        
        while (expenditure < 0)
        {
            printf("Invalid! Expenditure cannot be negative.\n");
            printf("Enter expenditure again: N$");
            scanf("%f", &expenditure);
        }

        remainingBudget = allocatedBudget - expenditure;

        printf("\n--- BUDGET INFORMATION ---\n");
        printf("Department: %s\n", department);
        printf("Allocated Budget: N$%.2f\n", allocatedBudget);
        printf("Expenditure: N$%.2f\n", expenditure);
        printf("Remaining Budget: N$%.2f\n", remainingBudget);

        if (expenditure <= allocatedBudget)
        {
            printf("Status: WITHIN BUDGET\n");
        }
        else
        {
            printf("Status: OVER BUDGET\n");
        }
    }

    return 0;
}