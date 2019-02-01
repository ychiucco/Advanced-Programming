#include <iostream>
#include <array>
#include <iomanip>

template<std::size_t SIZE>
std::array<double, SIZE> matrix_transpose(int n_row, int n_col, std::array<double, SIZE> M);

template<std::size_t SIZE>
void print_matrix(int n_row, int n_col, std::array<double, SIZE>& M);

void matrix_traspose_example();

int main()
{
	matrix_traspose_example();
	return 0;
}

template<std::size_t SIZE>
std::array<double, SIZE> matrix_transpose(int n_row, int n_col, std::array<double, SIZE> M)
{
	std::array<double, SIZE> T;

	for (int i = 0; i < n_row; ++i)
		for (int j = 0; j < n_col; ++j)
		{
			T[n_row*j + i] = M[n_col*i + j];
		}

	return T;
}

template<std::size_t SIZE>
void print_matrix(int n_row, int n_col, std::array<double, SIZE>& M)
{
	for (int i = 0; i < n_row; ++i)
	{
		for (int j = 0; j < n_col; ++j)
		{
			std::cout << std::setw(10) << M[n_col * i + j];
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
	return;
}

void matrix_traspose_example()
{
	std::array<double, 15> M;
	std::array<double, 15> T;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 5; ++j)
		{
			M[5 * i + j] = 1.15 + 1.15*j + 5 * 1.15*i;

		}

	std::cout << "Proviamo ad utilizzare la funzione sulla seguente matrice:\n\n";
	print_matrix(3, 5, M);

	T = matrix_transpose(3, 5, M);
	std::cout << "\n\nEd ecco la trasposta:\n\n";
	print_matrix(5, 3, T);

	return;
}