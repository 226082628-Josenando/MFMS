# Municipal Financial Management System

Group: 4

Group Members:

Member 1: Gizela Manuel (Leader)
      St. Number: 226029069
Member 2: Nataniel António
      St. Number: 226172015
Member 3: Mauipi Kasuto
      St. Number: 226050750
Member 4: Stephanus Samuel 
      St. Number: 224034308
Member 5: Josenando Gonçalves
      St. Number: 226082628
Member 6: Jada Shangadi
      St. Number 224079948
Member 7: Nelca Zinga
      St. Number: 226046389

**Project Description**

The Municipal Financial Management System is a console application written in C that helps a municipality keep track of its suppliers, employees, departmental budgets and assets. The program starts at a main menu and sends the user into one of the management modules. Each module has its own menu and returns to the main menu when the user is finished. All data is held in memory while the program is running, so it is cleared when the program exits.

**System Features**

The main menu offers six options: Supplier Management, Employee Management, Budget Management, Asset Management, Reports and Exit. The menu repeats until the user chooses Exit, and invalid input is handled without crashing the program.

Supplier Management lets the user add a supplier, display all suppliers, search for a supplier and compare two suppliers. A supplier has an ID, name, email address, telephone number and town. The ID must be positive and unique, the email must contain an @ symbol, and the telephone number must be at least seven characters long. Supplier names and towns are entered as a single word, so an underscore is used instead of a space. Suppliers can be searched by ID, name or town, and the comparison reports whether two suppliers are in the same town. Up to 100 suppliers can be stored.

Employee Management lets the user add an employee, display all employees, search for an employee by ID, calculate a gross salary and display relevant information. An employee record holds the ID, name, department, basic salary, housing allowance, transport allowance and years of service. The gross salary is the basic salary plus the housing allowance plus the transport allowance. The relevant information option shows the ID, name and department of every employee. Up to 100 employees can be stored.

Budget Management asks how many departments the user wants to enter and then reads the department name, allocated budget and expenditure for each one. Negative amounts are rejected. The program then shows the remaining budget in Namibian dollars (N$) and states whether the department is within budget or over budget.

Asset Management lets the user add an asset, display all assets and search for an asset. An asset has an ID, name, type, purchase value, department and condition. The ID must be positive and the purchase value cannot be negative. Assets can be searched by ID, name, type or department. Up to 100 assets can be stored.

The Reports option 

**Compilation Instructions**

The whole system is in a single source file called "main.c". It needs a C compiler such as GCC, which on Windows is provided by MinGW. Open a terminal in the folder that contains the file and run:
gcc main.c -o main

To see compiler warnings as well, compile with:
gcc -Wall main.c -o main


**How to Run the System**

After compiling, run the program from the same folder. On Windows (PowerShell or Command Prompt):
.\main.exe

On Linux or macOS:
./main

The main menu appears. Type the number of the module you want and press Enter. Inside a module, follow the on-screen prompts, and choose the "Back to main menu" option to return. Choose option 6 on the main menu to exit the program.

**Individual Responsibilities**

Main menu, Read me, integration of all modules into one program, GitHub Coordination: Josenando Gonçalves

Supplier Management (main menu option 1): Mauipi Kasuto

Employee Management (main menu option 2): Nelca Zinga

Budget Management (main menu option 3): Nataniel António

Asset Management (main menu option 4): Gizela Manuel (Leader)

Reports (main menu option 5): Stephanus Samuel 

Testing and Documentation: Jada Shangadi
