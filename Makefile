NAME		=	vector

C			=	clang++

C_FLAGS		= 	-Wall -Wextra -Werror -std=c++98

HEADERS		=	vector.hpp\
				stack.hpp\
				map.hpp\
				iterator.hpp\
				utils.hpp\
				tree.hpp
				
SRCS		=	main.cpp\

RM			= rm -f

$(NAME):	$(SRCS) $(HEADERS)
			$(C) $(C_FLAGS) $(SRCS) -o $@

all: 		$(NAME)

fclean: 	
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re