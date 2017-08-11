FILE = src/fnake.cpp src/food.cpp src/game.cpp src/main.cpp src/object.cpp src/overflow.cpp
NAME = snake
CC = g++
CFLAGS = -Wall -Werror -Wextra

all:
	@make -C GUIs/lib1/ re
	@make -C GUIs/lib2/ re
	@make -C GUIs/lib3/ re
#	@g++ -shared -fPIC -o lib1.so lib.cpp -lncurses
	@echo "Compiling code!"
	@$(CC) $(CFLAGS) -o $(NAME) $(FILE)
	@echo "It's happening.. it's happening!"

clean:
	@rm -rf $(NAME)
	@make -C GUIs/lib1/ clean
	@make -C GUIs/lib2/ clean
	@make -C GUIs/lib3/ clean

fclean: clean
	@make -C GUIs/lib1/ fclean
	@make -C GUIs/lib2/ fclean
	@make -C GUIs/lib3/ fclean

re: fclean all