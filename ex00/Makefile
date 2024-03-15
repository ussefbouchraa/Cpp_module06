NAME = ex00
CC =  c++ -Wall -Wextra -Werror -std=c++98 
RM = rm -rf
FILE = main.cpp ScalarConverter.cpp
OBJ = $(FILE:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $@

%.o : %.cpp ScalarConverter.hpp
	$(CC) -c $< -o $@ 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all	