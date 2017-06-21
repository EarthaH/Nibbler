NAME = lib1

CFLAGS =	-std=c++11 -Wno-deprecated-declarations -O3

CFLAGS2 = 	-framework OpenGL -framework GLUT -O3 -ltermcap \
			-Wno-deprecated-declarations

SRCS = test2.cpp

CC = g++

LIBRARY = -framework OpenGL -framework AppKit	\

all: $(NAME)
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#   created lib1    #"
	@echo "#    succesfully    #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

$(NAME):
	@$(CC) $(CFLAGS) $(CFLAGS2) -o $(NAME) $(LIBRARY) $(SRCS)

clean:
	@rm -f $(OBJS)
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#       clean       #"
	@echo "#     succesful     #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

fclean: clean
	@rm -f $(NAME)
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#      fclean       #"
	@echo "#     succesful     #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

re: fclean all
	@echo "\n# # # # # # # # # # #"
	@echo "#                   #"
	@echo "#        re         #"
	@echo "#     succesful     #"
	@echo "#                   #"
	@echo "# # # # # # # # # # #\n"

#texture:
#	@if [ ! -d textures ]; then \
#		git submodule add https://github.com/abintcli/textures.git textures; \
#	fi

.PHONY: clean fclean re
