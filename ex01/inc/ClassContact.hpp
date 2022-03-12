#ifndef CLASS_CONTACT_HPP
#define CLASS_CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		int				index;
		std::string		firstName;
		std::string		lastName;
		std::string		nickName;
	
	public:
		void			set_index(int				index);
		int				get_index(void);

		void			set_firstName(std::string	firstName);
		std::string		get_firstName(void);

		void			set_lastName(std::string	lastName);
		std::string		get_lastName(void);

		void			set_nickName(std::string	nickName);
		std::string		get_nickName(void);
};

#endif