#include <iostream>

int main()
{
	srand(time(NULL));
	int** matrix;


	int size(0);
	std::cout << "Enter massive size: ";
	std::cin >> size;
	std::cout << std::endl;


	matrix = new  int*[size];
	for (int i = 0; i < size; i++)
	{
		*(matrix + i) = new int[size];
	}
	

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			*(*(matrix + i) + j) = size * size - rand() % (size * size * 2);
		}
	}
	

	for (int i(0); i < size; i++)
	{
		for (int j(0); j < size; j++)
		{
			std::cout << *(*(matrix + i) + j) << "\t";
		}
		std::cout << std::endl;
	}


	bool AtleastOneBelowZero = false;
	for (int i(0); i < size; i++)
	{
		for (int j(0); j < size; j++)
		{
			if (*(*(matrix + i) + j) < 0)
			{
				AtleastOneBelowZero = true;
				j = size;
			}
		}
		if (!AtleastOneBelowZero)
		{
			int sum = 0;
			for (int j(0); j < size; j++)
			{
				sum += *(*(matrix + i) + j);
			}
			int z = i + 1;
			std::cout << "The sum of row " << z << " is: " << sum << std::endl;
		}
		AtleastOneBelowZero = false;
	}


	int minimal_sum = *(*(matrix)+size - 1);
	for (int i(1); i < size; i++)
	{
		int value_1(0), value_2(0);
		for (int j(0); j < size - i; j++)
		{
			value_1 += *(*(matrix + i + j) + j);
			value_2 += *(*(matrix + j) + i + j);
		}
		if (value_1 < minimal_sum)
		{
			minimal_sum = value_1;
		}
		if (value_2 < minimal_sum) 
		{
			minimal_sum = value_2;
		}
	}


	std::cout << "The minimal sum is: " << minimal_sum;


	for (int i(0); i < size; i++)
	{
		delete[]matrix[i];
	}
	return 0;
}