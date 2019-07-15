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

void dosort(t_lst *head, int flag, int len)
{
	int		i;
	t_lst	*tmp;
	char	*s;
	int t;

	i = 0;
	t = flag == 0 ? minint(head) : maxint(head);
	tmp = head;
	while (tmp->num != t)
	{
		tmp = tmp->next;
		i++;
	}
	s = i > len / 2 ? "rr" : "r";
	i = i > len / 2 ? len - i : i;
	while (i > 0)
	{
		printf("%s%s\n", s, flag == 0 ? "a" : "b");
		i--;
	}
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

int maxint(t_lst *head)
{
	t_lst	*tmp;
	int		max;

	tmp = head;
	max = head->num;
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		if (max < tmp->num)
			max = tmp->num;
	}
	return (max);
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
    //(*head) = dosort((*head), min);
    //return (head);
}

void print_coast(t_lst *heada, t_lst *headb)
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
	//printf("%d-\n", min);
	while (headb->next && headb->next->ishead != 1)
	{
		headb = headb->next;
		i++;
		//printf("%d--\n", ft_abs(num, headb->num));
		if (min > ft_abs(num, headb->num))
		{
			min = ft_abs(num, headb->num);
			rez = i;
		}
	}
	//printf("%d---\n", rez);
	return (rez);
}

int find_rrb(int num, t_lst *headb)
{
	int min;
	int i;
	int rez;

	i = rez = 0;
	min = ft_abs(num, headb->num);
	//printf("%d-\n", min);
	while (headb->prev && headb->prev->ishead != 1)
	{
		headb = headb->prev;
		i++;
		//printf("%d--\n", ft_abs(num, headb->num));
		if (min > ft_abs(num, headb->num))
		{
			min = ft_abs(num, headb->num);
			rez = i;
		}
	}
	//printf("%d---\n", rez);
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

t_lst *find_cheap(t_lst *h)
{
	int min;
	t_lst *it;

	it = h;
	min = h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr;
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		if (min > h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr)
		{
			min = h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr;
			it = h;
		}
	}
	return (it);
}

void create_both(t_lst **heada, t_lst **headb, int ac, char **av)
{
	int i;

	i = 3;
	while (--i > 0)
	{
		*headb = create_stake(*headb, atoi(av[i]));
		printf("%s\n", "pb");
	}
	i = 2;
	while (++i < ac)
		*heada = create_stake(*heada, atoi(av[i]));
}

void rr_ab(t_lst **head, int flag)
{
	(*head)->ishead = 0;
	(*head) = (*head)->prev;
	(*head)->ishead = 1;
	printf("%s\n", flag == 0 ? "rra" : "rrb");
}

void r_ab(t_lst **head, int flag)
{
	(*head)->ishead = 0;
	(*head) = (*head)->next;
	(*head)->ishead = 1;
	printf("%s\n", flag == 0 ? "ra" : "rb");
}

void rr(t_lst **heada, t_lst **headb)
{
	(*heada)->ishead = 0;
	(*heada) = (*heada)->next;
	(*heada)->ishead = 1;
	(*headb)->ishead = 0;
	(*headb) = (*headb)->next;
	(*headb)->ishead = 1;
	printf("%s\n", "rr");
}

void rrr(t_lst **heada, t_lst **headb)
{
	(*heada)->ishead = 0;
	(*heada) = (*heada)->prev;
	(*heada)->ishead = 1;
	(*headb)->ishead = 0;
	(*headb) = (*headb)->prev;
	(*headb)->ishead = 1;
	printf("%s\n", "rr");
}

t_lst *add_list(t_lst *head, int num)
{
	t_lst *list;

	list = create_list(num, 1);
	list->next = head;
	list->prev = head->prev;
	head->ishead = 0;
	head->prev->next = list;
	head->prev = list;
	return (list);
}

void p_ab(t_lst **heada, t_lst **headb)
{
	t_lst *tmp;

	tmp = *heada;
	*headb = add_list(*headb, (*heada)->num);
	if ((*heada)->next)
	{
		*heada = (*heada)->next;
		(*heada)->ishead = 1;
		(*heada)->prev = tmp->prev;
		tmp->prev->next = *heada;
	}
	free(tmp);
	printf("%s\n", "pb");
}

void zero_coast(t_lst *h)
{
	h->ra = h->rb = h->rr = h->rra = h->rrb = h->rrr = 0;
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		h->ra = h->rb = h->rr = h->rra = h->rrb = h->rrr = 0;
	}
}

void driver(t_lst *min, t_lst **heada, t_lst **headb)
{
	while (min->ra-- > 0)
		r_ab(heada, 0);
	while (min->rb-- > 0)
		r_ab(headb, 1);
	while (min->rra-- > 0)
		rr_ab(heada, 0);
	while (min->rrb-- > 0)
		rr_ab(headb, 1);
	while (min->rr-- > 0)
		rr(heada, headb);
	while (min->rrr-- > 0)
		rrr(heada, headb);
	p_ab(heada, headb);
}

void ft_throw(int n)
{
	int i;

	i = -1;
	while (++i < n)
		printf("%s\n", "pa");
}

void push_swap(int ac, char **av)
{
	t_lst *heada;
	t_lst *headb;
	t_lst *min;
	int i;

	i = ac - 3;
	heada = headb = NULL;
	create_both(&heada, &headb, ac, av);
	print(heada);
	print(headb);

	while (i > 0)
	{
		coast_r(heada, headb);
		coast_rr(heada, headb);
		coast_rez(heada);
		print_coast(heada, headb);
		driver(find_cheap(heada), &heada, &headb);
		zero_coast(heada);
		print(heada);
		print(headb);
		i--;
	}
	dosort(headb, 1, ac - 1);
	ft_throw(ac - 1);
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
