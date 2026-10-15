#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ---------------- Constants ---------------- */
#define Max_Employees   100
#define MAX_SUPPLIERS   100
#define MAX_ASSETS      100
#define MAX_DEPARTMENTS 50

/* ---------------- Data structures ---------------- */
struct Employee {
    int   Employee_id;
    char  Name[50];
    char  Department[50];
    float Basic_salary;
    float Housing_allowance;
    float Transport_allowance;
    int   years_of_service;
};

struct DepartmentBudget {
    char  departmentName[50];
    float allocatedBudget;
    float expenditure;
    float remainingBudget;
};

struct Asset {
    int    assetID;
    char   assetName[50];
    char   assetType[40];
    double purchaseValue;
    char   department[40];
    char   condition[45];
};

/* ---------------- Global data ---------------- */
/* Employees */
struct Employee employees[Max_Employees];
int EmployeeCount = 0;

/* Budget */
struct DepartmentBudget departmentBudgets[MAX_DEPARTMENTS];
int departmentBudgetCount = 0;

/* Suppliers */
int  ids[MAX_SUPPLIERS];
char names[MAX_SUPPLIERS][50];
char emails[MAX_SUPPLIERS][50];
char phones[MAX_SUPPLIERS][20];
char towns[MAX_SUPPLIERS][30];
int  count = 0;

/* Assets */
struct Asset assets[MAX_ASSETS];
int assetCount = 0;

/* ---------------- Prototypes ---------------- */
/* Helper */
void clearInputBuffer(void);

/* Employee module */
float getGrossSalary(struct Employee e);
void Menu(void);
void AddEmployees(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);
void display_Relevant_Informantion(void);
void employeeMenu(void);

/* Budget module */
void budgetManagement(void);

/* Supplier module */
int  findSupplier(int id);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
void compareSuppliers(void);
void supplierMenu(void);

/* Asset module */
void addAsset(void);
void displayAsset(void);
void searchAsset(void);
void assetMenu(void);

/* Reports module */
void generateEmployeeReport(void);
void generateBudgetReport(void);
void generateSupplierReport(void);
void generateAssetReport(void);
void generateComprehensiveReport(void);
void reportsMenu(void);

/* ---------------- Main ---------------- */
int main(void) {
    char municipalityName[100];
    char mayorName[100];
    long population;
    int choice;

    
    printf("=====================================================\n");
    printf("        MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("=====================================================\n\n");

    printf("Welcome to Windhoek Municipality\n\n");

    printf("Please enter the following details:\n");
    printf("-----------------------------------------------------\n");

    printf("Municipality Name: ");
    fgets(municipalityName, sizeof(municipalityName), stdin);
    municipalityName[strcspn(municipalityName, "\n")] = '\0';

    printf("Mayor's Name: ");
    fgets(mayorName, sizeof(mayorName), stdin);
    mayorName[strcspn(mayorName, "\n")] = '\0';

    printf("Population: ");
    while (scanf("%ld", &population) != 1 || population < 0) {
        printf("Invalid! Enter a valid population: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    printf("\n=====================================================\n");
    printf("               MUNICIPAL INFORMATION REPORT\n");
    printf("=====================================================\n");
    printf("%-25s: %s\n", "Municipality Name", municipalityName);
    printf("%-25s: %s\n", "Mayor's Name", mayorName);
    printf("%-25s: %ld\n", "Population", population);
    printf("=====================================================\n");

    /* ---- Main menu ---- */
    do {
        printf("\n========================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
        printf("========================================\n");

        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            choice = 0;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: employeeMenu();     break;
            case 2: budgetManagement(); break;
            case 3: supplierMenu();     break;
            case 4: assetMenu();        break;
            case 5: reportsMenu();      break;
            case 6: printf("Exiting the program.\n"); break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
/* ---------------- Helper ---------------- */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ---------------- Employee module ---------------- */

/* Gross salary = basic + housing allowance + transport allowance */
float getGrossSalary(struct Employee e) {
    return e.Basic_salary + e.Housing_allowance + e.Transport_allowance;
}

void Menu(void) {
    printf("\n");
    printf("..............................\n");
    printf("    EMPLOYEE MANAGEMENT\n");
    printf("..............................\n");
    printf("1. Add Employee\n");
    printf("2. Display Employee\n");
    printf("3. Search Employee\n");
    printf("4. Calculate Salary\n");
    printf("5. Display Relevant information\n");
    printf("6. Back to Main Menu\n");
    printf("Enter choice: ");
}

void AddEmployees(void) {
    if (EmployeeCount >= Max_Employees) {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter Employee ID: ");
    while (scanf("%d", &employees[EmployeeCount].Employee_id) != 1 ||
           employees[EmployeeCount].Employee_id <= 0) {
        printf("Invalid ID. Enter a positive number: ");
        clearInputBuffer();
    }
    clearInputBuffer();   /* remove the leftover newline before fgets */

    printf("Enter Name: ");
    fgets(employees[EmployeeCount].Name, 50, stdin);
    employees[EmployeeCount].Name[strcspn(employees[EmployeeCount].Name, "\n")] = '\0';

    printf("Enter Department: ");
    fgets(employees[EmployeeCount].Department, 50, stdin);
    employees[EmployeeCount].Department[strcspn(employees[EmployeeCount].Department, "\n")] = '\0';

    printf("Enter Basic Salary: ");
    while (scanf("%f", &employees[EmployeeCount].Basic_salary) != 1 ||
           employees[EmployeeCount].Basic_salary < 0) {
        printf("Invalid salary. Enter a positive number: ");
        clearInputBuffer();
    }

    printf("Enter Housing Allowance: ");
    while (scanf("%f", &employees[EmployeeCount].Housing_allowance) != 1 ||
           employees[EmployeeCount].Housing_allowance < 0) {
        printf("Invalid allowance. Enter a positive number: ");
        clearInputBuffer();
    }

    printf("Enter Transport Allowance: ");
    while (scanf("%f", &employees[EmployeeCount].Transport_allowance) != 1 ||
           employees[EmployeeCount].Transport_allowance < 0) {
        printf("Invalid allowance. Enter a positive number: ");
        clearInputBuffer();
    }

    printf("Enter Years of Service: ");
    while (scanf("%d", &employees[EmployeeCount].years_of_service) != 1 ||
           employees[EmployeeCount].years_of_service < 0) {
        printf("Invalid years of service. Enter a positive number: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    EmployeeCount++;
    printf("Employee added successfully!\n");
}

void displayEmployees(void) {
    if (EmployeeCount == 0) {
        printf("NO Employees\n");
        return;
    }

    printf("\n........Display Employees........\n");
    for (int i = 0; i < EmployeeCount; i++) {
        printf("\nEmployee_id : %d\n", employees[i].Employee_id);
        printf("Name : %s\n", employees[i].Name);
        printf("Department : %s\n", employees[i].Department);
        printf("Basic_salary : %.2f\n", employees[i].Basic_salary);
        printf("Housing_allowance : %.2f\n", employees[i].Housing_allowance);
        printf("Transport_allowance : %.2f\n", employees[i].Transport_allowance);
        printf("years of service : %d\n", employees[i].years_of_service);
    }
}

void searchEmployee(void) {
    int search_id;

    printf("Enter employee_id to search: ");
    if (scanf("%d", &search_id) != 1) {
        clearInputBuffer();
        printf("Invalid ID.\n");
        return;
    }
    clearInputBuffer();

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
    if (scanf("%d", &search_id) != 1) {
        clearInputBuffer();
        printf("Invalid ID.\n");
        return;
    }
    clearInputBuffer();

    for (int i = 0; i < EmployeeCount; i++) {
        if (employees[i].Employee_id == search_id) {
            float gross_salary = getGrossSalary(employees[i]);
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

    printf("\n........Relevant Information........\n");
    for (int i = 0; i < EmployeeCount; i++) {
        printf("\nEmployee_id : %d\n", employees[i].Employee_id);
        printf("Name : %s\n", employees[i].Name);
        printf("Department : %s\n", employees[i].Department);
    }
}

void employeeMenu(void) {
    int choice;

    do {
        Menu();

        if (scanf("%d", &choice) != 1) {
            printf("Invalid entry.\n");
            choice = 0;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: AddEmployees();                break;
            case 2: displayEmployees();            break;
            case 3: searchEmployee();              break;
            case 4: calculateSalary();             break;
            case 5: display_Relevant_Informantion(); break;
            case 6: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);
}

/* ---------------- Budget module ---------------- */
void budgetManagement(void) {
    char department[50];
    int numberOfDepartments;
    float allocatedBudget;
    float expenditure;
    float remainingBudget;
    int valid;

    if (departmentBudgetCount >= MAX_DEPARTMENTS) {
        printf("Budget list is full.\n");
        return;
    }

    printf("\n--- BUDGET MANAGEMENT ---\n");
    printf("How many departments do you want to enter? ");
    while (scanf("%d", &numberOfDepartments) != 1 || numberOfDepartments < 0 ||
           numberOfDepartments > MAX_DEPARTMENTS - departmentBudgetCount) {
        printf("Invalid! Enter a number between 0 and %d: ",
               MAX_DEPARTMENTS - departmentBudgetCount);
        clearInputBuffer();
    }
    clearInputBuffer();

    for (int i = 0; i < numberOfDepartments; i++) {
        printf("\n--- DEPARTMENT %d ---\n", i + 1);

        do {
            valid = 1;

            printf("Enter department name: ");
            scanf(" %49[^\n]", department);
            clearInputBuffer();

            for (int j = 0; department[j] != '\0'; j++) {
                if (isdigit((unsigned char)department[j])) {
                    valid = 0;
                }
            }

            if (valid == 0) {
                printf("Invalid! Department name cannot contain numbers.\n");
            }
        } while (valid == 0);

        printf("Enter allocated budget: N$");
        while (scanf("%f", &allocatedBudget) != 1 || allocatedBudget < 0) {
            printf("Invalid! Budget cannot be negative.\n");
            printf("Enter allocated budget again: N$");
            clearInputBuffer();
        }

        printf("Enter expenditure: N$");
        while (scanf("%f", &expenditure) != 1 || expenditure < 0) {
            printf("Invalid! Expenditure cannot be negative.\n");
            printf("Enter expenditure again: N$");
            clearInputBuffer();
        }
        clearInputBuffer();

        remainingBudget = allocatedBudget - expenditure;

        /* save so the Reports module can use it */
        strcpy(departmentBudgets[departmentBudgetCount].departmentName, department);
        departmentBudgets[departmentBudgetCount].allocatedBudget = allocatedBudget;
        departmentBudgets[departmentBudgetCount].expenditure = expenditure;
        departmentBudgets[departmentBudgetCount].remainingBudget = remainingBudget;
        departmentBudgetCount++;

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
}

/* ---------------- Supplier module ---------------- */
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
    int id = 0;
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
    while (scanf("%d", &id) != 1 || id <= 0 || findSupplier(id) != -1) {
        if (id <= 0) {
            printf("ID must be positive. Enter again: ");
        } else {
            printf("ID already used. Enter again: ");
        }
        clearInputBuffer();
        id = 0;
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
    if (scanf("%d", &choice) != 1) {
        clearInputBuffer();
        printf("Invalid choice.\n");
        return;
    }

    switch (choice) {
        case 1:
            printf("Enter ID: ");
            if (scanf("%d", &id) != 1) {
                clearInputBuffer();
                printf("Invalid ID.\n");
                break;
            }
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
    if (scanf("%d", &id1) != 1) {
        clearInputBuffer();
        printf("Invalid ID.\n");
        return;
    }
    printf("Enter second ID: ");
    if (scanf("%d", &id2) != 1) {
        clearInputBuffer();
        printf("Invalid ID.\n");
        return;
    }

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

void supplierMenu(void) {
    int choice = 0;

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
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addSupplier();      break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier();   break;
            case 4: compareSuppliers(); break;
            case 5: printf("Going back...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    }
}

/* ---------------- Asset module ---------------- */
void addAsset(void) {
    int c;

    if (assetCount >= MAX_ASSETS) {
        printf("Register is full.\n");
        return;
    }

    printf("Enter Asset ID: ");
    while (scanf("%d", &assets[assetCount].assetID) != 1 ||
           assets[assetCount].assetID <= 0) {
        printf("Negative values are not allowed!\n");
        printf("Enter Asset ID: ");
        clearInputBuffer();
    }
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter Asset Name: ");
    fgets(assets[assetCount].assetName, 50, stdin);
    assets[assetCount].assetName[strcspn(assets[assetCount].assetName, "\n")] = '\0';

    printf("Enter Asset Type: ");
    fgets(assets[assetCount].assetType, 40, stdin);
    assets[assetCount].assetType[strcspn(assets[assetCount].assetType, "\n")] = '\0';

    printf("Enter Asset Purchase Value: ");
    while (scanf("%lf", &assets[assetCount].purchaseValue) != 1 ||
           assets[assetCount].purchaseValue < 0) {
        printf("Negative values are not allowed!\n");
        printf("Enter Asset Purchase Value: ");
        clearInputBuffer();
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
    printf("----------------------------------------------------\n");
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
    char searchTerm[50] = "";

    if (assetCount == 0) {
        printf("No assets available.\n");
        return;
    }

    printf("\n1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Type\n");
    printf("4. Search by Department\n");
    printf("Choose your option: ");
    if (scanf("%d", &option) != 1) {
        clearInputBuffer();
        printf("Invalid option.\n");
        return;
    }

    while ((c = getchar()) != '\n' && c != EOF);

    if (option == 1) {
        printf("Enter ID: ");
        if (scanf("%d", &id) != 1) {
            clearInputBuffer();
            printf("Invalid ID.\n");
            return;
        }
        clearInputBuffer();
    }
    else if (option == 2) {
        printf("Enter Name: ");
        fgets(searchTerm, sizeof(searchTerm), stdin);
        searchTerm[strcspn(searchTerm, "\n")] = '\0';
    }
    else if (option == 3) {
        printf("Enter Type: ");
        fgets(searchTerm, sizeof(searchTerm), stdin);
        searchTerm[strcspn(searchTerm, "\n")] = '\0';
    }
    else if (option == 4) {
        printf("Enter Department: ");
        fgets(searchTerm, sizeof(searchTerm), stdin);
        searchTerm[strcspn(searchTerm, "\n")] = '\0';
    }
    else {
        printf("Invalid option.\n");
        return;
    }

    for (int i = 0; i < assetCount; i++) {
        if ((option == 1 && assets[i].assetID == id) ||
            (option == 2 && strcmp(assets[i].assetName, searchTerm) == 0) ||
            (option == 3 && strcmp(assets[i].assetType, searchTerm) == 0) ||
            (option == 4 && strcmp(assets[i].department, searchTerm) == 0)) {

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

    do {
        printf("\n-----------------------Asset Management Menu----------------------\n");
        printf("1. Add Asset\n");
        printf("2. Display Asset\n");
        printf("3. Search Asset\n");
        printf("4. Back to main Menu\n");
        printf("Choose your option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid entry.\n");
            choice = 0;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: addAsset();     break;
            case 2: displayAsset(); break;
            case 3: searchAsset();  break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf("Error...!\n"); break;
        }
    } while (choice != 4);
}

/* ---------------- Reports module ---------------- */
void generateEmployeeReport(void) {
    float totalBasic = 0.0f;
    float totalAllowances = 0.0f;
    float totalGross = 0.0f;
    float averageGross = 0.0f;
    float highestGross = 0.0f;
    float lowestGross = 0.0f;

    printf("\n========== EMPLOYEE REPORT ==========\n");

    if (EmployeeCount == 0) {
        printf("Total Employees: 0\n");
        printf("No employee data available.\n");
        printf("=====================================\n\n");
        return;
    }

    /* Gross salary = basic + housing allowance + transport allowance */
    highestGross = getGrossSalary(employees[0]);
    lowestGross = getGrossSalary(employees[0]);

    for (int i = 0; i < EmployeeCount; i++) {
        float gross = getGrossSalary(employees[i]);

        totalBasic += employees[i].Basic_salary;
        totalAllowances += employees[i].Housing_allowance + employees[i].Transport_allowance;
        totalGross += gross;

        if (gross > highestGross) {
            highestGross = gross;
        }
        if (gross < lowestGross) {
            lowestGross = gross;
        }
    }

    averageGross = totalGross / EmployeeCount;

    printf("Total Employees: %d\n", EmployeeCount);
    printf("Total Basic Salary: N$%.2f\n", totalBasic);
    printf("Total Allowances (Housing + Transport): N$%.2f\n", totalAllowances);
    printf("Average Gross Salary: N$%.2f\n", averageGross);
    printf("Highest Gross Salary: N$%.2f\n", highestGross);
    printf("Lowest Gross Salary: N$%.2f\n", lowestGross);
    printf("Total Gross Salary Expense: N$%.2f\n", totalGross);

    printf("\n--- GROSS SALARY BREAKDOWN BY DEPARTMENT ---\n");
    char departments[50][50];
    int deptCount = 0;
    float deptGross[50] = {0};
    int deptEmployees[50] = {0};

    for (int i = 0; i < EmployeeCount; i++) {
        int found = 0;
        float gross = getGrossSalary(employees[i]);

        for (int j = 0; j < deptCount; j++) {
            if (strcmp(departments[j], employees[i].Department) == 0) {
                found = 1;
                deptGross[j] += gross;
                deptEmployees[j]++;
                break;
            }
        }
        if (!found && deptCount < 50) {
            strcpy(departments[deptCount], employees[i].Department);
            deptGross[deptCount] = gross;
            deptEmployees[deptCount] = 1;
            deptCount++;
        }
    }

    for (int i = 0; i < deptCount; i++) {
        printf("\nDepartment: %s\n", departments[i]);
        printf("  Employees: %d\n", deptEmployees[i]);
        printf("  Total Gross Salary: N$%.2f\n", deptGross[i]);
        printf("  Average Gross Salary: N$%.2f\n", deptGross[i] / deptEmployees[i]);
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
        clearInputBuffer();

        switch (choice) {
            case 1: generateEmployeeReport();      break;
            case 2: generateBudgetReport();        break;
            case 3: generateSupplierReport();      break;
            case 4: generateAssetReport();         break;
            case 5: generateComprehensiveReport(); break;
            case 6: printf("Returning to main menu...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}
