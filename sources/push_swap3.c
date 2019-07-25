/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:26:03 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 19:26:04 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_lst	*find_cheap(t_lst *h)
{
	int		min;
	t_lst	*it;

	it = h;
	min = h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr;
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		if (min > h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr
			&& h->here == 1)
		{
			min = h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr;
			it = h;
		}
	}
	return (it);
}

void	three_zero(t_lst *h, int flag)
{
	if (flag == 0)
	{
		h->ra = 0;
		h->rb = 0;
		h->rr = 0;
	}
	else
	{
		h->rra = 0;
		h->rrb = 0;
		h->rrr = 0;
	}
}

int		minint(t_lst *head)
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

int		maxint(t_lst *head)
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

int		maxint2(t_lst *head)
{
	t_lst	*tmp;
	int		max;

	tmp = head;
	max = head->num;
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		if (max < tmp->num && tmp->num != maxint(head))
			max = tmp->num;
	}
	return (max);
}
