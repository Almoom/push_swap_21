/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:42:46 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 17:42:48 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_lst	*ft_dellist(t_lst *h)
{
	t_lst *next;
	t_lst *prev;

	next = NULL;
	prev = NULL;
	if (!h)
		return (NULL);
	if ((h)->next && (h)->next == (h)->prev)
	{
		next = (h)->next;
		next->ishead = 1;
		next->next = NULL;
		next->prev = NULL;
	}
	else if ((h)->next && (h)->prev)
	{
		next = (h)->next;
		prev = (h)->prev;
		next->prev = prev;
		prev->next = next;
		next->ishead = 1;
	}
	free(h);
	h = NULL;
	return (next);
}

t_lst	*list_before(t_lst *head, int n)
{
	t_lst *list;

	list = NULL;
	if (!head)
		list = create_list(n, 1);
	else
	{
		list = create_list(n, 1);
		head->ishead = 0;
		if (head->prev && head->next)
		{
			head->prev->next = list;
			list->prev = head->prev;
			list->next = head;
			head->prev = list;
		}
		else
		{
			list->next = head;
			list->prev = head;
			head->next = list;
			head->prev = list;
		}
	}
	return (list);
}
