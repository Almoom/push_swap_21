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
	{
		head = create_list(num, 1, len);
		tmp = head;
	}
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
	return (head);
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

int check(t_list *head, int min)
{
	t_list *tmp;
	int i;

	tmp = head;
	i = 1;
	while (tmp->num != min)
		tmp = tmp->next;
	while (1)
	{
		if (tmp->num > tmp->next->num)
			break ;
		tmp = tmp->next;
		i++;
		if (i == tmp->len)
			return (0);
	}
	return (1);
}

t_list *rra(t_list *head)
{
	head->ishead = 0;
	head = head->prev;
	head->ishead = 1;
	printf("%s\n", ">> rra");
	return (head);
}

t_list *ra(t_list *head)
{
	head->ishead = 0;
	head = head->next;
	head->ishead = 1;
	printf("%s\n", ">> ra");
	return (head);
}

t_list *sa(t_list *head)
{
	int t;

	t = 0;
	t = head->num;
	head->num = head->next->num;
	head->next->num = t;
	printf("%s\n", ">> sa");
	return (head);
}

t_list *dosort(t_list *head, int min)
{
	int i;
	t_list *tmp;
	t_list *(*f)(t_list*);

	i = 0;
	tmp = head;
	while (tmp->num != min)
	{
		tmp = tmp->next;
		i++;
	}
	f = i > head->len / 2 ? &rra : &ra;
	i = i > head->len / 2 ? head->len - i : i;
	while (i > 0)
	{
		head = f(head);
		i--;
	}
	return (head);
}

t_list *sortp(t_list *head)
{
	int min;

	min = minint(head);
	while (check(head, min))
	{
		if (head->num > head->next->num && head->next->num != min)
			head = sa(head);
		if (head->num < head->prev->num && head->num != min)
			head = rra(head);
		else
			head = ra(head);
		//print(head);
	}
	head = dosort(head, min);
	return (head);
}

int main()
{
	//int tab[] = {7,3,5,1};
	//int tab[] = {9, 0, 1,2,3,4,5,6,7,8};
	//int tab[] = {4,5,6,7,8,9,0,1,2,3};
	int tab[] = {10,3,4,5,9,13,0,6,78,8};
	int len = 10;
	int i = 0;
	t_list *tmp;
	t_list *head;

	tmp = head = NULL;
	while (i < len)
	{
		head = add_list(head, tab[i], len);
		i++;
	}
	tmp = head;
	print(tmp);
	tmp = sortp(head);
	print(tmp);
	return (0);
}




















//9
