#include <iostream>
#include <cmath>

int main()
{
	int n = 0;
	std::cout << "Fino a che numero vuoi cercare i primi? ";
	while (!(std::cin >> n) || n < 2)
	{
		std::cin.clear();
		std::cin.ignore(128, '\n');
		std::cout << "ERRORE. Inserire un numero intero maggiore di 1 e premere invio: ";
	}

	bool* A = new bool[n - 1];
	for (int i = 0; i < n - 1; ++i)
	{
		A[i] = true;
	}

	for (int i = 0; i + 2 <= std::sqrt(n); ++i)
	{
		if (A[i])
		{
			for (int j = (i + 2) * (i + 2) - 2; j < n; j += (i + 2))
				A[j] = false;
		}
	}

	std::cout << "I numeri primi da 2 a " << n << " sono:" << std::endl;
	for (int i = 0; i + 2 < n; ++i)
	{
		if (A[i])
			std::cout << i + 2 << "\t";
	}

	return 0;
}