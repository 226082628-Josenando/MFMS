#include <stdio.h>
#include <string.h>
#include "suppliers.h"

int ids[MAX_SUPPLIERS];
char names[MAX_SUPPLIERS][50];
char emails[MAX_SUPPLIERS][50];
char phones[MAX_SUPPLIERS][20];
char towns[MAX_SUPPLIERS][30];
int count = 0;

/* returns position of supplier in the array, -1 if not found */
int findSupplier(int id)
{
int i;
for (i = 0; i < count; i++)
{
if (ids[i] == id)
{
return i;
}
}
return -1;
}

void addSupplier()
{
int id;
int i;
int hasAt;
char name[50];
char email[50];
char phone[20];
char town[30];

if (count >= MAX_SUPPLIERS)
{
printf("Supplier list is full.\n");
return;
}

printf("\n--- ADD SUPPLIER ---\n");

printf("Enter supplier ID: ");
scanf("%d", &id);
while (id <= 0 || findSupplier(id) != -1)
{
if (id <= 0)
{
printf("ID must be positive. Enter again: ");
}
else
{
printf("ID already used. Enter again: ");
}
scanf("%d", &id);
}

printf("Enter supplier name (use _ instead of spaces): ");
scanf("%49s", name);

printf("Enter email: ");
scanf("%49s", email);
hasAt = 0;
for (i = 0; i < strlen(email); i++)
{
if (email[i] == '@')
{
hasAt = 1;
}
}
while (hasAt == 0)
{
printf("Email must have @. Enter again: ");
scanf("%49s", email);
for (i = 0; i < strlen(email); i++)
{
if (email[i] == '@')
{
hasAt = 1;
}
}
}

printf("Enter telephone number: ");
scanf("%19s", phone);
while (strlen(phone) < 7)
{
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

void displaySuppliers()
{
int i;

printf("\n--- SUPPLIERS ---\n");

if (count == 0)
{
printf("No suppliers added yet.\n");
return;
}

for (i = 0; i < count; i++)
{
printf("\nID: %d\n", ids[i]);
printf("Name: %s\n", names[i]);
printf("Email: %s\n", emails[i]);
printf("Phone: %s\n", phones[i]);
printf("Town: %s\n", towns[i]);
}
}

void searchSupplier()
{
int choice;
int id;
int i;
int found = 0;
char word[50];

if (count == 0)
{
printf("No suppliers added yet.\n");
return;
}

printf("\n--- SEARCH SUPPLIER ---\n");
printf("1. Search by ID\n");
printf("2. Search by name\n");
printf("3. Search by town\n");
printf("Enter choice: ");
scanf("%d", &choice);

switch (choice)
{
case 1:
printf("Enter ID: ");
scanf("%d", &id);
i = findSupplier(id);
if (i == -1)
{
printf("Supplier not found.\n");
}
else
{
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
for (i = 0; i < count; i++)
{
if (strcmp(names[i], word) == 0)
{
printf("\nID: %d\n", ids[i]);
printf("Name: %s\n", names[i]);
printf("Email: %s\n", emails[i]);
printf("Phone: %s\n", phones[i]);
printf("Town: %s\n", towns[i]);
found = 1;
}
}
if (found == 0)
{
printf("Supplier not found.\n");
}
break;

case 3:
printf("Enter town: ");
scanf("%49s", word);
for (i = 0; i < count; i++)
{
if (strcmp(towns[i], word) == 0)
{
printf("\nID: %d\n", ids[i]);
printf("Name: %s\n", names[i]);
printf("Email: %s\n", emails[i]);
printf("Phone: %s\n", phones[i]);
printf("Town: %s\n", towns[i]);
found = 1;
}
}
if (found == 0)
{
printf("No suppliers in that town.\n");
}
break;

default:
printf("Invalid choice.\n");
}
}

void compareSuppliers()
{
int id1;
int id2;
int a;
int b;

if (count < 2)
{
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

if (a == -1 || b == -1)
{
printf("One of the suppliers was not found.\n");
return;
}

printf("\n%s is in %s\n", names[a], towns[a]);
printf("%s is in %s\n", names[b], towns[b]);

if (strcmp(towns[a], towns[b]) == 0)
{
printf("They are in the same town.\n");
}
else
{
printf("They are in different towns.\n");
}
}

void displaySupplierReport()
{
printf("\n=========== SUPPLIER REPORT ===========\n");
printf("Total suppliers: %d\n", count);
displaySuppliers();
}

void supplierMenu()
{
int choice = 0;

while (choice != 5)
{
printf("\n===== SUPPLIER MANAGEMENT =====\n");
printf("1. Add supplier\n");
printf("2. Display suppliers\n");
printf("3. Search supplier\n");
printf("4. Compare suppliers\n");
printf("5. Back to main menu\n");
printf("Enter choice: ");
scanf("%d", &choice);

switch (choice)
{
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
