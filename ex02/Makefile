NAME = ex02
CC =  c++ -Wall -Wextra -Werror -std=c++98 
RM = rm -rf
FILE = main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJ = $(FILE:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $@

%.o : %.cpp Base.hpp A.hpp B.hpp C.hpp
	$(CC) -c $< -o $@ 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all	