/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:32:33 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 17:32:35 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_rab(t_lst **head)
{
	if (!(*head) || !(*head)->next)
		return ;
	(*head)->ishead = 0;
	(*head) = (*head)->next;
	(*head)->ishead = 1;
}

void	ft_rr(t_lst **heada, t_lst **headb)
{
	ft_rab(heada);
	ft_rab(headb);
}

void	ft_rrab(t_lst **head)
{
	if (!(*head) || !(*head)->prev)
		return ;
	(*head)->ishead = 0;
	(*head) = (*head)->prev;
	(*head)->ishead = 1;
}

void	ft_rrr(t_lst **heada, t_lst **headb)
{
	ft_rrab(heada);
	ft_rrab(headb);
}

void	ft_sab(t_lst **head)
{
	int t;

	if (!(*head) || !(*head)->next)
		return ;
	t = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = t;
}
