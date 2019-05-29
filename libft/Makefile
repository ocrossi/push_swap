# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/24 05:37:16 by ocrossi      #+#   ##    ##    #+#        #
#    Updated: 2019/05/27 17:01:01 by ocrossi     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
FILES = $(shell ls srcs/*.c | cut -d . -f1 | cut -d / -f 2)
PATH_SRCS = ./srcs/
PATH_OBJ = ./obj/
FLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES)))
OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o, $(FILES)))
PATH_INCLUDES = ./srcs/includes/
INC = $(addprefix $(PATH_INCLUDES), libft.h)

all: $(NAME)

$(NAME): $(PATH_OBJ) $(OBJ) $(INC)
	@ar rcs $(NAME) $(OBJ)
	@echo "library created"

$(PATH_OBJ):
	@mkdir $(PATH_OBJ)
	@echo "creating object directory for the library"

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INC)
	@gcc $(FLAGS) -o $@ -I $(PATH_INCLUDES) -c $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "library deleted"

re: fclean all

.PHONY: all clean fclean re
