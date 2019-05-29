# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ocrossi <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/04/24 04:39:13 by ocrossi      #+#   ##    ##    #+#        #
#    Updated: 2019/05/28 12:43:19 by ocrossi     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc
CC_FLAGS = -fsanitize=address -Wall -Wextra -Werror

#******************************************************************************#
#----------------------------------LIBFT---------------------------------------#
#******************************************************************************#
NAME_LIB = libft.a
PATH_LIB = ./libft/

#******************************************************************************#
#-----------------------------------PUSH_SWAP----------------------------------#
#******************************************************************************#
NAME = checker
NAMEPS = push_swap
PATH_SRCS = ./srcs/
PATH_OBJ = ./obj/
PATH_INC = ./srcs/includes/
FILES = $(shell ls srcs/*.c | cut -d "." -f 1 | cut -d / -f 2)
OBJ = $(addprefix $(PATH_OBJ), $(addsuffix .o, $(FILES)))
SRCS = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES)))
INC = $(addprefix $(PATH_INC), push_swap.h)
MAINCH = main_checker.c
MAINPS = main_ps.c

#******************************************************************************#
#----------------------------------RULES---------------------------------------#
#******************************************************************************#

all: $(NAME)

$(NAME): $(PATH_LIB)$(NAME_LIB) $(PATH_OBJ) $(OBJ) $(MAINPS) $(MAINCH)
	@$(CC) $(CC_FLAGS) $(OBJ) $(PATH_LIB)$(NAME_LIB) $(MAINCH) -o $(NAME)
	@echo "checker output created"
	@$(CC) $(CC_FLAGS) $(OBJ) $(PATH_LIB)$(NAME_LIB) $(MAINPS) -o $(NAMEPS)
	@echo "push_swap output created"

$(PATH_OBJ):
	@mkdir $(PATH_OBJ)
	@echo "object folder created"

$(PATH_OBJ)%.o: $(PATH_SRCS)%.c $(INC)
	@$(CC) $(CC_FLAGS) -o $@ -c $< -I $(PATH_INC)

$(PATH_LIB)$(NAME_LIB):
	@make -C $(PATH_LIB)

clean: clean_lib
	@rm -f $(OBJ)

fclean: clean fclean_lib
	@rm -f $(NAME)
	@rm -f $(NAMEPS)
	@rm -rf ./obj

clean_lib:
	@make -C $(PATH_LIB) clean

fclean_lib: clean_lib
	@make -C $(PATH_LIB) fclean

re: fclean_lib fclean all
