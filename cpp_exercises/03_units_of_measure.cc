#include <iostream>

int main()
{
	int conv{ 2 };
	std::cout << "Da che formato si vuole convertire?\n(digitare il numero corrispondente seguito da INVIO)\n0 --> da pollici a metri\n1 --> da metri a pollici" << std::endl;
	while (conv != 0 && conv != 1)
	{
		std::cin >> conv;
		if (std::cin.fail())
		{
			std::cout << "Errore!\nPremere INVIO qualche volta" << std::endl;
			std::cin.clear();
			std::cin.ignore(256);
			std::cout << "Perfavore digitare un numero valido (0 o 1)" << std::endl;
			continue;
		}
	}

	float unit{ 0 };
	std::cout << "Quante unita' vuoi convertire?\n(digitare il numero seguito da INVIO)\n";
	while (!(std::cin >> unit))
	{
		std::cout << "Errore!\nPremere INVIO qualche volta" << std::endl;
		std::cin.clear();
		std::cin.ignore(256);
		std::cout << "Perfavore digitare un numero valido: " << std::endl;
	}

	switch (conv)
	{
	case(0):
		std::cout << unit << " pollici corrispondono a " << unit * 0.0254 << " metri" << std::endl;
	case(1):
		std::cout << unit << " metri corrispondono a " << unit / 0.0254 << " pollici" << std::endl;
	default:
		std::cout << "ERROR" << std::endl;
		return -1;
	}

	return 0;
}