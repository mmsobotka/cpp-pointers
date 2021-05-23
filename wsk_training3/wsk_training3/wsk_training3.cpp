#include <iostream>

int** createDynamicTab2Dims(int a, int b)
{
	int** tab = new int* [a];

	for (int i = 0; i < a; i++)
	{
		tab[i] = new int[b];
	}
	return tab;
}

void fillData(int a, int b, int** tab)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			tab[i][j] = (i + 1) * (j + 1);
		}
	}
}

void printData(int a, int b, int** tab)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			std::cout << tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void freeData(int a, int** tab)
{
	for (int i = 0; i < a; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}


int main()
{
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	int** resultTab = createDynamicTab2Dims(a, b);
	fillData(a, b, resultTab);
	printData(a, b, resultTab);
	freeData(a, resultTab);
}
