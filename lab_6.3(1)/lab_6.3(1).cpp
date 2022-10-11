#include <iostream>
int main()
{
	int** a;
	
	int size = 0;
	std::cout << "Enter size: ";
	std::cin >> size;

	a = new int* [size];

	for (int i(0); i < size; i++)
	{
		*(a+i) = new int[size];
	}

	std::cout << "Enter data in matrix: ";
	for (int i(0); i < size; i++)
	{
		for (int j(0); j < size; j++)
		{
			std::cin >> *(*(a+i)+j);
		}
	}


	int k = 0;
	for (int i(0); i < size; i++)
	{
		for (int j(i + 1); j < size; j++)
		{
			if (*(*(a + i) + j) == *(*(a + j) + i))
			{
				k++;
			}
		}
	}

	if (k == 0)
	{
		std::cout << "Not symmetrical";
	}
	else
	{
		std::cout << "Symmetrical";
	}

	for (int i(0); i < size; i++)
	{
		delete[]a[i];
	}
	return 0;
}
