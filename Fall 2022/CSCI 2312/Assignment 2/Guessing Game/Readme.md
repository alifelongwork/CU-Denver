*******************************************************
*  Name      :  Austin Long               
*  Class     :  CSC 2312 Section H01           
*  HW#       :  2 Part 2                
*  Due Date  :  Sept 20th, 2022
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************
1. Randomly generates a number from 0 to 999 using the 
C++ STL functions srand() and rand(). Uses the ctime library
to generate a random seed for srand based on computer time.
2. Prompts the user to enter a number between 0 and 999
3. Checks to see if the user entered the correct value on the first
try
4. If not, loops until user gets right answer. Informs user 
whether the guess is too high or too low. The user has a max of 10 guesses
5. Once the correct answer is chosen the game ends, displaying
the value and the number of tries needed. 
6. Prompts user to play again and keeps going until user enters 
'n' or 'N'


*******************************************************
*  Source files
*******************************************************

Name:  GuessingGame.cpp
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
	(g++ -o GuessingGame GuessingGame.cpp) if using gnu 

3. Run the program by typing GuessingGame or ./GuessingGame 
depending on command window.

4. Play the game

*******************************************************
* Output
*******************************************************
Test Run #1: Low/High/Correct Play Again

[Your program randomly generated the integer 385]
Enter your guess (0 to 999): 0
# the user enters 0 as guess number 1
'0' is less than the random number. Try again: 400
 # the user enters 400 as guess number 2
'400' is greater than the random number. Try again: 384
 # the user enters 384 as guess number 3
'384' is less than the random number. Try again: 386
 # the user enters 386 as guess number 4
'386' is greater than the random number. Try again: 385
 # the user enters 385 as guess number 5
Good job! '385' is correct. You guessed it in 5 tries.
Would you like to play again? [Y/N] y
[Your program randomly generated the integer 431]
Enter your guess (0 to 999): 500
# the user enters 500 as guess number 1
'500' is greater than the random number. Try again: 431
 # the user enters 431 as guess number 2
Good job! '431' is correct. You guessed it in 2 tries.
Would you like to play again? [Y/N] n


Test Run #2: First guess correct

[Your program randomly generated the integer 921]
Enter your guess (0 to 999): 921
# the user enters 921 as guess number 1
WOW FIRST TRY GOOD JOB
Good job! '921' is correct. You guessed it in 1 try.
Would you like to play again? [Y/N] y
[Your program randomly generated the integer 953]
Enter your guess (0 to 999): 953
# the user enters 953 as guess number 1
WOW FIRST TRY GOOD JOB

Test Run #3: User uses up all their guess attempts

[Your program randomly generated the integer 417]
Enter your guess (0 to 999): 8
# the user enters 8 as guess number 1
'8' is less than the random number. Try again: 5
 # the user enters 5 as guess number 2
'5' is less than the random number. Try again: 5
 # the user enters 5 as guess number 3
'5' is less than the random number. Try again: 5
 # the user enters 5 as guess number 4
'5' is less than the random number. Try again: 3
 # the user enters 3 as guess number 5
'3' is less than the random number. Try again: 5
 # the user enters 5 as guess number 6
'5' is less than the random number. Try again: 3
 # the user enters 3 as guess number 7
'3' is less than the random number. Try again: 5
 # the user enters 5 as guess number 8
'5' is less than the random number. Try again: 2
 # the user enters 2 as guess number 9
'2' is less than the random number. Try again: 56
 # the user enters 56 as guess number 10
You have used up all your guesses! :(. The correct answer is 417 Better luck next time!
Would you like to play again? [Y/N] y
[Your program randomly generated the integer 456]
Enter your guess (0 to 999): 456
# the user enters 456 as guess number 1
WOW FIRST TRY GOOD JOB
Good job! '456' is correct. You guessed it in 1 try.

Test Run #4: User enters a non-numeric number accidentally (infinite loop proceeds)

You have used up all your guesses! :(. The correct answer is 159 Better luck next time!
Would you like to play again? [Y/N] [Your program randomly generated the integer 159]
Enter your guess (0 to 999): # the user enters 0 as guess number 1
'0' is less than the random number. Try again:  # the user enters 0 as guess number 2
'0' is less than the random number. Try again:  # the user enters 0 as guess number 3
'0' is less than the random number. Try again:  # the user enters 0 as guess number 4
'0' is less than the random number. Try again:  # the user enters 0 as guess number 5
'0' is less than the random number. Try again:  # the user enters 0 as guess number 6
'0' is less than the random number. Try again:  # the user enters 0 as guess number 7
'0' is less than the random number. Try again:  # the user enters 0 as guess number 8
'0' is less than the random number. Try again:  # the user enters 0 as guess number 9
'0' is less than the random number. Try again:  # the user enters 0 as guess number 10
You have used up all your guesses! :(. The correct answer is 159 Better luck next time!
Would you like to play again? [Y/N] [Your program randomly generated the integer 159]
Enter your guess (0 to 999): # the user enters 0 as guess number 1
'0' is less than the random number. Try again:  # the user enters 0 as guess number 2
'0' is less than the random number. Try again:  # the user enters 0 as guess number 3
'0' is less than the random number. Try again:  # the user enters 0 as guess number 4
'0' is less than the random number. Try again:  # the user enters 0 as guess number 5
'0' is less than the random number. Try again:  # the user enters 0 as guess number 6
'0' is less than the random number. Try again:  # the user enters 0 as guess number 7
'0' is less than the random number. Try again:  # the user enters 0 as guess number 8
'0' is less than the random number. Try again:  # the user enters 0 as guess number 9
'0' is less than the random number. Try again:  # the user enters 0 as guess number 10
You have used up all your guesses! :(. The correct answer is 159 Better luck next time!
Would you like to play again? [Y/N] [Your program randomly generated the integer 159]
Enter your guess (0 to 999): # the user enters 0 as guess number 1
'0' is less than the random number. Try again:  # the user enters 0 as guess number 2
'0' is less than the random number. Try again:  # the user enters 0 as guess number 3
'0' is less than the random number. Try again:  # the user enters 0 as guess number 4
'0' is less than the random number. Try again:  # the user enters 0 as guess number 5
'0' is less than the random number. Try again:  # the user enters 0 as guess number 6
'0' is less than the random number. Try again:  # the user enters 0 as guess number 7
'0' is less than the random number. Try again:  # the user enters 0 as guess number 8
'0' is less than the random number. Try again:  # the user enters 0 as guess number 9
'0' is less than the random number. Try again:  # the user enters 0 as guess number 10


