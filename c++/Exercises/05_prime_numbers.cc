#include <iostream>

int main()
{
	int n = 100;
	int m = n / 2 + 1;
	int* primes = new int[m];
	primes[0] = 2;
	int a = 1;
	bool prime = false;
	for (int i = 3; i <= n; ++i)
	{
		for (int j = 2; j < i; ++j)
		{
			if (!(i%j))
			{
				prime = false;
				break;
			}
			else
			{
				prime = true;
				continue;
			}
		}
		if (prime)
		{
			primes[a] = i;
			++a;
		}
	}
	for (int i = 0; i < a; ++i)
	{
		std::cout << primes[i] << "\t";
	}

	delete[] primes;

	return 0;
}