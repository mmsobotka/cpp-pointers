#include <iostream>

int* createTable(int n);
void printTab(int* wynik, const size_t rozmiar);
int getMaxElement(int* wynik, const size_t rozmiar);
int getNumberEvenElements(int* wynik, const size_t rozmiar);
void modifyTable1(int* wynik, const size_t rozmiar);
int sumOfTable(int* wynik, const size_t rozmiar);
int findMaxDiff(int* wynik, const size_t rozmiar);
int* createSumOfTables(int* tab1, int* tab2, const size_t rozmiar);
void removeElementFromTableAtIndex(int* wynik, size_t& rozmiar);
void swapFromConsoleInput(int* wynik, size_t rozmiar);
void setMaxMinIndex(int* wynik, size_t rozmiar, int& maxindeks, int& minindeks);
void bubbleSort(int* wynik, size_t rozmiar);
void swap(int& a, int& b);
int findMaxElement(int* wynik, size_t rozmiar, int iBegin);

int main()
{
	int maxindeks = 0;
	int minindeks = 0;
	size_t rozmiar = 1; //const size_t rozmiar = 10;
	int* tab1 = new int[rozmiar];
	int* tab2 = new int[rozmiar];

	//1. funkcja dostaje int n, tworzy n elementowa tablice z wartoœci¹ od 0 do n-1, ma zwróciæ tablice
	std::cout << "Podaj rozmiar tablicy: ";
	std::cin >> rozmiar;
	int* wynik = createTable(rozmiar);

	//2. funkcja wypisuje po spacji elementy tej tablice
	printTab(wynik, rozmiar);

	//3. funkcja zwracaj¹ca najwiêkszy element w tablicy
	int maxElement = getMaxElement(wynik, rozmiar);

	//4. funkcja zwracaj¹ca iloœæ elementów parzystych
	int evenElements = getNumberEvenElements(wynik, rozmiar);

	//5. funkcja pod indexami parzystymi zwiêksza wartoœæ o kwadrat
	modifyTable1(wynik, rozmiar);

	//6. funkcja liczy sumê tablicy
	int sum = sumOfTable(wynik, rozmiar);

	//7. funkcja zwracaj¹ca najwiêksz¹ ró¿nice pomiêdzy s¹siaduj¹cymi elementami
	int maxDiff = findMaxDiff(wynik, rozmiar);

	//8. funkcja dostaje dwie tablice i zwraca trzecia, która jest suma dwóch ( ka¿dy element z tab0 + ka¿dy element z tab1) pod odpowiednimi indeksami
	int* sumTab = createSumOfTables(tab1, tab2, rozmiar);

	//9. funkcja usuwa element tablicy pod wybranym indeksem
	removeElementFromTableAtIndex(wynik, rozmiar);

	//10. funkcja dostaje tablice, dwa indeksy i zamienia elementy pod tymi indeksami (swap)
	swapFromConsoleInput(wynik, rozmiar);

	//11. funkcja dostaje tablice i musi jakoœ zwróciæ informacje o indeksie max i min elementu w tej tablicy
	setMaxMinIndex(wynik, rozmiar, maxindeks, minindeks);

	//12*. funkcja sortuj¹ca ta tablice dowolnym algorytmem
	bubbleSort(wynik, rozmiar);

	//15. usuwanie pamiêci dla tablicy
	delete[] wynik;
	delete[] sumTab;
	delete[] tab1;
	delete[] tab2;
}

int* createTable(int n)
{
	int* tab = nullptr;
	tab = new int[n]; // int* tab= new int[n];

	for (int i = 0; i < n; i++)
	{
		tab[i] = i;
		//tab[i] = (i * 4) % 7;
		//*(tab + i) = i;
	}
	return tab;
}

void printTab(int* wynik, const size_t rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		std::cout << wynik[i] << " ";
	}
	std::cout << std::endl;
}

int getMaxElement(int* wynik, const size_t rozmiar)
{
	int extremeElement = wynik[0];
	for (int i = 0; i < rozmiar; i++)
	{
		if (extremeElement < wynik[i])
		{
			extremeElement = wynik[i];
		}
	}
	std::cout << "Najwiekszy element tablicy: " << extremeElement;
	return extremeElement;
}

int getNumberEvenElements(int* wynik, const size_t rozmiar)
{
	int ilosc = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		if (wynik[i] % 2 == 0)
		{
			ilosc++;
		}
	}
	std::cout << std::endl;
	std::cout << "Ilosc elementow parzystych w tablicy: " << ilosc << std::endl;
	return ilosc;
}

void modifyTable1(int* wynik, const size_t rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		if (i % 2 == 0)
		{
			wynik[i] = i * i;
		}
	}
	std::cout << "Parzyste elementy w tablicy zwiekszone o kwadrat " << std::endl;
	printTab(wynik, rozmiar);
}

int sumOfTable(int* wynik, const size_t rozmiar)
{
	int suma = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		suma += wynik[i];
	}
	std::cout << "Suma elementow tablicy: " << suma << std::endl;
	return suma;
}

int findMaxDiff(int* wynik, const size_t rozmiar)
{
	int porownanie = 0;
	int max = 0;
	for (int i = 0; i < rozmiar - 1; i++)
	{
		porownanie = wynik[i + 1] - wynik[i];
		if (max < porownanie)
		{
			max = porownanie;
		}
	}
	std::cout << "Najwieksza roznica pomiedzy elementami: " << max << std::endl;
	return max;
}

int* createSumOfTables(int* tab1, int* tab2, const size_t rozmiar)
{
	int* tab3 = new int[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		tab3[i] = tab1[i] + tab2[i];
	}
	printTab(tab3, rozmiar);
	return tab3;
}

void removeElementFromTableAtIndex(int* wynik, size_t& rozmiar)
{
	int pickElement = 0;
	std::cout << "Wybierz numer elementu ktory chcesz usunac: " << std::endl;
	std::cin >> pickElement;
	if (pickElement > rozmiar)
	{
		std::cout << "Numer elementu jest spoza rozmiaru tablicy";
	}
	else
	{
		for (int i = 0; i < rozmiar - 1; i++)
		{
			if (i >= pickElement)
			{
				wynik[i] = wynik[i + 1];
			}
		}
		rozmiar = rozmiar - 1;
	}
	printTab(wynik, rozmiar);
}

void swapFromConsoleInput(int* wynik, size_t rozmiar)
{
	unsigned int indeks1 = 0;
	unsigned int indeks2 = 0;
	int temp = 0;

	std::cout << "Jakie elementy chcesz ze soba zamienic?" << std::endl;
	std::cin >> indeks1;
	std::cin >> indeks2;


	if (indeks1 > rozmiar || indeks2 > rozmiar)
	{
		std::cout << "Bledne elementy";
	}
	else
	{
		temp = wynik[indeks1];
		wynik[indeks1] = wynik[indeks2];
		wynik[indeks2] = temp;

		printTab(wynik, rozmiar);
	}
}

void setMaxMinIndex(int* wynik, size_t rozmiar, int& maxindeks, int& minindeks)
{
	int max = 0;
	int min = 0;

	for (int i = 0; i < rozmiar; i++)
	{
		if (max < wynik[i])
		{
			max = wynik[i];
			maxindeks = i;
		}
		if (min > wynik[i])
		{
			min = wynik[i];
			minindeks = i;
		}
	}
}

void bubbleSort(int* wynik, size_t rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		//13* funkcja dostaje tablice (zwróci trzy parametry, zastanów siê jak), najwiêksza ró¿nice pomiêdzy s¹siadami i indeksy tych dwóch parametrów
		int maxindeks = findMaxElement(wynik, rozmiar, i);

		//14. funkcja swap
		swap(wynik[i], wynik[maxindeks]);
	}
	printTab(wynik, rozmiar);
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int findMaxElement(int* wynik, size_t rozmiar, int iBegin)
{
	int max = wynik[iBegin];
	int maxIndeks = iBegin;

	for (int i = iBegin + 1; i < rozmiar; i++)
	{
		if (max < wynik[i])
		{
			max = wynik[i];
			maxIndeks = iBegin;
		}
	}
	return maxIndeks;
}