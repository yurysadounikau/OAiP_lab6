

#include <iostream>

int main()
{
	int* a;


	int size = 0;
	std::cout << "Enter massive size: ";
	std::cin >> size;
	std::cout << std::endl;


	a = new int[size];

	
	for (int i = 0; i < size; i++)
	{
		std::cin >> *(a + i);
	}

	

	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(a + i) > 0)
		{
			k++;
		}
	}


	std::cout << "The massive looks like this: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << *(a + i)<<" ";
	}
	std::cout << std::endl;



	int n_last = 0;
	for (int i = 0; i < size; i++)
	{
		if (*(a + i) == 0)
		{
			n_last = i;
		}
	}

	
	int sum = 0;
	for (n_last; n_last<size; n_last++)
	{
		sum += *(a + n_last);
	}


	std::cout << "The quantity of positive array elements is: ";
	std::cout << k;
	std::cout << std::endl;


	std::cout << "The sum of array elements situated after last zero: ";
	std::cout << sum;
	std::cout << std::endl;


	delete[] a;
	return 0;
}