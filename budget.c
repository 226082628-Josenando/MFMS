#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
    char department[50];
    int numberOfDepartments;
    float allocatedBudget;
    float expenditure;
    float remainingBudget;
    int valid;

    printf("How many departments do you want to enter? ");
    scanf("%d", &numberOfDepartments);

    for (int i = 0; i < numberOfDepartments; i++)
    {
        do
        {
            valid = 1;

        printf("\n--- DEPARTMENT %d ---\n", i + 1);

        printf("Enter department name: ");
        scanf(" %s", department);

         for (int j = 0; department[j] != '\0'; j++)
            {
                if (isdigit(department[j]))
                {
                    valid = 0;
                }
            }

            if (valid == 0)
            {
                printf("Invalid! Department name cannot contain numbers.\n");
            }

        } while (valid == 0);

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