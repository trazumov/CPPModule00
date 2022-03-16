#include "../inc/phonebook.hpp"
#include <stdlib.h>

#include "../inc/ClassContact.hpp"
#include "../inc/ClassPhonebook.hpp"

// std::to_string придумали в C11. Быдлокодеры до С11:
 static void	printID(int id)
 {
	std::cout << "ID: " << g_nums[id] << std::endl;
 }

void	PhoneBook::init(void)
{
	this->setSize(0);
	this->add_index = 0;

	for (size_t index = 0; index < 8; index++)
	{
		this->Contacts[index].set_index(index);
		this->Contacts[index].set_firstName("Empty");
		this->Contacts[index].set_lastName("Empty");
		this->Contacts[index].set_nickName("Empty");
	}
}

void	PhoneBook::setSize(int newSize)
{
	this->size = newSize;
}
int		PhoneBook::getSize(void)
{
	return this->size;
}

// 1 is ERROR | 0 is OK
int		PhoneBook::showContactById(int id)
{
	if (id > this->size - 1 || id < 0)
	{
		std::cout << "Incorrect id of Contact" << std::endl;
		std::cout << "Insert command.." << std::endl;
		return 1;
	}
	printID(id);
	std::cout << "NAME: "<< this->Contacts[id].get_firstName() << std::endl;
	std::cout << "SURNAME: "<< this->Contacts[id].get_lastName() << std::endl;
	std::cout << "NICKNAME: "<< this->Contacts[id].get_nickName() << std::endl;
	
	std::cout << "Insert command.." << std::endl;
	return 0;
}

void	PhoneBook::addContact(void)
{
	std::string	input;
	
	if (this->size < 8)
		this->size++;
	if (this->add_index == 8)
		this->add_index = 0;

	std::cout << "Enter Name: ";
	std::cin >> input;
	this->Contacts[this->add_index].set_firstName(input);

	std::cout << "Enter Surname: ";
	std::cin >> input;
	this->Contacts[this->add_index].set_lastName(input);

	std::cout << "Enter Nickname: ";
	std::cin >> input;
	this->Contacts[this->add_index].set_nickName(input);
	
	std::cout << "Contact was added to Phonebook" << std::endl;

	this->add_index++;
}

static void print_str_alligned(std::string str)
{
	int	spaces;
	int	j;
	
	j = 0;
	spaces = 10 - str.length();
	if (spaces <= 0)
		spaces = 0;
	for (size_t i = 0; i < 9; i++)
	{
		if (spaces-- > 0)
			std::cout << " ";
		else
		{
			std::cout << str[j];
			j++;
		}
	}
	if (str.length() > 10)
		std::cout << ".";
	else
		std::cout << str[j];
	//std::cout << str;
}

static void print_row(PhoneBook *book, int row)
{
	std::string name =  book->Contacts[row].get_firstName();
	std::string lastname =  book->Contacts[row].get_lastName();
	std::string nickname =  book->Contacts[row].get_nickName();

	//printID(row); std::cout << "|";
	std::cout << g_nums[row] << "  |";
	print_str_alligned(name); std::cout << "|";
	print_str_alligned(lastname); std::cout << "|";
	print_str_alligned(nickname); std::cout << "|";
	
}

static int num_from_string(std::string s)
{
	return (s[0] - '0');
}

void	PhoneBook::search(void)
{
	std::string	input_id;
	int			num_id;	
	
	std::cout << "ID |";
	std::cout << "      Name|";
	std::cout << " Last Name|";
	std::cout << "  Nickname|" << std::endl;

	if (this->size != 0)
	{
		for (size_t row = 0; row < this->size; row++)
		{
			print_row(this, row);
			std::cout << std::endl;
		}
		std::cout << "Enter the ID to display\n";
	}
	else
	{
		std::cout << "Book is empty" << std::endl;
		std::cout << "Insert command.." << std::endl;
		return ;
	}

	std::cin >> input_id;
	if (input_id == "EXIT" || input_id == "exit")
	{
		std::cout << "Exit phonebook" << std::endl;
		std::exit (0);
	}
	num_id = num_from_string(input_id);
	if (num_id < 0 || num_id > 7)
	{
		std::cout << "Incorrect input\n";
		std::cout << "Insert command.." << std::endl;
	}
	else
		this->showContactById(num_id);
}