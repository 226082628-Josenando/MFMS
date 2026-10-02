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

void  Menu();

void AddEmployees(struct Employee  employees[], int *count);
void displayEmployees(struct Employee  employees[], int count);
void searchEmployee(struct Employee  employees[], int count);
void calculateSalary(struct Employee  employees[], int count);
void display_Relevant_Informantion(struct Employee  employees[], int count);
 

