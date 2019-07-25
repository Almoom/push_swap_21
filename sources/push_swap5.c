/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:36:46 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 19:36:47 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	zero_coast(t_lst *h)
{
	three_zero(h, 0);
	three_zero(h, 1);
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		three_zero(h, 0);
		three_zero(h, 1);
	}
}

void	driver(t_lst *min, t_lst **heada, t_lst **headb)
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

void	ft_throw(int n)
{
	int i;

	i = -1;
	while (++i < n)
		ft_putendl("pa");
}

void	ft_here(t_lst *h)
{
	t_lst *lst;

	lst = h;
	lst->here = 1;
	while (lst->next && lst->next->ishead != 1)
	{
		lst = lst->next;
		lst->here = 1;
	}
}

int		solver(t_lst *heada)
{
	int n;

	if (!heada)
		return (1);
	n = heada->num;
	while (heada->next && heada->next->ishead != 1)
	{
		heada = heada->next;
		if (n < heada->num)
			n = heada->num;
		else
			return (0);
	}
	return (1);
}
