#include <iostream>
#include <string>
#include <algorithm>

void get_int();
void get_double();


int main()
{
	std::cout << "GET_INT\n\n";
	get_int();

	std::cout << "GET_DOUBLE\n\n";
	get_double();

	return 0;
}

void get_int()
{
	std::string input;
	std::cout << "Inserire un numero intero e premere INVIO:\t";
	while (std::getline(std::cin, input))
	{
		if (input.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Errore! Premere INVIO per ripetere..." << std::endl;
			std::cin.clear();
			std::cin.ignore(128, '\n');
			std::cout << "Inserire un numero intero e premere INVIO:\t" << std::endl;
			continue;
		}
		else
		{
			std::cout << "\nIl numero inserito e' " << input << std::endl;
			return;
		}
	}

}

void get_double()
{
	std::string input;
	
	std::cout << "\nInserire un numero double e premere INVIO:\t";

	while (std::getline(std::cin, input))
	{

		if (input.find_first_not_of("0123456789.") != std::string::npos || std::count(input.begin(), input.end(), '.') > 1)
		{
			std::cout << "Errore! Premere INVIO per ripetere..." << std::endl;
			std::cin.clear();
			std::cin.ignore(128, '\n');
			std::cout << "Inserire un numero double e premere INVIO:\t";
			continue;
		}
		else
		{
			std::cout << "\n\nIl numero inserito e' " << input << std::endl;
			return;
		}
	} 

}