/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:37:21 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 17:37:25 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_ss(t_lst **heada, t_lst **headb)
{
	ft_sab(heada);
	ft_sab(headb);
}

void	ft_p(t_lst **from, t_lst **to)
{
	if (!(*from))
		return ;
	*to = list_before(*to, (*from)->num);
	*from = ft_dellist(*from);
}

void	ft_build(t_lst **heada, t_lst **headb, char *s)
{
	if (!ft_strcmp(s, "ra"))
		ft_rab(heada);
	if (!ft_strcmp(s, "rb"))
		ft_rab(headb);
	if (!ft_strcmp(s, "rr"))
		ft_rr(heada, headb);
	if (!ft_strcmp(s, "rra"))
		ft_rrab(heada);
	if (!ft_strcmp(s, "rrb"))
		ft_rrab(headb);
	if (!ft_strcmp(s, "rrr"))
		ft_rrr(heada, headb);
	if (!ft_strcmp(s, "sa"))
		ft_sab(heada);
	if (!ft_strcmp(s, "sb"))
		ft_sab(headb);
	if (!ft_strcmp(s, "ss"))
		ft_ss(heada, headb);
	if (!ft_strcmp(s, "pb"))
		ft_p(heada, headb);
	if (!ft_strcmp(s, "pa"))
		ft_p(headb, heada);
}

int		ft_valid_op(char *s)
{
	if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rra")
	|| !ft_strcmp(s, "rrb") || !ft_strcmp(s, "rr") || !ft_strcmp(s, "rrr")
	|| !ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "ss")
	|| !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb"))
		return (1);
	return (0);
}
