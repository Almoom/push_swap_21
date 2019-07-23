# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 13:04:11 by ljalikak          #+#    #+#              #
#    Updated: 2019/04/04 13:04:14 by ljalikak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = push_swap
NAME2 = checker

make:
	@$(CC) -o $(NAME) main.c /Users/ljalikak/Documents/push_swap_21/libft/libft.a

make2:
	@$(CC) -o $(NAME2) main2.c /Users/ljalikak/Documents/push_swap_21/libft/libft.a

clean:
	@rm -f /Users/ljalikak/Documents/push_swap_21/libft/*.o

fclean: clean
	@rm -f *.out

re: fclean all
