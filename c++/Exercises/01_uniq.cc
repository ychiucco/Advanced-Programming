#include <iostream>
#include <string>


int main(int argc, char* argv[])
{
	std::string line, prev;
	int i = 0;
	while (std::getline(std::cin, line))
	{
		if (i == 0)
		{
			prev = line;
			++i;
			continue;
		}

		if (line == prev)
		{
			++i;
			continue;
		}
		else
		{
			std::cout << prev << " [" << i << "]" << std::endl;
			prev = line;
			i = 1;
			continue;
		}
	}
	if (i != 0)
	{
		std::cout << prev << " [" << i << "]" << std::endl;
	}

	return 0;
}