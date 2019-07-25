/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:31:26 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 19:31:28 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	rr_ab(t_lst **head, int flag)
{
	int n;

	n = (*head)->num;
	(*head)->ishead = 0;
	(*head) = (*head)->prev;
	while ((*head)->prev->num != n && (*head)->here == 0)
		(*head) = (*head)->prev;
	(*head)->ishead = 1;
	ft_putendl(flag == 0 ? "rra" : "rrb");
}

void	r_ab(t_lst **head, int flag)
{
	int n;

	n = (*head)->num;
	(*head)->ishead = 0;
	(*head) = (*head)->next;
	while ((*head)->next->num != n && (*head)->here == 0)
		(*head) = (*head)->next;
	(*head)->ishead = 1;
	ft_putendl(flag == 0 ? "ra" : "rb");
}

void	rr(t_lst **heada, t_lst **headb)
{
	int na;
	int nb;

	na = (*heada)->num;
	nb = (*headb)->num;
	(*heada)->ishead = 0;
	(*headb)->ishead = 0;
	(*heada) = (*heada)->next;
	while ((*heada)->next->num != na && (*heada)->here == 0)
		(*heada) = (*heada)->next;
	(*heada)->ishead = 1;
	(*headb) = (*headb)->next;
	while ((*headb)->next->num != nb && (*headb)->here == 0)
		(*headb) = (*headb)->next;
	(*headb)->ishead = 1;
	ft_putendl("rr");
}

void	rrr(t_lst **heada, t_lst **headb)
{
	int na;
	int nb;

	na = (*heada)->num;
	nb = (*headb)->num;
	(*heada)->ishead = 0;
	(*headb)->ishead = 0;
	(*heada) = (*heada)->prev;
	while ((*heada)->prev->num != na && (*heada)->here == 0)
		(*heada) = (*heada)->prev;
	(*heada)->ishead = 1;
	(*headb) = (*headb)->prev;
	while ((*headb)->prev->num != nb && (*headb)->here == 0)
		(*headb) = (*headb)->prev;
	(*headb)->ishead = 1;
	ft_putendl("rrr");
}

void	p_ab(t_lst **heada, t_lst **headb)
{
	t_lst *lst;

	lst = *headb;
	(*headb)->ishead = 0;
	while (lst->next && lst->next->ishead != 1)
	{
		if (lst->num == (*heada)->num)
		{
			lst->here = 1;
			lst->ishead = 1;
			(*heada)->here = 0;
			(*heada)->ishead = 0;
			while ((*heada)->next->num != lst->num && (*heada)->here == 0)
				*heada = (*heada)->next;
			(*heada)->ishead = 1;
			(*headb) = lst;
			break ;
		}
		lst = lst->next;
	}
	ft_putendl("pb");
}
