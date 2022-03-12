#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

# include "ClassContact.hpp"

class PhoneBook
{
	private:
		Contact Contacts[8];
		int		size; // количество занесенных пользователем Контактов
	
	public:
		void	init(void);
		void	setSize(int newSize);
		int		getSize(void);

		void	addContact(void);
		void	search(void);
		int		showContactById(int id);
};

#endif