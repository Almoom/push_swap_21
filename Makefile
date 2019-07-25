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
CFLAGS = -Wall -Wextra -Werror
CHECKER = checker
PUSHSWAP = push_swap
LIB = $(LIBSRC)libft.a
HEADER = ./includes/
LIBSRC = ./libft/
SRC1 = ./sources/
SRC2 = common_valid.c \
common_born_kill_stack.c \
push_swap.c \
push_swap2.c \
push_swap3.c \
push_swap4.c \
push_swap5.c \
push_swap6.c \
push_swap7.c
SRC3 = common_valid.c \
common_born_kill_stack.c \
checker.c \
checker2.c \
checker3.c \
checker4.c

OBJS2 = $(SRC2:.c=.o)
OBJS3 = $(SRC3:.c=.o)

.PHONY: clean all fclean re

all: $(CHECKER) $(PUSHSWAP)

$(CHECKER): $(LIB) $(OBJS3) $(CHECKER).o
	$(CC) $(CFLAGS) -o $@ $^

$(PUSHSWAP): $(LIB) $(OBJS2) $(PUSHSWAP).o
	$(CC) $(CFLAGS) -o $(PUSHSWAP) $(OBJS2) $(LIB)

$(LIB):
	@make lib_refresh

%.o: $(SRC1)%.c
	$(CC) $(CFLAGS) -c $< -I $(HEADER) -I $(LIBSRC)

lib_refresh:
	make -C $(LIBSRC)

norm:
	norminette -R CheckForbiddenSourceHeader

clean:
	rm -rf $(OBJS3) $(OBJS2) 
	@make -C $(LIBSRC) clean

fclean: clean
	@rm -rf $(PUSHSWAP) $(CHECKER)
	make -C $(LIBSRC) fclean

re: fclean all
