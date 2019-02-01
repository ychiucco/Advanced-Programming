#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

int main()
{
	double v{ 0 };
	double total{ 0 };
	std::vector<double> values;
	std::ifstream myFile;


	myFile.open("temperatures.txt");


	if (!(myFile.is_open()))
	{
		std::cerr << "There was a problem opening the input file!\n";
		exit(0);
	}

	while (myFile >> v)
	{
		total += v;
		values.push_back(v);
	}

	int size = values.size();

	double mean = total / size;
	std::cout << "La media delle temperature misurate e' " << mean << std::endl;

	std::sort(std::begin(values), std::end(values));

	double median;

	if (size % 2 != 0)
	{
		median = values[(size - 1) / 2];
	}
	else
	{
		median = (values[size / 2] + values[(size / 2) - 1]) / 2;
	}
	std::cout << "La mediana delle temperature misurate e' " << median << std::endl;

	return 0;
}