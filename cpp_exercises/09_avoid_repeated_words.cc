#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::string> bag;
	std::cout << "Inserire parole e premere INVIO.\n\n";

	std::string word;
	while (std::cin >> word)
	{
		bag.push_back(word);
	}
	std::sort(bag.begin(), bag.end());

	std::vector<std::string>::iterator it = bag.begin();

	do
	{
		if (it == bag.begin() || *it != *(it - 1)) { std::cout << *it << "\t"; }
		++it;		
	} while (it != bag.end());

	return 0;
}
