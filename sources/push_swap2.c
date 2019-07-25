/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:09:14 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 19:09:17 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		find_rb(int num, t_lst *headb)
{
	int i;

	i = 0;
	if (headb->here == 1)
		i++;
	if (num == headb->num)
		return (i);
	while (headb->next && headb->next->ishead != 1)
	{
		headb = headb->next;
		if (headb->here == 1)
			i++;
		if (num == headb->num)
			return (i);
	}
	return (i);
}

void	coast_r(t_lst *heada, t_lst *headb)
{
	int i;

	i = 0;
	if (heada->here == 1)
	{
		heada->ra = i;
		heada->rb = find_rb(heada->num, headb);
		heada->rr = heada->ra > heada->rb ? heada->rb : heada->ra;
		heada->ra = heada->ra - heada->rr;
		heada->rb = heada->rb - heada->rr;
	}
	while (heada->next && heada->next->ishead != 1)
	{
		heada = heada->next;
		if (heada->here == 1)
		{
			i++;
			heada->ra = i;
			heada->rb = find_rb(heada->num, headb);
			heada->rr = heada->ra > heada->rb ? heada->rb : heada->ra;
			heada->ra = heada->ra - heada->rr;
			heada->rb = heada->rb - heada->rr;
		}
	}
}

int		find_rrb(int num, t_lst *headb)
{
	int i;

	i = 0;
	while (headb->prev && headb->prev->ishead != 1)
	{
		headb = headb->prev;
		if (num == headb->num)
			return (i);
		if (headb->here == 1)
			i++;
	}
	return (i);
}

void	coast_rr(t_lst *heada, t_lst *headb)
{
	int i;

	i = 0;
	if (heada->here == 1)
	{
		heada->rra = i;
		heada->rrb = find_rrb(heada->num, headb);
		heada->rrr = heada->rra > heada->rrb ? heada->rrb : heada->rra;
		heada->rra = heada->rra - heada->rrr;
		heada->rrb = heada->rrb - heada->rrr;
	}
	while (heada->prev && heada->prev->ishead != 1)
	{
		heada = heada->prev;
		if (heada->here == 1)
		{
			i++;
			heada->rra = i;
			heada->rrb = find_rrb(heada->num, headb);
			heada->rrr = heada->rra > heada->rrb ? heada->rrb : heada->rra;
			heada->rra = heada->rra - heada->rrr;
			heada->rrb = heada->rrb - heada->rrr;
		}
	}
}

void	coast_rez(t_lst *h)
{
	if (!(h->ra + h->rb + h->rr == 0 || h->rra + h->rrb + h->rrr == 0))
	{
		if (h->ra + h->rb + h->rr < h->rra + h->rrb + h->rrr)
			three_zero(h, 1);
		else
			three_zero(h, 0);
	}
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		if (h->ra + h->rb + h->rr == 0 || h->rra + h->rrb + h->rrr == 0)
			continue ;
		if (h->ra + h->rb + h->rr < h->rra + h->rrb + h->rrr)
			three_zero(h, 1);
		else
			three_zero(h, 0);
	}
}
