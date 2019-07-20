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
		if (i == 0 && s[i] != '-' && s[i] != '+' && !ft_isdigit(s[i]))
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

void reader(t_lst **head)
{
	char *arr;

	arr = NULL;
	while (ft_get_next_line(0, &arr))
	{
		if (ft_valid_op(arr))
		{
			ft_putendl("go");//////////////////////////////////////////////////////////
			free(arr);
		}
		else
		{
			ft_putendl("Error");
			break;
		}
	}
	free(arr);
}

int main(int ac, char **av)
{

	t_lst *heada;
	int i;

	i = 0;
	heada = NULL;
	while (++i < ac)
	{
		if (ft_notvalid(av[i]))
		{
			ft_putendl("Error");
			del_stack(&heada, i - 1);
			return (0);
		}
		heada = create_stake(heada, ft_atoi(av[i]));
	}
	reader(&heada);
	del_stack(&heada, ac - 1);
	return (0);
}
