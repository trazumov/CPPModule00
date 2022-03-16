#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

# include "ClassContact.hpp"

class PhoneBook
{
	private:
		// количество занесенных пользователем Контактов
		int		size;

	public:
		// просто тестирование что она может быть и
		// public
		int		add_index;
		Contact Contacts[8];

		void	init(void);
		void	setSize(int newSize);
		int		getSize(void);

		void	addContact(void);
		void	search(void);
		int		showContactById(int id);
};

#endif