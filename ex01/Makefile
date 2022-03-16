NAME		= phonebook

OBJS =		$(SRCS:.c=.o)

SRCS		= src/ClassContact.cpp \
			src/ClassPhonebook.cpp \
			src/phonebook.cpp
			
CC			= clang++
#CFLAGS		= -Wall -Wextra -Werror -std=c++98
CFLAGS		=  -g -std=c++98

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re