#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath> 
#include <string>

int main()
{
	//standard two decimal precision
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);
	
	//constants for monthly withdraw RNG
	const int MAX_WITHDRAW = 620;
	const int MIN_WITHDRAW = 480;
	const int MONTHLY_WITHDRAW_DIFF = (MAX_WITHDRAW - MIN_WITHDRAW) + 1;	
	
	const int COMPOUND_PERIOD = 12; //compounded monthly
	
	double initialDeposit;
	std::cout << "How much would you like to deposit? ";
	std::cin >> initialDeposit;
	std::cout << "You've deposited: $" << initialDeposit << std::endl;
	
	double annualInterest;
	std::cout << "In a perfect world, we can pick our interest rate. What annual interest rate would you like? ";
	std::cin >> annualInterest;
	std::cout << "You've chosen an interest rate of " << annualInterest << "% per year. \n";
	
	annualInterest /= 100; //convert to decimal;
	
	std::cout << "Give me a moment to find out how long before you go broke. Assuming you withdraw an amount between $480 to $620 each month \n";
	
	//seed random number with computer time
	std::srand(std::time(nullptr));	
	
	double interestOnPrincipal = annualInterest / COMPOUND_PERIOD; //works for any compounding period
	
	//output formatting
	std::cout << "# of Month	Month/Year	Initial Balance		Withdrawal		Interest	New Balance \n";
	std::cout << "==========	==========	===============		==========		========	=========== \n";
	
	int monthNumber = 1;
	int yearNumber = 1;
	std::string currentMonth = "January";
	int currentYear = 2022;
	
	double monthlyInterest;
	double afterWithdraw;	
	double newBalance;
	double monthlyInitialBal = initialDeposit;
	
	bool notBrokeYet = true;
	int monthsUntilBroke = 0;		
	
	int monthlyWithdraw;
	
	//most of the code in this loop is formatting and output. The algorithm still matches the pseudocode
	while(notBrokeYet)
	{		
		/*
		Generate random number mod the difference between the min and max withdraw plus one.
		In this case it gives us a random number between 0 and 140. Add the min withdraw to shift
		the range from min to max. min = 0 + 480 max = 140 + 480
		*/
		monthlyWithdraw = (std::rand() % MONTHLY_WITHDRAW_DIFF) + MIN_WITHDRAW; 
				
		std::cout << "	" << monthNumber << "	";
		
		//set string variable currentMonth to correct month based on monthNumber
		switch(monthNumber)
		{
			case 1:
				currentMonth = "January";
			break;
			case 2:
				currentMonth = "February";
			break;
			case 3:
				currentMonth = "March";
			break;
			case 4:
				currentMonth = "April";
			break;
			case 5:
				currentMonth = "May";
			break;
			case 6:
				currentMonth = "June";
			break;
			case 7:
				currentMonth = "July";
			break;
			case 8:
				currentMonth = "August";
			break;
			case 9:
				currentMonth = "September";
			break;
			case 10:
				currentMonth = "October";
			break;
			case 11:
				currentMonth = "November";
			break;
			case 12:
				currentMonth = "December";
			break;
		}
		
		std::cout << currentMonth << " " << currentYear << "	";
		
		//formatting statements
		if(monthlyInitialBal > 1000.00)
		{
			std::cout << "$" << monthlyInitialBal << "	";
		}
		else
		{
			std::cout << "$" << monthlyInitialBal << "		";
		}
		
		if(monthlyInitialBal >= monthlyWithdraw)
		{
			std::cout << "	$" << monthlyWithdraw << "		";
		}
		else
		{
			std::cout << "	$" << monthlyInitialBal << "		";
		}		
		
		afterWithdraw = monthlyInitialBal - monthlyWithdraw;
		
		if(afterWithdraw < 0)
		{
			afterWithdraw = 0;
		}
		
		//based on the compound interest formula for a compound period n = 12. yearNumber increases each year. 
		//yearNumber was thought of as a source for the infinite loop but even if yearNumber = 1 always it still can
		//loop forever with high amounts
		monthlyInterest = (afterWithdraw * (std::pow((1.0 + interestOnPrincipal), (COMPOUND_PERIOD * yearNumber)))) - afterWithdraw;
		
		std::cout << "	$" << monthlyInterest << "	";
		
		newBalance = afterWithdraw + monthlyInterest;
		
		if(newBalance <= 0.0)
		{
			notBrokeYet = false;
			newBalance = 0.0;
		}
		
		std::cout << "	$" << newBalance << std::endl;
		
		monthlyInitialBal = newBalance;
		
		monthNumber++;
		monthsUntilBroke++;
		
		if(monthNumber > 12)
		{
			yearNumber++;
			currentYear++;
			monthNumber = 1;
		}

		//If statement to prevent infinite looping given a high interest causing the account to grow instead of decline
		if(monthlyInterest > monthlyWithdraw)
		{
			std::cout << "You're set for life, clearly this is a stable economic system.";
			std::cout << "Interest rate of growth is greater than your monthly withdrawal amount, feel free to spend more.";
			break;
		}
		
	}
	
	//if the loop ended because your balance = 0 then prints out the following statement. Otherwise the loop ended
	//because of an overflow 
	if(notBrokeYet == false)
	{
		std::cout << "You have " << monthsUntilBroke << " months before you need to panhandle down Colfax.";
	}
	
	return 0;
}