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
	if (tmp->here == 1)
		printf("%d\t", tmp->num);
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		if (tmp->here == 1)
			printf("%d\t", tmp->num);
	}
	printf("\n");
}

int ft_notvalid(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i + 1] && i == 0 && (s[i] == '-' || s[i] == '+') &&
		!ft_isdigit(s[i + 1]))
			return (1);
		if (i > 0 && !ft_isdigit(s[i]))
			return (1);
		i++;
	}
	return (0);
}

void del_stack(t_lst **head, int n)
{
	t_lst *t;
	int i;

	t = NULL;
	i = 0;
	while (i < n)
	{
		t = (*head)->next;
		free(*head);
		*head = t;
		i++;
	}
}

t_lst	*create_list(int num, int ishead)
{
	t_lst *list;

	if (!(list = (t_lst*)malloc(sizeof(*list))))
		return (NULL);
	list->num = num;
	list->ishead = ishead;
	list->here = 0;
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

int ft_valid_op(char *s)
{
	if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rra")
	|| !ft_strcmp(s, "rrb") || !ft_strcmp(s, "rr") || !ft_strcmp(s, "rrr")
	|| !ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "ss")
	|| !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb"))
		return (1);
	return (0);
}

void del_split(char **s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void reader(t_lst **head)
{
	char *arr;

	arr = NULL;
	while (ft_get_next_line(0, &arr))
	{
		if (ft_valid_op(arr))
		{
			ft_putendl("go");//////////////////////////////////////////////////////////
			ft_memdel((void**)(&arr));
		}
		else
		{
			ft_putendl("Error");
			break;
		}
	}
	ft_memdel((void**)(&arr));
}

void checker(int ac, char **av)
{
	t_lst *heada;
	int i;

	i = 0;
	heada = NULL;
	while (++i < ac)
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i]))
		{
			ft_putendl("Error");
			del_stack(&heada, i - 1);
			return ;
		}
		heada = create_stake(heada, ft_atoi(av[i]));
	}
	reader(&heada);
	del_stack(&heada, ac - 1);
}

int ft_isint2(char *s, int n, int len, int minus)
{
	int i;

	i = 0;
	while (i < n)
	{
		s++;
		i++;
	}
	if (len < 10)
		return (1);
	if (len == 10)
	{
		if (minus && ft_strcmp(s, "2147483648") <= 0)
			return (1);
		if (!minus && ft_strcmp(s, "2147483647") <= 0)
			return (1);
	}
	return (0);
}

int ft_isint(char *s)
{
	int i;
	int j;
	int flag;
	int minus;

	i = j = flag = minus = 0;
	while (s[i])
	{
		if (i == 0 && s[i] == '-')
			minus = 1;
		if (i == 0 && (s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			i++;
		while (s[i] == '0' && flag == 0)
			i++;
		if (ft_isdigit(s[i]))
		{
			flag = 1;
			j++;
		}
		i++;
	}
	return (ft_isint2(s, i - j, j, minus));
}

int main(int ac, char **av)
{
	// 10 3 4 5 9 -2 13 0 6 11 8 -5 -3 -99 1000 18 -11 --58
	// 16 12 17 10 7 9 1 19 8 4 2 15 13 6 20 14 18 5 11 3 --127 --75

	if (ac == 2)
		do_split(av[1]);
	else if (ac > 2)
		checker(ac, av);

	return (0);
}

void do_split(const char *s)
{
	char **av;
	char *t[10000];
	int i;

	i = -1;
	t[0] = "42";
	if (!ft_strchr(s, ' '))
		return ;
	av = ft_strsplit(s, ' ');
	while (av[++i])
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i]))
		{
			ft_putendl("Error");
			del_split(av, i);
			return ;
		}
		t[i + 1] = av[i];
	}
	t[i + 1] = 0;
	if (i == 1)
		return ;
	else
		main(i + 1, t);
	del_split(av, i);
}
