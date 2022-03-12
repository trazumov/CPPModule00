NAME		= phonebook
SRCS		= src/ClassContact.cpp \
			src/ClassPhonebook.cpp \
			src/phonebook.cpp
			
CC			= clang++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re