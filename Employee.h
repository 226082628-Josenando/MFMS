#ifndef EMPLOYEE_H
#define EMPLOYEE_H
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

extern struct Employee employees[Max_Employees] ;
extern int EmployeeCount;


void  Menu();

void AddEmployees(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);
void display_Relevant_Informantion(void);
 
#endif

