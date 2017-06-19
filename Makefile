FILE = *.cpp
NAME = snake
CC = clang++
CFLAGS = -Wall -Werror -Wextra

all: clean
	@echo "Compiling code!"
	@$(CC) $(CFLAGS) -o $(NAME) $(FILE)
	@echo "It's happening.. it's happening!"

clean:
	@rm -rf $(NAME)