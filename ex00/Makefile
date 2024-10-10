NAME 		=	Animal
CXX 		=	clang++
CPPFLAGS 	=	-Wall -Wextra -Werror -MMD -g3 -std=c++98 -gdwarf-4
SRC_PATH	=	src/
OBJ_PATH	=	.obj/
SRC_NAME	=	main.cpp \
				Animal.cpp \
				Cat.cpp \
				Dog.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp
OBJ_NAME	=	$(SRC_NAME:.cpp=.o) 
OBJ 		=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC 		=	$(addprefix $(SRC_PATH), $(SRC_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CPPFLAGS) -o $@ -c $<

-include $(OBJ:%.o=%.d)

clean:
	rm -rf .obj

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) -s fclean all

.PHONY: all clean fclean re
