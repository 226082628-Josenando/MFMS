#include<stdio.h>




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

void  Menu(){

        printf("\n");
        printf("..............................\n");
        printf("    EMPLOYEE MANAGEMENT\n"   );
        printf("..............................\n");
        printf("1.Add Employee\n");
        printf("2. Display Employee\n");
        printf("3.search Employee\n");
        printf("4.Calculate Salary\n");
        printf("5. Display Relevant information\n");
        printf("6.Exit\n");
        printf("Enter choice\n");
}


void AddEmployees(struct Employee  employees[], int *count){

  if (*count>=Max_Employees){
      printf("Is full \n:");
       return;
}
        int i = *count;

       printf("Enter Employee_id :");
       scanf("%d",&employees[i].Employee_id);
       getchar();

       printf("Enter Name :");
       fgets(employees[i].Name,sizeof(employees[i].Name),stdin);

       printf("Department :");
       fgets(employees[i].Department,sizeof(employees[i].Department),stdin);

       printf("Enter Basic_salary :");
       scanf("%f",&employees[i].Basic_salary);

       printf("Enter Housing_allowance :");
       scanf("%f",&employees[i].Housing_allowance);

       printf("Enter Transport_allowance :");
       scanf("%f",&employees[i].Transport_allowance); 

       printf("Enter years of service :");
       scanf("%d",&employees[i].years_of_service);
       

        *count = *count +1 ;

         printf("Employee added:\n");

}


void displayEmployees(struct Employee  employees[], int count)


{

    if(count == 0){
    printf("NO Employees\n");
     return;
    }
       printf("\n........Display Employees........\n");

           for(int i = 0 ; i<count;i++){

           printf("Employee_id : %d\n",employees[i].Employee_id);
           printf("Name : %s\n",employees[i].Name);
           printf("Department : %s\n",employees[i].Department);
           printf("Basic_salary : %.2f\n",employees[i].Basic_salary);
           printf("Housing_allowance : %.2f\n",employees[i].Housing_allowance);
           printf("Transport_allowance : %.2f\n",employees[i].Transport_allowance);
           printf("years of service : %d\n",employees[i].years_of_service);
         }

}

void searchEmployee(struct Employee  employees[], int count) 
{ 
    
int search_id;

printf("Enter employee_id to search ");
scanf("%d",&search_id);

    for (int i = 0; i < count; i++) 
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
printf("Employee not found ",search_id);
}

void calculateSalary(struct Employee  employees[], int count) 
{ 
    
int search_id;

printf("Enter employee_id to calculate salary ");
scanf("%d",&search_id);

    for (int i = 0; i < count; i++) 
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


printf("Employee not found ",search_id);

}


void display_Relevant_Informantion(struct Employee  employees[], int count)


{
    if(count == 0){
    printf("NO Employees\n");
     return;
    }
       printf("\n........Relevant Informantion........\n");

           for(int i = 0 ; i<count;i++){

           printf("Employee_id : %d\n",employees[i].Employee_id);
           printf("Name : %s\n",employees[i].Name);
           printf("Department : %s\n",employees[i].Department);
         
           }
        }

int main (){

 struct Employee  employees[Max_Employees] ;
int EmployeeCount = 0;
int choice;

    

    
do{
Menu();
scanf("%d",&choice);

switch(choice){

case 1:
AddEmployees(employees,&EmployeeCount);
break;

case 2:
displayEmployees(employees,EmployeeCount);
break;

case 3 :
searchEmployee(employees,EmployeeCount);
break;


case 4 :
calculateSalary(employees,EmployeeCount);
break;

case 5 :
display_Relevant_Informantion(employees,EmployeeCount);
break;


default:
printf ("invalid choice");
}
} while (choice != 5);


    
  return 0;
}















