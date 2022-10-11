#include <iostream>
#define QUANTITY_OF_PLAYERS 5

int main()
{
	srand(time(NULL));


	int** a;
	

	int QuantityOfCommands = 0;
	std::cout << "Enter the quantity of commands: ";
	std::cin >> QuantityOfCommands;;
	a = new int* [QuantityOfCommands];


	for (int i(0); i < QuantityOfCommands; i++)
	{
		*(a + i) = new int[QUANTITY_OF_PLAYERS];
	}
	std::cout << std::endl;


	for (int i(0); i < QuantityOfCommands; i++)
	{
		for (int j(0); j < QUANTITY_OF_PLAYERS; j++)
		{
			*(*(a + i) + j) = rand() % 50;
		}
	}


	std::cout << "The results are: " << std::endl;
	for (int i(0); i < QuantityOfCommands; i++)
	{
		for (int j(0); j < QUANTITY_OF_PLAYERS; j++)
		{
			std::cout <<*(*(a+i)+j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	int* sum;
	sum = new int[QuantityOfCommands];
	for (int i(0); i < QuantityOfCommands; i++)
	{
		sum[i] = 0;
		for (int j(0); j < 5; j++)
		{
			sum[i] += *(*(a + i) + j);
		}
	}


	int max = 0, NumberOfCommand = 0;
	std::cout << "Winners are: " << std::endl;
	for (int i(0); i < 3; i++)
	{
		max = *(sum + 0);
		for (int j(0); j < QuantityOfCommands; j++)
		{
			if (*(sum + j) > max)
			{
				max = *(sum + j); 
				NumberOfCommand = j;
			}
		}
		std::cout << "Team " << NumberOfCommand << " result is: " << max << std::endl;
		max = 0;
		sum[NumberOfCommand] = 0;
	}
	
	delete[] sum;

	for (int i(0); i < NumberOfCommand; i++)
	{
		delete[]a[i];
	}
	delete[] sum;

	return 0;
}