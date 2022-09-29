//file HelloWorld.cpp
#include <iostream>
#include <string>

int main()
{
	std::string name; //stores user name
	char weather; //stores todays weather 
	int dayNumber; //stores todays day as a number with 0 = sunday 6 = saturday
	std::string day; //stores the actual day based on the dayNumber entry
	std::string activity; //activity based on weather and day
	
	//take user input
	std::cout << "Please enter your name: ";
	std::cin >> name;
	
	std::cout << "Please enter today's weather [S]unny, [R]ainy, [W]indy: ";
	std::cin >> weather;
	
	std::cout << "Please enter today's day as a number [Sunday:0..Saturday:6]: ";
	std::cin >> dayNumber;
	
	//check what day was entered numerically and convert it to a string of the actual day 
	if(dayNumber == 0)
	{
		day = "Sunday";
	}
	else if(dayNumber == 1)
	{
		day = "Monday";
	}
	else if(dayNumber == 2)
	{
		day = "Tuesday";
	}
	else if(dayNumber == 3)
	{
		day = "Wednesday";
	}
	else if(dayNumber == 4)
	{
		day = "Thursday";
	}
	else if(dayNumber == 5)
	{
		day = "Friday";
	}
	else
	{
		day = "Saturday";
	}
	
	/*check what letter was entered for the weather then check what dayNumber was entered.
	Based on these values set the activity appropriately*/
	
	if(weather == 'S')
	{
		if(dayNumber == 0 || dayNumber == 6)
		{
			activity = "go hiking";
		}
		else
		{
			activity = "play tennis";
		}
	}
	else if(weather == 'R')
	{
		if(dayNumber == 0 || dayNumber == 6)
		{
			activity = "go bowling";
		}
		else
		{
			activity = "stay home";
		}
	}
	else if(weather == 'W')
	{
		if(dayNumber == 0 || dayNumber == 6)
		{
			activity = "go hang-gliding";
		}
		else
		{
			activity = "fly a kite";
		}
	}
	
	std::cout << "Hello " << name << "! You may " << activity << " on " << day << "." << std::endl;
	
	return 0;
}