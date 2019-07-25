/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_born_kill_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:59:10 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 16:59:12 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	del_split(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int		ft_lenstack(t_lst *h)
{
	int i;

	i = 1;
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		i++;
	}
	return (i);
}

void	del_stack(t_lst **head)
{
	t_lst	*t;
	int		i;
	int		len;

	if (!(*head))
		return ;
	len = ft_lenstack(*head);
	t = NULL;
	i = 0;
	while (i < len)
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

t_lst	*create_stake(t_lst *head, int n)
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
