NAME = lib2.so

CFLAGS = -std=c++11 -Wno-deprecated-declarations -O3

CFLAGS2 = -framework OpenGL -framework GLUT -O3 -ltermcap \
		  -Wno-deprecated-declarations

CFLAGS3 = -shared -fPIC

SRCS = lib.cpp

CC = g++

LIBRARY = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(CFLAGS2) $(CFLAGS3) -o ../../$(NAME) $(SRCS) $(LIBRARY)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f ../../$(NAME)

re: fclean all

.PHONY: clean fclean re
