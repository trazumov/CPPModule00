#include "../inc/phonebook.hpp"

#include "../inc/ClassContact.hpp"
#include "../inc/ClassPhonebook.hpp"

static int input_is_correct(std::string input)
{
	int i = 0;
	if (input == "")
		return FALSE;
	while (1)
	{
		if (i == 6)
			return FALSE;
		if (g_cmds[i] == input)
			break ;
		i++;
	}
	i = 0;
	while (input[i])
	{
		if (input[i] == '\n')
			return FALSE;
		i++;
	}
	return TRUE;
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
	while (input != "EXIT" && input != "exit")
	{
		std::cout << "Insert command.." << std::endl;
		getline(std::cin, input);
		if (!input_is_correct(input))
		{
			showhint();
			continue ;
		}
		if (input == "ADD" || input == "add")
			Book.addContact();
		else if (input == "SEARCH" || input == "search")
			Book.search();
	}
	std::cout << "Exit phonebook" << std::endl;
	return 0;
}