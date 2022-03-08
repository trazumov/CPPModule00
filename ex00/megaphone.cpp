#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	int i = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (argv[i])
		{
			for (unsigned int j = 0; j < strlen(argv[i]); j++)
				argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i];
			i++;
		}
	}
	std::cout << "\n";
	return 0;
}