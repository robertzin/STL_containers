NAME		=	containers

C			=	clang++

C_FLAGS		= 	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

HEADERS		=	vector.hpp\
				stack.hpp\
				iterator.hpp\
				utils.hpp\
				node.hpp\
				tree.hpp\
				map.hpp

SRCS		=	main.cpp\

RM			= rm -f

$(NAME):	$(SRCS) $(HEADERS)
			$(C) $(C_FLAGS) $(SRCS) -o $@

all: 		$(NAME)

fclean:
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
