#include <iostream>

template <typename T>
T* heap_allocation(int& n)
{
	T* n_array = new T[n]{};
	
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Inserire l'elemento numero " << i+1 << " dell'array e premere INVIO:\t";
		std::cin >> n_array[i];
	}
	
	return n_array;
}

template <typename T>
void reverse_print(T* arr, int& n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[n-1-i] << "\t";
	}
	return;
}

int main()
{
	int n;
	do
	{
       std::cout << "Quanti elementi conterrà il tuo array? ";
	   std::cin >> n;
	} while (n < 1);
	

	bool type;
	std::cout << "\nScegli cosa vuoi inserire:\n0 --> int\n1 --> double\n";
	std::cin >> type;

	if (!type)
	{
		int* ptr = heap_allocation<int>(n);
		std::cout << "\nAl contrario" << std::endl;
		reverse_print<int>(ptr, n);
		delete[] ptr;
	}
	else
	{
		double* ptr = heap_allocation<double>(n);
		std::cout << "\nEcco l'array stampato al contrario" << std::endl;
		reverse_print<double>(ptr, n);
		delete[] ptr;
	}
		
	return 0;
}