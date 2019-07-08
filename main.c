/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:13:24 by ljalikak          #+#    #+#             */
/*   Updated: 2019/06/19 14:13:26 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void print(t_lst *tmp)
{
	printf("%d\t", tmp->num);
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		printf("%d\t", tmp->num);
	}
	printf("\n");
}

t_lst	*create_list(int num, int ishead)
{
	t_lst *list;

	if (!(list = (t_lst*)malloc(sizeof(*list))))
		return (NULL);
	list->num = num;
	list->ishead = ishead == 1 ? 1 : 0;
	list->prev = NULL;
	list->next = NULL;
	list->len = NULL;
	list->cost = -1;
	return (list);
}

t_lst *create_stake(t_lst *head, int n)
{
	t_lst *tmp;
	t_lst *list;

	list = NULL;
	tmp = head;
	if (!head)
		head = create_list(n, 1);
	else
	{
		while (tmp->next && tmp->next->ishead != 1)
			tmp = tmp->next;
		list = create_list(n, 0);
		tmp->next = list;
		list->prev = tmp;
		list->next = head;
		head->prev = list;
	}
	return (head);
}

void sort1(t_lst *head)
{
	
}

void push_swap(int ac, char **av)
{
	t_lst *heada;
	t_lst *headb;
	int i;

	i = 0;
	heada = headb = NULL;
	if (ac > 6)
	{
		while (++i < 4)
			headb = create_stake(headb, atoi(av[i]));
		print(headb);
		i--;
		while (++i < ac)
			heada = create_stake(heada, atoi(av[i]));
		print(heada);
		//sort2();
	}
	else
	{
		while (++i < ac)
			heada = create_stake(heada, atoi(av[i]));
		print(heada);
		sort1(heada);
	}
	//headb = create_stake_b(headb, heada);
}

int main(int ac, char **av)
{
	// 10 3 4 5 9 13 0 6 11 8 -5 -3 -99 1000
	// 16 12 17 10 7 9 1 19 8 4 2 15 13 6 20 14 18 5 11 3 --127 --75

	if (ac > 3)
		push_swap(ac, av);
	else if (ac == 3 && atoi(av[1]) > atoi(av[2]))
		printf("%s\n", "sa");
	return (0);
}
