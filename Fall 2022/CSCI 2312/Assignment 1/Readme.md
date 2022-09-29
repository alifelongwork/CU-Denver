*******************************************************
*  Name      : Austin Long      
*  Class     :  CSC 2312 Section H01           
*  HW#       :  1                
*  Due Date  :  September 6th, 20222
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
1. Prompt's the user to enter their name, today's weather
as a single letter (S = Sunny, R = Rainy, W = Windy) and the 
current day of the week as a number (0 = Sunday ... 6 = Saturday)
2. Based on the weather and day of the week, an activity is chosen
for the user to do that day
- Sunny and Weekday (M-F): Play Tennis
- Sunny and Weekend (Sat, Sun): Go Hiking
- Rainy and Weekday (M-F): Stay Home
- Rainy and Weekend (Sat, Sun): Go Bowling
- Windy and Weekday (M-F): Fly a kite
- Windy and Weekend (Sat, Sun): Go Hang-gliding

Note: There is not input error checking so user must enter 
the information correctly


*******************************************************
*  Source files
*******************************************************

Name:  helloWorld.cpp
   Main program. Appropriate libraries included. Creates
variables for the users name, the current weather, the day, and
the activity.

The users name is stored as a string using std::string. 
The current weather is stored as a char
The day is stored as a number
The activity is stored as a string
Once the data is entered, checks are performed for the day 
to convert the number to a string of the actual day. 
The weather and day of the week are checked using nested
if-else statements in order to determine which activity the
user should pursue that day. The activity is stored as a string
and output after all checks are performed

   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 6.1.x  It was 
   compiled, run, and tested on gcc csegrid server.


*******************************************************
*  How to build and run the program
*******************************************************

1. Open a command line window and change the directory to the file location

2. Build the program.

   Compile the program using:
   % make

3. Run the program by:
   % ./helloWorld

4. Delete the obj files, executables, and core dump by
   %./make clean

