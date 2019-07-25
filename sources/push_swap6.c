/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:04:42 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 20:04:49 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_lst	*rr_aorb(t_lst *head, int flag)
{
	head->ishead = 0;
	head = head->prev;
	head->ishead = 1;
	ft_putendl(flag == 0 ? "rra" : "rrb");
	return (head);
}

t_lst	*r_aorb(t_lst *head, int flag)
{
	head->ishead = 0;
	head = head->next;
	head->ishead = 1;
	ft_putendl(flag == 0 ? "ra" : "rb");
	return (head);
}

t_lst	*s_aorb(t_lst *head, int flag)
{
	int t;

	t = head->num;
	head->num = head->next->num;
	head->next->num = t;
	ft_putendl(flag == 0 ? "sa" : "sb");
	return (head);
}

t_lst	*sort_list(t_lst *lst, int (*cmp)(int, int))
{
	t_lst	*tmp;
	int		swap;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (lst->next && lst->next->ishead != 1)
	{
		if (!cmp(lst->num, lst->next->num))
		{
			swap = lst->next->num;
			lst->next->num = lst->num;
			lst->num = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	return (tmp);
}

int		ascending(int a, int b)
{
	return (a > b);
}
