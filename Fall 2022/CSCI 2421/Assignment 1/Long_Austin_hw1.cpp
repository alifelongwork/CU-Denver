#include <iostream>

int findSum(int a[], int size);

int main()
{
	int n;
	std::cout << "Please enter the size of the array: ";
	std::cin >> n;
	
	int *array = new int[n];
	
	std::cout << "Please enter the values of the array: " << std::endl;
	
	for(int i = 0; i < n; i++)
	{
		std::cin >> array[i];
	}
	
	std::cout << "The sum of the values in the array is " << findSum(array, n) << std::endl;
	
	return 0;
}

int findSum(int a[], int size)
{
	if(size == 1)
	{
		return a[0];
	}
	
	return a[size - 1] + findSum(a, size - 1);
}