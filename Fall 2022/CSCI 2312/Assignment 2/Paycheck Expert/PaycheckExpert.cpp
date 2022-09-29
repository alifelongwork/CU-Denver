#include <iostream>

int main()
{
	//constant variables used for wage and deduction calculations
	const int WEEKLY_HOUR_CAP = 40;
	const int WEEKS_PER_YEAR = 52;
	const float OVERTIME_RATE = 1.5;
	
	const int SOC_SEC_CAP = 137000;	
	const float SOC_SEC_TAX_RATE = 0.062;
	
	const float MEDICARE_TAX_RATE = 0.0145;
	
	const float FIRST_TAX_BRACKET_CAP = 9875.00;
	const float FIRST_TAX_RATE = 0.10;
	
	const float SECOND_TAX_BRACKET_CAP = 54125.00;
	const float SECOND_BRACKET_WEEKLY_TAX = 987.00;
	const float SECOND_TAX_RATE = 0.12;
	
	const float THIRD_TAX_BRACKET = 54126.00;
	const float THIRD_BRACKET_WEEKLY_TAX = 6297.00;
	const float THIRD_TAX_RATE = 0.22;

	const float CO_STATE_TAX_RATE = 0.0455;
	
	//mutable variables that are used to store calculations
	float hourlyRate;
	int weeklyHours;
	double weeklyRetirement;
	
	std::cout << "Please enter your hourly rate: ";
	std::cin >> hourlyRate;
	
	std::cout << "How many hours did you work this week? ";
	std::cin >> weeklyHours;
	
	std::cout << "How much would you like to put towards retirement each week? ";
	std::cin >> weeklyRetirement;
	
	int overTimeHours = 0;
	//checking for overtime and calculating hours
	if(weeklyHours > WEEKLY_HOUR_CAP)
	{
		overTimeHours = weeklyHours - WEEKLY_HOUR_CAP;
		weeklyHours  = WEEKLY_HOUR_CAP;
	}
	
	float regPay = weeklyHours * hourlyRate;
	float overTimePay = 0;
	
	if(overTimeHours > 0)
	{
		overTimePay = overTimeHours * OVERTIME_RATE * hourlyRate;
	}
	
	//calculating pay based on hours worked and rate
	float weeklyGross = regPay + overTimePay;
	float annualGross = weeklyGross * WEEKS_PER_YEAR;
	
	//calculating deductions
	float socSec = 0;
	if(annualGross > SOC_SEC_CAP)
	{
		socSec = SOC_SEC_TAX_RATE * SOC_SEC_CAP / WEEKS_PER_YEAR;
	}
	else
	{
		socSec = SOC_SEC_TAX_RATE * weeklyGross;
	}
	
	float mediCare = MEDICARE_TAX_RATE * weeklyGross;
	
	float fedTax = 0.0;
	
	if(annualGross < FIRST_TAX_BRACKET_CAP)
	{
		fedTax = FIRST_TAX_RATE * weeklyGross;
	}
	else if(annualGross <= SECOND_TAX_BRACKET_CAP)
	{
		fedTax = (SECOND_BRACKET_WEEKLY_TAX/WEEKS_PER_YEAR) + SECOND_TAX_RATE * (weeklyGross - (FIRST_TAX_BRACKET_CAP/WEEKS_PER_YEAR));
	}
	else if(annualGross >= THIRD_TAX_BRACKET)
	{
		fedTax = (THIRD_BRACKET_WEEKLY_TAX/WEEKS_PER_YEAR) + THIRD_TAX_RATE * (weeklyGross - (SECOND_TAX_BRACKET_CAP/WEEKS_PER_YEAR));
	}
	float coStateTax = CO_STATE_TAX_RATE * weeklyGross;
	
	float totalDeductions = socSec + mediCare + fedTax + coStateTax + weeklyRetirement;
	
	//calculating net pay
	float netPay = weeklyGross - totalDeductions;
	
	//formatting decimals
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(2);
	
	//pay stub output with some formatting
	std::cout << "This week wage details: \n";
	std::cout << "======================= \n";
	std::cout << "Gross pay: $" << weeklyGross << " (Overtime pay: $" << overTimePay << ")\n";
	std::cout << std::endl;
	std::cout << "Taxes and deductions: \n";
	std::cout << "====================== \n";
	std::cout << "Social security withdrawal: $" << socSec << std::endl;
	std::cout << "Medicare withdrawal: $" << mediCare << std::endl;
	std::cout << "Federal Tax: $" << fedTax << std::endl;
	std::cout << "Colorado State Tax: $" << coStateTax << std::endl;
	std::cout << "Retirement contribution: $" << weeklyRetirement << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------- \n";
	std::cout << "Deduction total: $" << totalDeductions << std::endl;
	std::cout << "---------------------------- \n";
	std::cout << "Net Pay: $" << netPay;
	
	return 0;
}
