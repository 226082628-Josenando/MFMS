#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SUPPLIERS 100

static char supplierId[MAX_SUPPLIERS][20];
static char supplierName[MAX_SUPPLIERS][100];
static char supplierEmail[MAX_SUPPLIERS][100];
static char supplierPhone[MAX_SUPPLIERS][30];
static char supplierTown[MAX_SUPPLIERS][50];
static int supplierCount = 0;

static void readString(const char prompt[], char text[], int size)
{
    int c;

    printf("%s", prompt);
    if (fgets(text, size, stdin) == NULL) {
        text[0] = '\0';
        return;
    }

    if (strchr(text, '\n') == NULL) {

        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    text[strcspn(text, "\n")] = '\0';
}

static int readChoice(void)
{
    char line[20];
    int value;
    char extra;

    printf("Enter choice: ");
    if (fgets(line, sizeof(line), stdin) == NULL) {
        return -1;
    }
    if (sscanf(line, "%d %c", &value, &extra) != 1) {
        return -1;
    }
    return value;
}

static int findSupplierById(const char id[])
{
    int i;

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(supplierId[i], id) == 0) {
            return i;
        }
    }
    return -1;
}

static int findSupplierByName(const char name[])
{
    int i;

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(supplierName[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

static int isValidEmail(const char email[])
{
    const char *at = strchr(email, '@');
    const char *dot;

    if (at == NULL || at == email) {
        return 0;
    }
    dot = strrchr(at, '.');
    if (dot == NULL || dot == at + 1 || *(dot + 1) == '\0') {
        return 0;
    }
    return 1;
}

static int isValidPhone(const char phone[])
{
    int i;
    int digits = 0;
    int length = (int)strlen(phone);

    for (i = 0; i < length; i++) {
        if (isdigit((unsigned char)phone[i])) {
            digits++;
        } else if (phone[i] == '+' && i == 0) {

        } else if (phone[i] == ' ' || phone[i] == '-') {

        } else {
            return 0;
        }
    }

    if (digits < 7 || digits > 15) {
        return 0;
    }
    return 1;
}

static void printHeader(void)
{
    printf("\n%-8s %-25s %-28s %-15s %-12s\n",
           "ID", "Name", "Email", "Phone", "Town");
    printf("--------------------------------------------------------------------------------------\n");
}

static void printSupplier(int i)
{
    printf("%-8s %-25s %-28s %-15s %-12s\n",
           supplierId[i], supplierName[i], supplierEmail[i],
           supplierPhone[i], supplierTown[i]);
}

int getSupplierCount(void)
{
    return supplierCount;
}

void addSupplier(void)
{
    char id[20];
    char name[100];
    char email[100];
    char phone[30];
    char town[50];
    int valid;

    if (supplierCount >= MAX_SUPPLIERS) {
        printf("\nSupplier list is full.\n");
        return;
    }

    printf("\n--- ADD SUPPLIER ---\n");

    valid = 0;
    while (valid == 0) {
        readString("Enter supplier ID (e.g. SUP001): ", id, sizeof(id));
        if (strlen(id) == 0) {
            printf("Supplier ID cannot be empty.\n");
        } else if (strchr(id, ' ') != NULL) {
            printf("Supplier ID cannot contain spaces.\n");
        } else if (findSupplierById(id) != -1) {
            printf("That supplier ID already exists.\n");
        } else {
            valid = 1;
        }
    }

    valid = 0;
    while (valid == 0) {
        readString("Enter supplier name: ", name, sizeof(name));
        if (strlen(name) == 0) {
            printf("Supplier name cannot be empty.\n");
        } else if (findSupplierByName(name) != -1) {
            printf("A supplier with that name already exists.\n");
        } else {
            valid = 1;
        }
    }

    valid = 0;
    while (valid == 0) {
        readString("Enter email: ", email, sizeof(email));
        if (isValidEmail(email) == 0) {
            printf("Invalid email (example: sales@abc.com).\n");
        } else {
            valid = 1;
        }
    }

    valid = 0;
    while (valid == 0) {
        readString("Enter phone: ", phone, sizeof(phone));
        if (isValidPhone(phone) == 0) {
            printf("Invalid phone number (7-15 digits).\n");
        } else {
            valid = 1;
        }
    }

    valid = 0;
    while (valid == 0) {
        readString("Enter town: ", town, sizeof(town));
        if (strlen(town) == 0) {
            printf("Town cannot be empty.\n");
        } else {
            valid = 1;
        }
    }

    strcpy(supplierId[supplierCount], id);
    strcpy(supplierName[supplierCount], name);
    strcpy(supplierEmail[supplierCount], email);
    strcpy(supplierPhone[supplierCount], phone);
    strcpy(supplierTown[supplierCount], town);
    supplierCount++;

    printf("\nSupplier added successfully.\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printHeader();
    for (i = 0; i < supplierCount; i++) {
        printSupplier(i);
    }
    printf("\nTotal suppliers: %d\n", supplierCount);
}

void searchSupplier(void)
{
    int choice;
    int i;
    int found = 0;
    char searchText[100];
    char description[250];

    if (supplierCount == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    printf("\n--- SEARCH SUPPLIER ---\n");
    printf("1. Search by name\n");
    printf("2. Search by ID\n");
    printf("3. Search by town\n");
    choice = readChoice();

    if (choice < 1 || choice > 3) {
        printf("Invalid choice. Please enter 1-3.\n");
        return;
    }

    readString("Enter text to search for: ", searchText, sizeof(searchText));
    if (strlen(searchText) == 0) {
        printf("Search text cannot be empty.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++) {
        int match = 0;

        if (choice == 1) {
            if (strcmp(supplierName[i], searchText) == 0) {
                match = 1;
            }
        } else if (choice == 2) {
            if (strcmp(supplierId[i], searchText) == 0) {
                match = 1;
            }
        } else if (choice == 3) {
            if (strcmp(supplierTown[i], searchText) == 0) {
                match = 1;
            }
        }

        if (match == 1) {
            if (found == 0) {
                printHeader();
            }
            printSupplier(i);

            strcpy(description, supplierName[i]);
            strcat(description, " operates in ");
            strcat(description, supplierTown[i]);
            strcat(description, ".");
            printf("  -> %s\n", description);

            found++;
        }
    }

    if (found == 0) {
        printf("\nSupplier not found.\n");
    } else {
        printf("\nSupplier found (%d).\n", found);
    }
}

void showNameLength(void)
{
    char name[100];
    int position;

    if (supplierCount == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }

    readString("Enter supplier name: ", name, sizeof(name));
    position = findSupplierByName(name);

    if (position == -1) {
        printf("Supplier not found.\n");
    } else {
        printf("Supplier name length: %zu\n", strlen(supplierName[position]));
        printf("Email length: %zu\n", strlen(supplierEmail[position]));
        printf("Town length: %zu\n", strlen(supplierTown[position]));
    }
}

void compareSuppliers(void)
{
    char id1[20];
    char id2[20];
    int a;
    int b;
    int result;

    if (supplierCount < 2) {
        printf("\nYou need at least 2 suppliers to compare.\n");
        return;
    }

    printf("\n--- COMPARE SUPPLIERS ---\n");
    readString("Enter first supplier ID: ", id1, sizeof(id1));
    readString("Enter second supplier ID: ", id2, sizeof(id2));

    a = findSupplierById(id1);
    b = findSupplierById(id2);

    if (a == -1 || b == -1) {
        printf("One or both supplier IDs were not found.\n");
        return;
    } else if (a == b) {
        printf("Please enter two different suppliers.\n");
        return;
    }

    printf("\n%-10s %-28s %-28s\n", "", supplierId[a], supplierId[b]);
    printf("%-10s %-28s %-28s\n", "Name", supplierName[a], supplierName[b]);
    printf("%-10s %-28s %-28s\n", "Email", supplierEmail[a], supplierEmail[b]);
    printf("%-10s %-28s %-28s\n", "Phone", supplierPhone[a], supplierPhone[b]);
    printf("%-10s %-28s %-28s\n", "Town", supplierTown[a], supplierTown[b]);

    if (strcmp(supplierTown[a], supplierTown[b]) == 0) {
        printf("\nBoth suppliers are in %s.\n", supplierTown[a]);
    } else {
        printf("\nThe suppliers are in different towns.\n");
    }

    result = strcmp(supplierName[a], supplierName[b]);
    if (result < 0) {
        printf("Alphabetically, %s comes first.\n", supplierName[a]);
    } else if (result > 0) {
        printf("Alphabetically, %s comes first.\n", supplierName[b]);
    }
}

void displaySupplierReport(void)
{
    printf("\n========================================\n");
    printf("            SUPPLIER REPORT\n");
    printf("========================================\n");
    displaySuppliers();
}

void supplierMenu(void)
{
    int choice = 0;

    while (choice != 6) {
        printf("\n========================================\n");
        printf("          SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Compare Suppliers\n");
        printf("6. Back to Main Menu\n");

        choice = readChoice();

        if (choice == 1) {
            addSupplier();
        } else if (choice == 2) {
            displaySuppliers();
        } else if (choice == 3) {
            searchSupplier();
        } else if (choice == 4) {
            showNameLength();
        } else if (choice == 5) {
            compareSuppliers();
        } else if (choice == 6) {
            printf("Returning to main menu...\n");
        } else {
            printf("Invalid choice. Please enter 1-6.\n");
        }
    }
}

int main(void)
{
    supplierMenu();
    return 0;
}