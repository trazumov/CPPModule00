#include <iostream>
#include <cstring>

#include "../inc/ClassContact.hpp"
#include "../inc/ClassPhonebook.hpp"

// std::to_string придумали в C11. Быдлокодеры до С11:
 static void	printID(int id)
 {
	std::cout << "ID: " << std::endl;
	id = 0;
 }

void	PhoneBook::init(void)
{
	this->size = 0;
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
	if (id > this->size || id < 0)
	{
		std::cout << "Incorrect id of Contact" << std::endl;
		return 1;
	}
	printID(id);
	std::cout << "NAME: "<< this->Contacts[id].get_firstName() << std::endl;
	std::cout << "SURNAME: "<< this->Contacts[id].get_lastName() << std::endl;
	std::cout << "NICKNAME: "<< this->Contacts[id].get_nickName() << std::endl;
	
	return 0;
}

void	PhoneBook::addContact(void)
{
	std::string	input;

	std::cout << "Enter Name: ";
	std::cin >> input;
	this->Contacts[this->getSize()].set_firstName(input);

	std::cout << "Enter Surname: ";
	std::cin >> input;
	this->Contacts[this->getSize()].set_lastName(input);

	std::cout << "Enter Nickname: ";
	std::cin >> input;
	this->Contacts[this->getSize()].set_nickName(input);

	if (this->getSize() < 7)
		this->setSize(this->getSize() + 1);
	
	std::cout << "Contact was added to Phonebook" << std::endl;
}