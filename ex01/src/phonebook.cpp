#include "../inc/phonebook.hpp"

static int input_is_correct(std::string input)
{
	int i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			return 0;
		i++;
	}
	return 1;
}

static void showhint(void)
{
	std::cout << "The command is incorrect. List of commands: ADD / SEARCH / EXIT" \
	<< std::endl;
	std::cout << "Line break unavailable too." << std::endl;
}

int main(void)
{
	std::string	input;
	PhoneBook	Book;

	Book.init();
	std::cout << "Insert command..\n";
	while (input != "EXIT")
	{
		std::cin >> input;
		if (!input_is_correct(input))
		{
			showhint();
			continue ;
		}
		if (input == "ADD" || input == "add")
			Book.addContact();
		else if (input == "SEARCH" || input == "search")
			Book.search();
		//else if (input == "SHOW" || input == "show")
		//	Book.showContactById(0);
		else
			showhint();
	}

	std::cout << "Exit phonebook" << std::endl;
	return 0;
}