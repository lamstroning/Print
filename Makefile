# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: -tdontos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/02 12:58:40 by tdontos-          #+#    #+#              #
#    Updated: 2019/01/06 13:54:10 by tdontos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_printf

SRC=ft_printf.c check_format.c save_conf.c output.c
LIBFT=./libft
OBJ=$(SRC:.c=.o)
INC=./

all: $(NAME)
	
$(NAME):
	@make -C $(LIBFT)
	@gcc  -I$(INC) -c $(SRC)
	@gcc $(OBJ) -L $(LIBFT) -lft -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
