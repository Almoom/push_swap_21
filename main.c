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
	if (!tmp)
	{
		printf("%s\n", "NULL");
		return ;
	}
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
	list->ishead = ishead;
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

void sort(t_lst *heada, t_lst *headb)
{

	printf("%d->\t", heada->num);
	printf("ra: %d\t", heada->ra);
	printf("rb: %d\t", heada->rb);
	printf("rr: %d\t", heada->rr);
	printf("rra: %d\t", heada->rra);
	printf("rrb: %d\t", heada->rrb);
	printf("rrr: %d\t", heada->rrr);
	printf("\n");
	while (heada->next && heada->next->ishead != 1)
	{
		heada = heada->next;
		printf("%d->\t", heada->num);
		printf("ra: %d\t", heada->ra);
		printf("rb: %d\t", heada->rb);
		printf("rr: %d\t", heada->rr);
		printf("rra: %d\t", heada->rra);
		printf("rrb: %d\t", heada->rrb);
		printf("rrr: %d\t", heada->rrr);
		printf("\n");
	}
}

int ft_abs(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	return (a - b);
}

int find_rb(int num, t_lst *headb)
{
	int min;
	int i;
	int rez;

	i = rez = 0;
	min = ft_abs(num, headb->num);
	printf("%d-\n", min);
	while (headb->next && headb->next->ishead != 1)
	{
		headb = headb->next;
		i++;
		printf("%d--\n", ft_abs(num, headb->num));
		if (min > ft_abs(num, headb->num))
		{
			min = ft_abs(num, headb->num);
			rez = i;
		}
	}
	printf("%d---\n", rez);
	return (rez);
}

int find_rrb(int num, t_lst *headb)
{
	int min;
	int i;
	int rez;

	i = rez = 0;
	min = ft_abs(num, headb->num);
	printf("%d-\n", min);
	while (headb->prev && headb->prev->ishead != 1)
	{
		headb = headb->prev;
		i++;
		printf("%d--\n", ft_abs(num, headb->num));
		if (min > ft_abs(num, headb->num))
		{
			min = ft_abs(num, headb->num);
			rez = i;
		}
	}
	printf("%d---\n", rez);
	return (rez);
}

void coast_r(t_lst *heada, t_lst *headb)
{
	int i;

	i = 0;
	heada->rb = find_rb(heada->num, headb);
	while (heada->next && heada->next->ishead != 1)
	{
		heada = heada->next;
		i++;
		heada->ra = i;
		heada->rb = find_rb(heada->num, headb);
		heada->rr = heada->ra > heada->rb ? heada->rb : heada->ra;
		heada->ra = heada->ra - heada->rr;
		heada->rb = heada->rb - heada->rr;
	}
}

void coast_rr(t_lst *heada, t_lst *headb)
{
	int i;

	i = 0;
	heada->rrb = find_rrb(heada->num, headb);
	while (heada->prev && heada->prev->ishead != 1)
	{
		heada = heada->prev;
		i++;
		heada->rra = i;
		heada->rrb = find_rrb(heada->num, headb);
		heada->rrr = heada->rra > heada->rrb ? heada->rrb : heada->rra;
		heada->rra = heada->rra - heada->rrr;
		heada->rrb = heada->rrb - heada->rrr;
	}
}

void coast_rez(t_lst *h)
{
	if (h->ra + h->rb + h->rr > h->rra + h->rrb + h->rrr)
		h->ra = h->rb = h->rr = 0;
	else
		h->rra = h->rrb = h->rrr = 0;
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		if (h->ra + h->rb + h->rr > h->rra + h->rrb + h->rrr)
			h->ra = h->rb = h->rr = 0;
		else
			h->rra = h->rrb = h->rrr = 0;
	}
}

void push_swap(int ac, char **av)
{
	t_lst *heada;
	t_lst *headb;
	int i;

	i = 0;
	heada = headb = NULL;
	while (++i < 3)
		headb = create_stake(headb, atoi(av[i]));
	i--;
	while (++i < ac)
		heada = create_stake(heada, atoi(av[i]));
	print(heada);
	print(headb);
	coast_r(heada, headb);
	coast_rr(heada, headb);
	coast_rez(heada);
	sort(heada, headb);
	print(heada);
	print(headb);
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
