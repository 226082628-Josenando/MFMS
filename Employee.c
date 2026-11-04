#include<stdio.h>
#include<string.h>



#define Max_Employees 100
struct Employee { 
      int Employee_id;
      char Name [50] ;
      char Department[50] ; 
      float Basic_salary ;
      float Housing_allowance ;
      float Transport_allowance ;
      int   years_of_service;
};

struct Employee  employees[Max_Employees] ;
int EmployeeCount = 0;


void  Menu(){

        printf("\n");
        printf("..............................\n");
        printf("    EMPLOYEE MANAGEMENT\n"   );
        printf("..............................\n");
        printf("1.Add Employee\n");
        printf("2. Display Employee\n");
        printf("3.search Employee\n");
        printf("4.Calculate Salary\n");
        printf("5.Display Relevant information\n");
        printf("6.Exit\n");
        printf("Enter choice\n");
}


void AddEmployees(void){

  if (EmployeeCount>=Max_Employees){
      printf("Is full \n:");
       return;
}
        int c;
        

         
    printf("Enter Employee ID: ");

while (scanf("%d", &employees[EmployeeCount].Employee_id) != 1 ||
       employees[EmployeeCount].Employee_id <= 0){

    printf("Invalid ID. Enter a positive number: ");

    while (getchar() != '\n');
}


    printf("Enter Name: ");
    fgets(employees[EmployeeCount].Name, 50, stdin);
    employees[EmployeeCount].Name[strcspn(employees[EmployeeCount].Name, "\n")] = '\0';


    printf("Enter Department: ");
    fgets(employees[EmployeeCount].Department, 50, stdin);
    employees[EmployeeCount].Department[strcspn(employees[EmployeeCount].Department, "\n")] = '\0';


  printf("Enter Basic Salary: ");

while (scanf("%f", &employees[EmployeeCount].Basic_salary) != 1 ||
       employees[EmployeeCount].Basic_salary < 0){

    printf("Invalid salary. Enter a positive number: ");

    while (getchar() != '\n');
}


  printf("Enter Housing Allowance: ");

while (scanf("%f", &employees[EmployeeCount].Housing_allowance) != 1 ||
       employees[EmployeeCount].Housing_allowance < 0){

    printf("Invalid allowance. Enter a positive number: ");

    while (getchar() != '\n');
}


    printf("Enter Transport Allowance: ");

while (scanf("%f", &employees[EmployeeCount].Transport_allowance) != 1 ||
       employees[EmployeeCount].Transport_allowance < 0){

    printf("Invalid allowance. Enter a positive number: ");

    while (getchar() != '\n');
}


 printf("Enter Years of Service: ");

while (scanf("%d", &employees[EmployeeCount].years_of_service) != 1 ||
       employees[EmployeeCount].years_of_service < 0){

    printf("Invalid years of service. Enter a positive number: ");

    while (getchar() != '\n');
}

    EmployeeCount++;

    printf("Employee added successfully!\n");
}



void displayEmployees(void)


{

    if(EmployeeCount == 0){
    printf("NO Employees\n");
     return;
    }
       printf("\n........Display Employees........\n");

           for(int i = 0 ; i<EmployeeCount;i++){

           printf("Employee_id : %d\n",employees[i].Employee_id);
           printf("Name : %s\n",employees[i].Name);
           printf("Department : %s\n",employees[i].Department);
           printf("Basic_salary : %.2f\n",employees[i].Basic_salary);
           printf("Housing_allowance : %.2f\n",employees[i].Housing_allowance);
           printf("Transport_allowance : %.2f\n",employees[i].Transport_allowance);
           printf("years of service : %d\n",employees[i].years_of_service);
         }

}

void searchEmployee(void) 
{ 
    
int search_id;

printf("Enter employee_id to search ");
scanf("%d",&search_id);

   

    for (int i = 0; i < EmployeeCount; i++) 
      { 
        if (employees[i].Employee_id == search_id ){
           printf(" \nEmployee found\n");
           printf("Name : %s\n",employees[i].Name);
           printf("Department : %s\n",employees[i].Department);
           printf("Basic_salary : %.2f\n",employees[i].Basic_salary);
           printf("Housing_allowance : %.2f\n",employees[i].Housing_allowance);
           printf("Transport_allowance : %.2f\n",employees[i].Transport_allowance);
           printf("years of service : %d\n",employees[i].years_of_service);

           return;

        } 

}
printf("Employee %d not found ",search_id);
}

void calculateSalary(void) 
{ 
    
int search_id;

printf("Enter employee_id to calculate salary ");
scanf("%d",&search_id);

    for (int i = 0; i < EmployeeCount; i++) 
      { 
        if (employees[i].Employee_id == search_id ){
           float gross_salary = employees[i].Basic_salary + employees[i].Housing_allowance + employees[i].Transport_allowance ;
           printf("Name : %s\n",employees[i].Name);
           printf("Department : %s\n",employees[i].Department);
           printf("Basic_salary : %.2f\n",employees[i].Basic_salary);
           printf("Housing_allowance : %.2f\n",employees[i].Housing_allowance);
           printf("Transport_allowance : %.2f\n",employees[i].Transport_allowance);
           printf("years of service : %d\n",employees[i].years_of_service);
           printf("Gross Salary : %.2f\n",gross_salary);
return;
        }
    }


printf("Employee %d not found ",search_id);

}


void display_Relevant_Informantion(void)


{
    if(EmployeeCount == 0){
    printf("NO Employees\n");
     return;
    }
       printf("\n........Relevant Informantion........\n");

           for(int i = 0 ; i<EmployeeCount;i++){

           printf("Employee_id : %d\n",employees[i].Employee_id);
           printf("Name : %s\n",employees[i].Name);
           printf("Department : %s\n",employees[i].Department);
         
           }
        }

int main (){


int choice;
int c;
    

    
do{
Menu();

if (scanf("%d", &choice) != 1) {
    printf("Invalid entry.\n");
    choice = 0;  
        
    }

    while ((c = getchar()) != '\n' && c != EOF);

switch(choice){

case 1:
AddEmployees();
break;

case 2:
displayEmployees();
break;

case 3 :
searchEmployee();
break;


case 4 :
calculateSalary();
break;

case 5 :
display_Relevant_Informantion();
break;

case 6:                                                
printf("Exiting program...\n");
break;


default:
printf ("invalid choice");
}
} while (choice != 6);


    
  return 0;
}















