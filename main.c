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
	list->ra = 0;
	list->rb = 0;
    list->rr = 0;
    list->rrb = 0;
    list->rra = 0;
    list->rrr = 0;
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

t_lst *rr_aorb(t_lst *head, int flag)
{
    head->ishead = 0;
    head = head->prev;
    head->ishead = 1;
    printf("%s\n", flag == 0 ? "rra" : "rrb");
    return (head);
}

t_lst *r_aorb(t_lst *head, int flag)
{
    head->ishead = 0;
    head = head->next;
    head->ishead = 1;
    printf("%s\n", flag == 0 ? "ra" : "rb");
    return (head);
}

t_lst *s_aorb(t_lst *head, int flag)
{
    int t;

    t = 0;
    t = head->num;
    head->num = head->next->num;
    head->next->num = t;
    printf("%s\n", flag == 0 ? "sa" : "sb");
    return (head);
}

t_lst *dosort(t_lst *head, int min)
{
    int		i;
    t_lst	*tmp;

    i = 0;
    tmp = head;
    while (tmp->num != min)
    {
        tmp = tmp->next;
        i++;
    }
    while (i > 0)
    {
        head = r_aorb(head, 0);
        i--;
    }
    return (head);
}

int		check(t_lst *head, int min, int len)
{
    t_lst	*tmp;
    int		i;

    tmp = head;
    i = 1;
    if (!head->next)
        return (0);
    while (tmp->num != min)
        tmp = tmp->next;
    while (1)
    {
        if (tmp->num > tmp->next->num)
            break ;
        tmp = tmp->next;
        i++;
        if (i == len)
            return (0);
    }
    return (1);
}

int minint(t_lst *head)
{
    t_lst	*tmp;
    int		min;

    tmp = head;
    min = head->num;
    while (tmp->next && tmp->next->ishead != 1)
    {
        tmp = tmp->next;
        if (min > tmp->num)
            min = tmp->num;
    }
    return (min);
}

void sort1(t_lst **head, int len)
{
    int min;

    min = minint(*head);
    while (check(*head, min, len))
    {
        if ((*head)->num > (*head)->next->num && (*head)->next->num != min)
            (*head) = s_aorb((*head), 0);
        if ((*head)->num < (*head)->prev->num && (*head)->num != min)
            (*head) = rr_aorb((*head), 0);
        else
            (*head) = r_aorb((*head), 0);
        //print(head);
    }
    (*head) = dosort((*head), min);
    //return (head);
}

void push_swap(int ac, char **av)
{
	t_lst *heada;
	t_lst *headb;
	int i;

	i = 0;
	heada = headb = NULL;
	if (ac > 4)
	{
		while (++i < 3)
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
		//print(heada);
		sort1(&heada, ac - 1);
        //print(heada);
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
