OBJS	:=	$(patsubst %.cpp, %.o, $(shell find src -type f -name "*.cpp"))

INCLUDE	=	include

HFILE	=	$(wildcard $(INCLUDE)/*.hpp)

NAME	=	abstrakt

INC_FLAG	=	-I $(INCLUDE) -g3 -Weverything -Wno-gnu -march=native -Wno-c++98-compat -Wno-padded -Wnon-virtual-dtor -Wno-weak-vtables

OBJ_FLAG	=	-g3 -Weverything -Wno-gnu -march=native

DEBUG_FLAGS	=	-O0

CC	=	@clang++
RM	=	@rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(OBJ_FLAG)

$(OBJS): $(HFILE)

debug: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(OBJ_FLAG) $(DEBUG_FLAGS)

clean:
	@$(RM) $(OBJS)
	@printf "\033[32m[  DONE  ]\033[0m  Cleanned *o\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[32m[  DONE  ]\033[0m  Cleanned $(NAME)\n"

re:	fclean all

.cpp.o:	%.c
	@$(CC) -c $< -o $@ $(INC_FLAG) && printf "\033[32m[  DONE  ]\033[0m  $< \n\e[0m" || printf "\033[91;5m[  FAIL  ]\033[25m  $< \n\e[0m"

.PHONY: all clean fclean re