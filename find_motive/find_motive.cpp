#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
	if (argc != 3)
	{
		return 1;
	}

	std::ifstream file;
	file.open(argv[1]);
	if (file.fail()) {
		std::cout << "The file " << argv[1] << " could not be opened.\n";
		return 1;
	}
	std::string word;
	int k = 0;
	while (file >> word)
	{
		if (word.find(argv[2]) != std::string::npos)
		{
			k++;
		}
	}
	std::cout << "The file " << argv[1] << " contains " << k << " words containing the motive " << argv[2] << "\n";
	return 0;

}
