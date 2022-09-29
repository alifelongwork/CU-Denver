#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	//variables used to keep game running
	
	bool keepPlaying = true;
	const int MAX_GUESSES = 10;
	
	while(keepPlaying)
	{
		//generates random number from 0 to 999 at game start
		std::srand(std::time(nullptr));	
		int randomCorrect = std::rand() % 1000;
		
		std::cout << "[Your program randomly generated the integer " << randomCorrect << "]" << std::endl;
		std::cout << "You have ten chances to guess the correct number within a range of 0 to 999\n";
		std::cout << "Enter your guess (0 to 999): ";
		
		int userGuess = 0;
		
		std::cin >> userGuess;
		
		int numOfGuesses = 1;
		bool youreWrong = true;
		
		std::cout << "# the user enters " << userGuess << " as guess number " << numOfGuesses << std::endl;
		
		//check if user is lucky on the first try, otherwise keep asking the user for their guess until they're correct or 
		//max guesses used
		if(userGuess == randomCorrect)
		{
			std::cout << "WOW FIRST TRY GOOD JOB \n";
		}
		else
		{
			do
			{
				if(userGuess > randomCorrect)
				{
					std::cout << "'" << userGuess << "' is greater than the random number. Try again: ";
					std::cin >> userGuess;
					numOfGuesses++;
					std::cout << " # the user enters " << userGuess << " as guess number " << numOfGuesses << std::endl;
				}
				else if(userGuess < randomCorrect)
				{
					std::cout << "'" << userGuess << "' is less than the random number. Try again: ";
					std::cin >> userGuess;
					numOfGuesses++;
					std::cout << " # the user enters " << userGuess << " as guess number " << numOfGuesses << std::endl;
				}
				else
				{
					youreWrong = false;
				}				
			}while(youreWrong && numOfGuesses < MAX_GUESSES);
		}
	
		//if it took more than one guess but they got it right. Else if it only took one guess. Else they never got it right 
		if(numOfGuesses > 1 && !youreWrong)
		{
			std::cout << "Good job! '" << userGuess << "' is correct. You guessed it in " << numOfGuesses << " tries." << std::endl;	
		}
		else if(numOfGuesses == 1)
		{
			std::cout << "Good job! '" << userGuess << "' is correct. You guessed it in " << numOfGuesses << " try." << std::endl;
		}
		else
		{
			std::cout << "You have used up all your guesses! :(. The correct answer is " << randomCorrect << " Better luck next time! \n";
		}
		
		std::cout << "Would you like to play again? [Y/N] ";
		char playAgain = 'Y'; //default to 'Y' so that game keeps running if user enters anything other than N or n
		std::cin >> playAgain;
		
		if(playAgain == 'N' || playAgain == 'n')
		{
			keepPlaying = false;
		}
	}
	return 0;
}
