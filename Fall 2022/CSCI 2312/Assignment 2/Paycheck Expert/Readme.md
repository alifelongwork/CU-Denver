*******************************************************
*  Name      :  Austin Long              
*  Class     :  CSC 2312 Section H01           
*  HW#       :  2 Part 1                
*  Due Date  :  Sept 20th, 2022
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
1. Prompts the user to enter their hourly pay, amount of
hours worked in the week, and the amount they want to set
aside each week for retirement
2. Checks for if the weekly hours worked is over 40 to determine
any overtime hours.
3. Calculates regular pay & overtime pay if overtime hours worked
4. Determines gross pay, both weekly and annual then calculates
deductions for social security, medicare, federal tax, state tax,
and retirement amounts
5. Calculates net pay by taking the difference between the gross
and the deductions
6. Prints out a virtual pay stub


*******************************************************
*  Source files
*******************************************************

Name:  PaycheckExpert.cpp
   Entire program written in int main(). Variables declared
   as needed.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 6.1.x  It was 
   compiled, run, and tested on gcc csegrid server.


*******************************************************
*  How to build and run the program
*******************************************************

1. Open a command prompt and set the directory to the .cpp file
location

2. Compile the .cpp file in the typical manner
	(g++ -o PaycheckExpert PaycheckExpert.cpp) if using gnu 

3. Run the program by typing PaycheckExpert or ./PaycheckExpert 
depending on command window.

4. Enter the values and get paid


*******************************************************
* Output
*******************************************************

Test Run #1: Standard Sample Input

Please enter your hourly rate: 21.5
How many hours did you work this week? 44
How much would you like to put towards retirement each week? 15.05
This week wage details:
=======================
Gross pay: $989.00 (Overtime pay: $129.00)

Taxes and deductions:
======================
Social security withdrawal: $61.32
Medicare withdrawal: $14.34
Federal Tax: $114.87
Colorado State Tax: $45.00
Retirement contribution: $15.05

----------------------------
Deduction total: $250.58
----------------------------
Net Pay: $738.42

Test Run #2: User enters 0 for all values

Please enter your hourly rate: 0
How many hours did you work this week? 0
How much would you like to put towards retirement each week? 0
This week wage details:
=======================
Gross pay: $0.00 (Overtime pay: $0.00)

Taxes and deductions:
======================
Social security withdrawal: $0.00
Medicare withdrawal: $0.00
Federal Tax: $0.00
Colorado State Tax: $0.00
Retirement contribution: $0.00

----------------------------
Deduction total: $0.00
----------------------------
Net Pay: $0.00

Test Run #3: User enters letters on accident

Please enter your hourly rate: jk
How many hours did you work this week? How much would you like to put towards retirement each week? This week wage details:
=======================
Gross pay: $0.00 (Overtime pay: $0.00)

Taxes and deductions:
======================
Social security withdrawal: $0.00
Medicare withdrawal: $0.00
Federal Tax: $0.00
Colorado State Tax: $0.00
Retirement contribution: $0.00

----------------------------
Deduction total: $0.00
----------------------------
Net Pay: $0.00

Test Run #4 : User works too much

Please enter your hourly rate: 50
How many hours did you work this week? 80
How much would you like to put towards retirement each week? 100
This week wage details:
=======================
Gross pay: $5000.00 (Overtime pay: $3000.00)

Taxes and deductions:
======================
Social security withdrawal: $163.35
Medicare withdrawal: $72.50
Federal Tax: $992.11
Colorado State Tax: $227.50
Retirement contribution: $100.00

----------------------------
Deduction total: $1555.45
----------------------------
Net Pay: $3444.55
