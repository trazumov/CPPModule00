#include <iostream>
#include <cstring>

#include "../inc/ClassContact.hpp"

//--------------------------INDEX--------------------------//
void	Contact::set_index(int	index)
{
	this->index = index;
}
int		Contact::get_index(void)
{
	return this->index;
}
//--------------------------FIRST NAME--------------------------//
void	Contact::set_firstName(std::string	firstName)
{
	this->firstName = firstName;
}
std::string		Contact::get_firstName(void)
{
	return this->firstName;
}
//--------------------------LAST NAME--------------------------//
void	Contact::set_lastName(std::string	lastName)
{
	this->lastName = lastName;
}
std::string		Contact::get_lastName(void)
{
	return this->lastName;
}

//--------------------------NICKNAME--------------------------//
void	Contact::set_nickName(std::string	nickName)
{
	this->nickName = nickName;
}
std::string		Contact::get_nickName(void)
{
	return this->nickName;
}