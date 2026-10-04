/* ---------------- Reports module ---------------- */
void generateEmployeeReport(void) {
    float totalSalary = 0.0f;
    float averageSalary = 0.0f;
    float highestSalary = 0.0f;
    float lowestSalary = 0.0f;

    printf("\n========== EMPLOYEE REPORT ==========\n");

    if (EmployeeCount == 0) {
        printf("Total Employees: 0\n");
        printf("No employee data available.\n");
        printf("=====================================\n\n");
        return;
    }

    highestSalary = employees[0].Basic_salary;
    lowestSalary = employees[0].Basic_salary;

    for (int i = 0; i < EmployeeCount; i++) {
        totalSalary += employees[i].Basic_salary;
        if (employees[i].Basic_salary > highestSalary) {
            highestSalary = employees[i].Basic_salary;
        }
        if (employees[i].Basic_salary < lowestSalary) {
            lowestSalary = employees[i].Basic_salary;
        }
    }

    averageSalary = totalSalary / EmployeeCount;

    printf("Total Employees: %d\n", EmployeeCount);
    printf("Average Salary: N$%.2f\n", averageSalary);
    printf("Highest Salary: N$%.2f\n", highestSalary);
    printf("Lowest Salary: N$%.2f\n", lowestSalary);
    printf("Total Salary Expense: N$%.2f\n", totalSalary);

    printf("\n--- SALARY BREAKDOWN BY DEPARTMENT ---\n");
    char departments[50][50];
    int deptCount = 0;
    float deptSalaries[50] = {0};
    int deptEmployees[50] = {0};

    for (int i = 0; i < EmployeeCount; i++) {
        int found = 0;
        for (int j = 0; j < deptCount; j++) {
            if (strcmp(departments[j], employees[i].Department) == 0) {
                found = 1;
                deptSalaries[j] += employees[i].Basic_salary;
                deptEmployees[j]++;
                break;
            }
        }
        if (!found && deptCount < 50) {
            strcpy(departments[deptCount], employees[i].Department);
            deptSalaries[deptCount] = employees[i].Basic_salary;
            deptEmployees[deptCount] = 1;
            deptCount++;
        }
    }

    for (int i = 0; i < deptCount; i++) {
        printf("\nDepartment: %s\n", departments[i]);
        printf("  Employees: %d\n", deptEmployees[i]);
        printf("  Total Salary: N$%.2f\n", deptSalaries[i]);
        printf("  Average Salary: N$%.2f\n", deptSalaries[i] / deptEmployees[i]);
    }

    printf("\n=====================================\n\n");
}

void generateBudgetReport(void) {
    float totalAllocated = 0.0f;
    float totalExpenditure = 0.0f;
    float totalRemaining = 0.0f;
    int departmentsExceedingBudget = 0;

    printf("\n========== BUDGET REPORT ==========\n");

    if (departmentBudgetCount == 0) {
        printf("Total allocated budget: N$0.00\n");
        printf("Total expenditure: N$0.00\n");
        printf("Remaining budget: N$0.00\n");
        printf("Departments exceeding budget: 0\n");
        printf("No budget data available.\n");
        printf("====================================\n\n");
        return;
    }

    for (int i = 0; i < departmentBudgetCount; i++) {
        totalAllocated += departmentBudgets[i].allocatedBudget;
        totalExpenditure += departmentBudgets[i].expenditure;
        totalRemaining += departmentBudgets[i].remainingBudget;

        if (departmentBudgets[i].expenditure > departmentBudgets[i].allocatedBudget) {
            departmentsExceedingBudget++;
        }
    }

    printf("Total allocated budget: N$%.2f\n", totalAllocated);
    printf("Total expenditure: N$%.2f\n", totalExpenditure);
    printf("Remaining budget: N$%.2f\n", totalRemaining);
    printf("Departments exceeding budget: %d\n", departmentsExceedingBudget);

    printf("\n--- DETAILED BUDGET BY DEPARTMENT ---\n");
    for (int i = 0; i < departmentBudgetCount; i++) {
        printf("\nDepartment: %s\n", departmentBudgets[i].departmentName);
        printf("  Allocated: N$%.2f\n", departmentBudgets[i].allocatedBudget);
        printf("  Expenditure: N$%.2f\n", departmentBudgets[i].expenditure);
        printf("  Remaining: N$%.2f\n", departmentBudgets[i].remainingBudget);

        if (departmentBudgets[i].expenditure > departmentBudgets[i].allocatedBudget) {
            float overBudget = departmentBudgets[i].expenditure - departmentBudgets[i].allocatedBudget;
            printf("  Status: OVER BUDGET (N$%.2f)\n", overBudget);
        } else {
            printf("  Status: WITHIN BUDGET\n");
        }
    }

    if (departmentsExceedingBudget > 0) {
        printf("\n--- DEPARTMENTS EXCEEDING BUDGET ---\n");
        for (int i = 0; i < departmentBudgetCount; i++) {
            if (departmentBudgets[i].expenditure > departmentBudgets[i].allocatedBudget) {
                float overAmount = departmentBudgets[i].expenditure - departmentBudgets[i].allocatedBudget;
                printf("\n%s\n", departmentBudgets[i].departmentName);
                printf("  Allocated: N$%.2f\n", departmentBudgets[i].allocatedBudget);
                printf("  Expenditure: N$%.2f\n", departmentBudgets[i].expenditure);
                printf("  Over Budget By: N$%.2f\n", overAmount);
            }
        }
    }

    printf("\n====================================\n\n");
}

void generateSupplierReport(void) {
    printf("\n========== SUPPLIER REPORT ==========\n");

    if (count == 0) {
        printf("Total Suppliers: 0\n");
        printf("No suppliers registered in the system.\n");
        printf("=====================================\n\n");
        return;
    }

    printf("Total Suppliers: %d\n", count);

    printf("\n--- SUPPLIERS BY LOCATION ---\n");
    char towns_list[50][50];
    int townCount = 0;
    int townSuppliers[50] = {0};

    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < townCount; j++) {
            if (strcmp(towns_list[j], towns[i]) == 0) {
                found = 1;
                townSuppliers[j]++;
                break;
            }
        }
        if (!found && townCount < 50) {
            strcpy(towns_list[townCount], towns[i]);
            townSuppliers[townCount] = 1;
            townCount++;
        }
    }

    for (int i = 0; i < townCount; i++) {
        printf("%s: %d supplier(s)\n", towns_list[i], townSuppliers[i]);
    }

    printf("\n--- COMPLETE SUPPLIER LIST ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nSupplier #%d\n", i + 1);
        printf("  ID: %d\n", ids[i]);
        printf("  Name: %s\n", names[i]);
        printf("  Email: %s\n", emails[i]);
        printf("  Phone: %s\n", phones[i]);
        printf("  Location: %s\n", towns[i]);
    }

    printf("\n=====================================\n\n");
}

void generateAssetReport(void) {
    double totalAssetValue = 0.0;
    double highestValue = 0.0;
    double lowestValue = 0.0;

    printf("\n========== ASSET REPORT ==========\n");

    if (assetCount == 0) {
        printf("Total Assets: 0\n");
        printf("No municipal assets registered in the system.\n");
        printf("==================================\n\n");
        return;
    }

    highestValue = assets[0].purchaseValue;
    lowestValue = assets[0].purchaseValue;

    for (int i = 0; i < assetCount; i++) {
        totalAssetValue += assets[i].purchaseValue;

        if (assets[i].purchaseValue > highestValue) {
            highestValue = assets[i].purchaseValue;
        }
        if (assets[i].purchaseValue < lowestValue) {
            lowestValue = assets[i].purchaseValue;
        }
    }

    printf("Total Assets: %d\n", assetCount);
    printf("Total Asset Value: N$%.2f\n", totalAssetValue);
    printf("Highest Asset Value: N$%.2f\n", highestValue);
    printf("Lowest Asset Value: N$%.2f\n", lowestValue);
    printf("Average Asset Value: N$%.2f\n", totalAssetValue / assetCount);

    printf("\n--- ASSETS BY DEPARTMENT ---\n");
    char departments[50][50];
    int deptCount = 0;
    double deptValues[50] = {0};
    int deptAssets[50] = {0};

    for (int i = 0; i < assetCount; i++) {
        int found = 0;
        for (int j = 0; j < deptCount; j++) {
            if (strcmp(departments[j], assets[i].department) == 0) {
                found = 1;
                deptValues[j] += assets[i].purchaseValue;
                deptAssets[j]++;
                break;
            }
        }
        if (!found && deptCount < 50) {
            strcpy(departments[deptCount], assets[i].department);
            deptValues[deptCount] = assets[i].purchaseValue;
            deptAssets[deptCount] = 1;
            deptCount++;
        }
    }

    for (int i = 0; i < deptCount; i++) {
        printf("\nDepartment: %s\n", departments[i]);
        printf("  Number of Assets: %d\n", deptAssets[i]);
        printf("  Total Value: N$%.2f\n", deptValues[i]);
    }

    printf("\n--- ASSETS BY CONDITION ---\n");
    char conditions[50][50];
    int condCount = 0;
    int condAssets[50] = {0};

    for (int i = 0; i < assetCount; i++) {
        int found = 0;
        for (int j = 0; j < condCount; j++) {
            if (strcmp(conditions[j], assets[i].condition) == 0) {
                found = 1;
                condAssets[j]++;
                break;
            }
        }
        if (!found && condCount < 50) {
            strcpy(conditions[condCount], assets[i].condition);
            condAssets[condCount] = 1;
            condCount++;
        }
    }

    for (int i = 0; i < condCount; i++) {
        printf("%s: %d asset(s)\n", conditions[i], condAssets[i]);
    }

    printf("\n--- COMPLETE ASSET LIST ---\n");
    for (int i = 0; i < assetCount; i++) {
        printf("\nAsset #%d\n", i + 1);
        printf("  ID: %d\n", assets[i].assetID);
        printf("  Name: %s\n", assets[i].assetName);
        printf("  Type: %s\n", assets[i].assetType);
        printf("  Value: N$%.2f\n", assets[i].purchaseValue);
        printf("  Department: %s\n", assets[i].department);
        printf("  Condition: %s\n", assets[i].condition);
    }

    printf("\n==================================\n\n");
}

void generateComprehensiveReport(void) {
    printf("\n\n");
    printf("=====================================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM - FULL REPORT\n");
    printf("=====================================================\n");

    generateEmployeeReport();
    generateBudgetReport();
    generateSupplierReport();
    generateAssetReport();

    printf("\n");
    printf("=====================================================\n");
    printf("END OF COMPREHENSIVE REPORT\n");
    printf("=====================================================\n\n");
}

void reportsMenu(void) {
    int choice;
    int c;

    do {
        printf("\n========== REPORTS MENU ==========\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Comprehensive Report\n");
        printf("6. Back to Main Menu\n");
        printf("==================================\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            choice = 0;
        }
        /* clear the rest of the line once, whether or not the input was valid */
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1:
                generateEmployeeReport();
                break;
            case 2:
                generateBudgetReport();
                break;
            case 3:
                generateSupplierReport();
                break;
            case 4:
                generateAssetReport();
                break;
            case 5:
                generateComprehensiveReport();
                break;
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}