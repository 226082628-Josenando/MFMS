#include <stdio.h>
#include <string.h>

/* ---------------- Supplier module data ---------------- */
#define MAX_SUPPLIERS 100

int ids[MAX_SUPPLIERS];
char names[MAX_SUPPLIERS][50];
char emails[MAX_SUPPLIERS][50];
char phones[MAX_SUPPLIERS][20];
char towns[MAX_SUPPLIERS][30];
int count = 0;

/* ---------------- Employee module data ---------------- */
#define Max_Employees 100

struct Employee {
    int   Employee_id;
    char  Name[50];
    char  Department[50];
    float Basic_salary;
    float Housing_allowance;
    float Transport_allowance;
    int   years_of_service;
};

struct Employee employees[Max_Employees];
int EmployeeCount = 0;

/* ---------------- Asset module data ---------------- */
struct Asset {
    int    assetID;
    char   assetName[50];
    char   assetType[40];
    double purchaseValue;
    char   department[40];
    char   condition[45];
};

struct Asset assets[100];
int assetCount = 0;

/* ---------------- Prototypes ---------------- */
void addAsset(void);
void displayAsset(void);
void searchAsset(void);
void assetMenu(void);
void budgetManagement(void);
int findSupplier(int id);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void compareSuppliers(void);
void displaySupplierReport(void);
void supplierMenu(void);
void showEmployeeMenu(void);
void AddEmployees(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);
void display_Relevant_Informantion(void);
void employeeMenu(void);

/* ---------------- Main menu ---------------- */
int main(void) {
    int choice;
    int c;

    do {
        printf("\n========================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");

        printf("1. Supplier Management\n");
        printf("2. Employee Management\n");
        printf("3. Budget Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            choice = 0;
        }
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1:
                supplierMenu();   /* calls the supplier module */
                break;
            case 2:
                employeeMenu();   /* calls the employee module */
                break;
            case 3:
                budgetManagement();   /* calls the budget module */
                break;
            case 4:
                assetMenu();   /* calls the asset module */
                break;
            case 5:
                printf("Reports selected.\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

/* ---------------- Budget module ---------------- */
void budgetManagement(void) {
    char department[50];
    int numberOfDepartments;
    float allocatedBudget;
    float expenditure;
    float remainingBudget;
    int c;

    printf("How many departments do you want to enter? ");
    if (scanf("%d", &numberOfDepartments) != 1 || numberOfDepartments < 0) {
        printf("Invalid number of departments.\n");
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    for (int i = 0; i < numberOfDepartments; i++) {
        printf("\n--- DEPARTMENT %d ---\n", i + 1);

        printf("Enter department name: ");
        scanf(" %49s", department);

        printf("Enter allocated budget: N$");
        scanf("%f", &allocatedBudget);

        while (allocatedBudget < 0) {
            printf("Invalid! Budget cannot be negative.\n");
            printf("Enter allocated budget again: N$");
            scanf("%f", &allocatedBudget);
        }

        printf("Enter expenditure: N$");
        scanf("%f", &expenditure);

        while (expenditure < 0) {
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

        if (expenditure <= allocatedBudget) {
            printf("Status: WITHIN BUDGET\n");
        } else {
            printf("Status: OVER BUDGET\n");
        }
    }

    while ((c = getchar()) != '\n' && c != EOF);
}

/* ---------------- Asset module ---------------- */
void addAsset(void) {
    int c;

    if (assetCount >= 100) {
        printf("Registo cheio.\n");
        return;
    }

    printf("Enter Asset ID: ");
    scanf("%d", &assets[assetCount].assetID);

    while (assets[assetCount].assetID <= 0) {
        printf("Negative values are not allowed!\n");
        printf("Enter Asset ID: ");
        scanf("%d", &assets[assetCount].assetID);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter Asset Name: ");
    fgets(assets[assetCount].assetName, 50, stdin);
    assets[assetCount].assetName[strcspn(assets[assetCount].assetName, "\n")] = '\0';

    printf("Enter Asset Type: ");
    fgets(assets[assetCount].assetType, 40, stdin);
    assets[assetCount].assetType[strcspn(assets[assetCount].assetType, "\n")] = '\0';

    printf("Enter Asset Purchase Value: ");
    scanf("%lf", &assets[assetCount].purchaseValue);

    while (assets[assetCount].purchaseValue < 0) {
        printf("Negative values are not allowed!\n");
        printf("Enter Asset Purchase Value: ");
        scanf("%lf", &assets[assetCount].purchaseValue);
    }
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter Asset Department: ");
    fgets(assets[assetCount].department, 40, stdin);
    assets[assetCount].department[strcspn(assets[assetCount].department, "\n")] = '\0';

    printf("Enter Asset Condition: ");
    fgets(assets[assetCount].condition, 45, stdin);
    assets[assetCount].condition[strcspn(assets[assetCount].condition, "\n")] = '\0';

    printf("Asset added!\n");
    assetCount++;
}

void displayAsset(void) {
    if (assetCount == 0) {
        printf("No assets.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        printf("Asset ID: %d\n", assets[i].assetID);
        printf("Asset Name: %s\n", assets[i].assetName);
        printf("Asset Type: %s\n", assets[i].assetType);
        printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n\n", assets[i].condition);
    }
}

void searchAsset(void) {
    int c;
    int option;
    int found = 0;
    int id = 0;
    char termo[50] = "";

    if (assetCount == 0) {
        printf("No assets available.\n");
        return;
    }

    printf("\n1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Type\n");
    printf("4. Search by Department\n");
    printf("Choose your option: ");
    scanf("%d", &option);

    while ((c = getchar()) != '\n' && c != EOF);

    if (option == 1) {
        printf("Enter ID: ");
        scanf("%d", &id);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    else if (option == 2) {
        printf("Enter Name: ");
        fgets(termo, sizeof(termo), stdin);
        termo[strcspn(termo, "\n")] = '\0';
    }
    else if (option == 3) {
        printf("Enter Type: ");
        fgets(termo, sizeof(termo), stdin);
        termo[strcspn(termo, "\n")] = '\0';
    }
    else if (option == 4) {
        printf("Enter Department: ");
        fgets(termo, sizeof(termo), stdin);
        termo[strcspn(termo, "\n")] = '\0';
    }
    else {
        printf("Invalid option.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        if ((option == 1 && assets[i].assetID == id) ||
            (option == 2 && strcmp(assets[i].assetName, termo) == 0) ||
            (option == 3 && strcmp(assets[i].assetType, termo) == 0) ||
            (option == 4 && strcmp(assets[i].department, termo) == 0)) {

            printf("\n--- Asset Found ---\n");
            printf("Asset ID: %d\n", assets[i].assetID);
            printf("Asset Name: %s\n", assets[i].assetName);
            printf("Asset Type: %s\n", assets[i].assetType);
            printf("Purchase Value: %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
        }
    }

    if (found == 0) {
        printf("\nAsset not found!\n");
    }
}

void assetMenu(void) {
    int choice;
    int c;

    do {
        printf("\n-----------------------Asset Management Menu----------------------\n");
        printf("1.Add Asset\n");
        printf("2.Display Asset\n");
        printf("3.Search Asset\n");
        printf("4.Back to main Menu\n");

        printf("Choose your option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Entrada invalida.\n");
            choice = 0;
        }
        while ((c = getchar()) != '\n' && c != EOF);

        switch (choice) {
            case 1:
                addAsset();
                break;
            case 2:
                displayAsset();
                break;
            case 3:
                searchAsset();
                break;
            case 4:
                printf("Back to main menu!\n");
                break;
            default:
                printf("Error...!\n");
                break;
        }
    } while (choice != 4);
}

/* ---------------- Supplier module ---------------- */

/* returns position of supplier in the array, -1 if not found */
int findSupplier(int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}

void addSupplier(void) {
    int id;
    int i;
    int hasAt;
    char name[50];
    char email[50];
    char phone[20];
    char town[30];

    if (count >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    printf("Enter supplier ID: ");
    scanf("%d", &id);
    while (id <= 0 || findSupplier(id) != -1) {
        if (id <= 0) {
            printf("ID must be positive. Enter again: ");
        } else {
            printf("ID already used. Enter again: ");
        }
        scanf("%d", &id);
    }

    printf("Enter supplier name (use _ instead of spaces): ");
    scanf("%49s", name);

    printf("Enter email: ");
    scanf("%49s", email);
    hasAt = 0;
    for (i = 0; i < (int)strlen(email); i++) {
        if (email[i] == '@') {
            hasAt = 1;
        }
    }
    while (hasAt == 0) {
        printf("Email must have @. Enter again: ");
        scanf("%49s", email);
        for (i = 0; i < (int)strlen(email); i++) {
            if (email[i] == '@') {
                hasAt = 1;
            }
        }
    }

    printf("Enter telephone number: ");
    scanf("%19s", phone);
    while (strlen(phone) < 7) {
        printf("Number too short. Enter again: ");
        scanf("%19s", phone);
    }

    printf("Enter town: ");
    scanf("%29s", town);

    ids[count] = id;
    strcpy(names[count], name);
    strcpy(emails[count], email);
    strcpy(phones[count], phone);
    strcpy(towns[count], town);
    count++;

    printf("Supplier added.\n");
}

void displaySuppliers(void) {
    int i;

    printf("\n--- SUPPLIERS ---\n");

    if (count == 0) {
        printf("No suppliers added yet.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nID: %d\n", ids[i]);
        printf("Name: %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town: %s\n", towns[i]);
    }
}

void searchSupplier(void) {
    int choice;
    int id;
    int i;
    int found = 0;
    char word[50];

    if (count == 0) {
        printf("No suppliers added yet.\n");
        return;
    }

    printf("\n--- SEARCH SUPPLIER ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by name\n");
    printf("3. Search by town\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter ID: ");
            scanf("%d", &id);
            i = findSupplier(id);
            if (i == -1) {
                printf("Supplier not found.\n");
            } else {
                printf("\nID: %d\n", ids[i]);
                printf("Name: %s\n", names[i]);
                printf("Email: %s\n", emails[i]);
                printf("Phone: %s\n", phones[i]);
                printf("Town: %s\n", towns[i]);
            }
            break;

        case 2:
            printf("Enter name: ");
            scanf("%49s", word);
            for (i = 0; i < count; i++) {
                if (strcmp(names[i], word) == 0) {
                    printf("\nID: %d\n", ids[i]);
                    printf("Name: %s\n", names[i]);
                    printf("Email: %s\n", emails[i]);
                    printf("Phone: %s\n", phones[i]);
                    printf("Town: %s\n", towns[i]);
                    found = 1;
                }
            }
            if (found == 0) {
                printf("Supplier not found.\n");
            }
            break;

        case 3:
            printf("Enter town: ");
            scanf("%49s", word);
            for (i = 0; i < count; i++) {
                if (strcmp(towns[i], word) == 0) {
                    printf("\nID: %d\n", ids[i]);
                    printf("Name: %s\n", names[i]);
                    printf("Email: %s\n", emails[i]);
                    printf("Phone: %s\n", phones[i]);
                    printf("Town: %s\n", towns[i]);
                    found = 1;
                }
            }
            if (found == 0) {
                printf("No suppliers in that town.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
    }
}

void compareSuppliers(void) {
    int id1;
    int id2;
    int a;
    int b;

    if (count < 2) {
        printf("You need at least 2 suppliers to compare.\n");
        return;
    }

    printf("\n--- COMPARE SUPPLIERS ---\n");
    printf("Enter first ID: ");
    scanf("%d", &id1);
    printf("Enter second ID: ");
    scanf("%d", &id2);

    a = findSupplier(id1);
    b = findSupplier(id2);

    if (a == -1 || b == -1) {
        printf("One of the suppliers was not found.\n");
        return;
    }

    printf("\n%s is in %s\n", names[a], towns[a]);
    printf("%s is in %s\n", names[b], towns[b]);

    if (strcmp(towns[a], towns[b]) == 0) {
        printf("They are in the same town.\n");
    } else {
        printf("They are in different towns.\n");
    }
}

void displaySupplierReport(void) {
    printf("\n=========== SUPPLIER REPORT ===========\n");
    printf("Total suppliers: %d\n", count);
    displaySuppliers();
}

void supplierMenu(void) {
    int choice = 0;
    int c;

    while (choice != 5) {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier\n");
        printf("4. Compare suppliers\n");
        printf("5. Back to main menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            choice = 0;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        switch (choice) {
            case 1:
                addSupplier();
                break;
            case 2:
                displaySuppliers();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                compareSuppliers();
                break;
            case 5:
                printf("Going back...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}

/* ---------------- Employee module ---------------- */
void showEmployeeMenu(void) {
    printf("\n");
    printf("..............................\n");
    printf("    EMPLOYEE MANAGEMENT\n");
    printf("..............................\n");
    printf("1. Add Employee\n");
    printf("2. Display Employee\n");
    printf("3. Search Employee\n");
    printf("4. Calculate Salary\n");
    printf("5. Display Relevant information\n");
    printf("6. Back to main menu\n");
    printf("Enter choice: ");
}

void AddEmployees(void) {
    int c;

    if (EmployeeCount >= Max_Employees) {
        printf("Is full\n");
        return;
    }
    int i = EmployeeCount;

    printf("Enter Employee_id: ");
    scanf("%d", &employees[i].Employee_id);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter Name: ");
    fgets(employees[i].Name, sizeof(employees[i].Name), stdin);
    employees[i].Name[strcspn(employees[i].Name, "\n")] = '\0';

    printf("Department: ");
    fgets(employees[i].Department, sizeof(employees[i].Department), stdin);
    employees[i].Department[strcspn(employees[i].Department, "\n")] = '\0';

    printf("Enter Basic_salary: ");
    scanf("%f", &employees[i].Basic_salary);

    printf("Enter Housing_allowance: ");
    scanf("%f", &employees[i].Housing_allowance);

    printf("Enter Transport_allowance: ");
    scanf("%f", &employees[i].Transport_allowance);

    printf("Enter years of service: ");
    scanf("%d", &employees[i].years_of_service);

    EmployeeCount++;

    printf("Employee added.\n");
}

void displayEmployees(void) {
    if (EmployeeCount == 0) {
        printf("NO Employees\n");
        return;
    }
    printf("\n........Display Employees........\n");

    for (int i = 0; i < EmployeeCount; i++) {
        printf("Employee_id : %d\n", employees[i].Employee_id);
        printf("Name : %s\n", employees[i].Name);
        printf("Department : %s\n", employees[i].Department);
        printf("Basic_salary : %.2f\n", employees[i].Basic_salary);
        printf("Housing_allowance : %.2f\n", employees[i].Housing_allowance);
        printf("Transport_allowance : %.2f\n", employees[i].Transport_allowance);
        printf("years of service : %d\n\n", employees[i].years_of_service);
    }
}

void searchEmployee(void) {
    int search_id;

    printf("Enter employee_id to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < EmployeeCount; i++) {
        if (employees[i].Employee_id == search_id) {
            printf("\nEmployee found\n");
            printf("Name : %s\n", employees[i].Name);
            printf("Department : %s\n", employees[i].Department);
            printf("Basic_salary : %.2f\n", employees[i].Basic_salary);
            printf("Housing_allowance : %.2f\n", employees[i].Housing_allowance);
            printf("Transport_allowance : %.2f\n", employees[i].Transport_allowance);
            printf("years of service : %d\n", employees[i].years_of_service);
            return;
        }
    }
    printf("Employee %d not found\n", search_id);
}

void calculateSalary(void) {
    int search_id;

    printf("Enter employee_id to calculate salary: ");
    scanf("%d", &search_id);

    for (int i = 0; i < EmployeeCount; i++) {
        if (employees[i].Employee_id == search_id) {
            float gross_salary = employees[i].Basic_salary
                               + employees[i].Housing_allowance
                               + employees[i].Transport_allowance;
            printf("Name : %s\n", employees[i].Name);
            printf("Department : %s\n", employees[i].Department);
            printf("Basic_salary : %.2f\n", employees[i].Basic_salary);
            printf("Housing_allowance : %.2f\n", employees[i].Housing_allowance);
            printf("Transport_allowance : %.2f\n", employees[i].Transport_allowance);
            printf("years of service : %d\n", employees[i].years_of_service);
            printf("Gross Salary : %.2f\n", gross_salary);
            return;
        }
    }
    printf("Employee %d not found\n", search_id);
}

void display_Relevant_Informantion(void) {
    if (EmployeeCount == 0) {
        printf("NO Employees\n");
        return;
    }
    printf("\n........Relevant Informantion........\n");

    for (int i = 0; i < EmployeeCount; i++) {
        printf("Employee_id : %d\n", employees[i].Employee_id);
        printf("Name : %s\n", employees[i].Name);
        printf("Department : %s\n\n", employees[i].Department);
    }
}

void employeeMenu(void) {
    int choice;
    int c;

    do {
        showEmployeeMenu();
        if (scanf("%d", &choice) != 1) {
            choice = 0;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        switch (choice) {
            case 1:
                AddEmployees();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                calculateSalary();
                break;
            case 5:
                display_Relevant_Informantion();
                break;
            case 6:
                printf("Back to main menu!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
}
