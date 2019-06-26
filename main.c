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

// int check(int *tab, int min, int len)
// {
// 	int i;
// 	char *s;
// 	int pos;
//
// 	i = 0;
// 	while (tab[i] != min)
// 		i++;
// 	i++;
// 	if (i >= len)
// 		i = i - len;
// 	if (i == 0)
// 		i++;
// 	while (tab[i - 1] < tab[i])
// 	{
//
// 		i++;
// 		if (i >= len)
// 			i = i - len;
// 	}
// 	pos = len - i;
//
// 	if (tab[i] == min)
// 	{
// 		s = i > len / 2 ? "rra" : "ra";
// 		printf("%d\n", pos);
// 		while (pos > 0)
// 		{
// 			printf("%s\n", s);
// 			pos--;
// 		}
//
// 		return (len - i);
// 	}
// 	return (0);
// }

// int check(int *tab, int min, int len)
// {
// 	int i;
//
// 	i = 1;
// 	while (tab[i - 1] < tab[i] && i < len)
// 		i++;
// 	if (i == len)
// 		return (1);
// 	return (0);
// }

// int		main()
// {
// 	//int tab[10] = {5, 56, 3, 45, 30, -4, 18, -100, 0, 13};
// 	//int tab[4] = {7, 3, 5 ,1};
// 	int tab[] = {8, 5, 3, 4, 2, 1};
// 	//int tab[] = {10,3,4,5,9,13,0,6,78,8};
// 	//int tab[] = {3,2,0};
// 	int len = 6;
// 	int i;
// 	int t;
// 	int j;
// 	int count;
//
// 	i = 1;
// 	count = 0;
// 	while (!check(tab, 1, len))
// 	{
// 		t = tab[i];
// 		count++;
// 		j = i - 1;
// 		while (j >= 0 && tab[j] > t)
// 		{
// 			tab[j + 1] = tab[j];
// 			j--;
// 			count++;
// 		}
// 		tab[j + 1] = t;
// 		i++;
// 		if (i >= len)
// 			i = i - len;
// 	}
// 	printf("%d\n", count + check(tab, 1, len));
// 	i = 0;
// 	while (i < len)
// 	{
// 		printf("%d\t", tab[i]);
// 		i++;
// 	}
// }

void print(t_list *tmp)
{
	printf("%d\t", tmp->num);
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		printf("%d\t", tmp->num);
	}
	printf("\n");
}
void print_l(t_l *tmp)
{
	printf("%d\t", tmp->num);
	while (tmp->next)
	{
		tmp = tmp->next;
		printf("%d\t", tmp->num);
	}
	printf("\n");
}

t_list	*create_list(int num, int ishead, int len)
{
	t_list *list;

	if (!(list = (t_list*)malloc(sizeof(*list))))
		return (NULL);
	list->num = num;
	list->ishead = ishead == 1 ? 1 : 0;
	list->prev = NULL;
	list->next = NULL;
	list->len = len;
	return (list);
}

t_list	*add_list(t_list *head, int num, int len)
{
	t_list *tmp;
	t_list *list;

	list = NULL;
	tmp = head;
	if (!head)
		head = create_list(num, 1, len);
	else
	{
		while (tmp->next && tmp->next->ishead != 1)
			tmp = tmp->next;
		list = create_list(num, 0, len);
		tmp->next = list;
		list->prev = tmp;
		list->next = head;
		head->prev = list;
	}
	printf("%s\n", "ra");
	return (head);
}

t_list	*prev_list(t_list *head, int num, int len)
{
	t_list *tmp;
	t_list *list;

	list = NULL;
	tmp = head;
	if (!head)
		list = create_list(num, 1, len);
	else
	{
		while (tmp->next && tmp->next->ishead != 1)
			tmp = tmp->next;
		list = create_list(num, 1, len);
		head->ishead = 0;
		list->next = head;
		list->prev = tmp;
		tmp->next = list;
		head->prev = list;
	}
	printf("%s\n", "pb");
	return (list);
}

int minint(t_list *head)
{
	t_list	*tmp;
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

void rr_aorb(t_list **head, int flag)
{
	(*head)->ishead = 0;
	*head = (*head)->prev;
	(*head)->ishead = 1;
	printf("%s\n", flag == 0 ? "rra" : "rrb");
}

void r_aorb(t_list **head, int flag)
{
	(*head)->ishead = 0;
	*head = (*head)->next;
	(*head)->ishead = 1;
	printf("%s\n", flag == 0 ? "ra" : "rb");
}

void s_aorb(t_list **head, int flag)
{
	int t;

	t = 0;
	t = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = t;
	printf("%s\n", flag == 0 ? "sa" : "sb");
}

void rrr(t_list **heada, t_list **headb)
{
	(*heada)->ishead = 0;
	*heada = (*heada)->prev;
	(*heada)->ishead = 1;
	(*headb)->ishead = 0;
	*headb = (*headb)->prev;
	(*headb)->ishead = 1;
	printf("%s\n", "rrr");
}

void rr(t_list **heada, t_list **headb)
{
	(*heada)->ishead = 0;
	*heada = (*heada)->next;
	(*heada)->ishead = 1;
	(*headb)->ishead = 0;
	*headb = (*headb)->next;
	(*headb)->ishead = 1;
	printf("%s\n", "rr");
}

void ss(t_list **heada, t_list **headb)
{
	int t;

	t = 0;
	t = (*heada)->num;
	(*heada)->num = (*heada)->next->num;
	(*heada)->next->num = t;
	t = (*headb)->num;
	(*headb)->num = (*headb)->next->num;
	(*headb)->next->num = t;
	printf("%s\n", "ss");
}

int maxint(t_list *head)
{
	t_list	*tmp;
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

int		check(t_list *head, int flag)
{
	t_list	*tmp;
	int		i;
	int		t;

	tmp = head;
	i = 1;
	t = flag == 0 ? minint(head) : maxint(head);
	if (!head->next)
		return (0);
	while (tmp->num != t)
		tmp = tmp->next;
	while (1)
	{
		if ((flag == 0 && tmp->num > tmp->next->num)
		|| (flag == 1 && tmp->num < tmp->next->num))
			break ;
		tmp = tmp->next;
		i++;
		if (i == tmp->len)
			return (0);
	}
	return (1);
}

void dosort(t_list *head, int flag)
{
	int		i;
	t_list	*tmp;
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
	s = i > head->len / 2 ? "rr" : "r";
	i = i > head->len / 2 ? head->len - i : i;
	while (i > 0)
	{
		printf("%s%s\n", s, flag == 0 ? "a" : "b");
		i--;
	}
}

void sortp_new(t_list *heada, t_list *headb, int mina, int maxb)
{
	while (check(heada, 0) || check(headb, 1))
	{
		if ((heada->num > heada->next->num && heada->next->num != mina)
		&& (headb->num < headb->next->num && headb->next->num != maxb))
			ss(&heada, &headb);
		if ((heada->num < heada->prev->num && heada->num != mina)
		&& (headb->num > headb->prev->num && headb->num != maxb))
			rrr(&heada, &headb);
		if (heada->num > heada->next->num && heada->next->num != mina)
			s_aorb(&heada, 0);
		if (headb->num < headb->next->num && headb->next->num != maxb)
			s_aorb(&headb, 1);
		if (heada->num < heada->prev->num && heada->num != mina)
			rr_aorb(&heada, 0);
		else if (headb->num > headb->prev->num && headb->num != maxb)
			rr_aorb(&headb, 1);
		else
			rr(&heada, &headb);
	}
	dosort(heada, 0);
	dosort(headb, 1);
}

void create_stakes(int ac, char **av, int lena, int mid)
{
	t_list *heada;
	t_list *headb;
	int i;
	int n;

	i = n = 0;
	heada = headb = NULL;
	while (++i < ac)
	{
		n = atoi(av[i]);
		if (n >= mid)
			heada = add_list(heada, n, ac - 1 - lena);
		else
			headb = prev_list(headb, n, lena);
	}
	// print(heada);
	// print(headb);
	sortp_new(heada, headb, minint(heada), maxint(headb));

	i = -1;
	while (++i < ac - 1 - lena)
		printf("%s\n", "pa");
	// print(heada);
	// print(headb);
}

t_l *create_l(int num)
{
	t_l *list;

	if (!(list = (t_l*)malloc(sizeof(*list))))
		return (NULL);
	list->num = num;
	list->next = NULL;
	return (list);
}

t_l	*add_l(t_l *head, int num)
{
	t_l *tmp;

	tmp = head;
	if (!head)
		head = create_l(num);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_l(num);
	}
	return (head);
}

t_l *create_pre(int ac, char **av)
{
	int i;
	t_l *head;

	i = 0;
	head = NULL;
	while (++i < ac)
		head = add_l(head, atoi(av[i]));
	return (head);
}

t_l *presort(t_l *head)
{
	t_l *tmp;
	int t;

	tmp = head;
	while (head->next)
	{
		if (head->num > head->next->num)
		{
			t = head->next->num;
			head->next->num = head->num;
			head->num = t;
			head = tmp;
		}
		else
			head = head->next;
	}
	return (tmp);
}

int findmiddle(t_l *head, int ac)
{
	int rez;
	int i;

	i = 0;
	while (head)
	{
		rez = head->num;
		head = head->next;
		i++;
		if (i >= ac / 2)
			break ;
	}
	return (rez);
}

int len_a(t_l *head, int mid)
{
	int rez;

	rez = 0;
	while (head)
	{
		if (mid > head->num)
			rez++;
		else
			break ;
		head = head->next;
	}
	return (rez);
}

int main(int ac, char **av)
{
	// 10 3 4 5 9 13 0 6 11 8 -5 -3 -99 1000
	int mid;
	int lena;
	t_l *head;

	head = create_pre(ac, av);
	head = presort(head);
	//print_l(head);
	mid = lena = 0;
	mid = findmiddle(head, ac);
	//printf("--%d\n", mid);
	lena = len_a(head, mid);
	//printf("--%d\n", lena);
	create_stakes(ac, av, lena, mid);
	return (0);
}
