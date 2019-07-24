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
	@$(CC) -o $(NAME) main.c common_valid.c common_born_kill_stack.c /Users/ljalikak/Documents/push_swap_21/libft/libft.a

make2:
	@$(CC) -o $(NAME2) checker.c common_valid.c common_born_kill_stack.c checker2.c checker3.c checker4.c /Users/ljalikak/Documents/push_swap_21/libft/libft.a

clean:
	@rm -f /Users/ljalikak/Documents/push_swap_21/libft/*.o

fclean: clean
	@rm -f *.out

re: fclean all
