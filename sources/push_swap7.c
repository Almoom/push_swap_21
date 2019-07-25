/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:11:36 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 20:11:37 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		create_both(t_lst **heada, t_lst **headb, int ac, char **av)
{
	int i;
	int (*cmd)(int, int);

	i = 0;
	cmd = &ascending;
	while (++i < ac)
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i])
		|| ft_intdupl(*heada, ft_atoi(av[i])))
		{
			ft_putendl("Error");
			del_stack(heada);
			del_stack(headb);
			return (0);
		}
		*heada = create_stake(*heada, ft_atoi(av[i]));
		*headb = create_stake(*headb, ft_atoi(av[i]));
	}
	sort_list(*headb, cmd);
	ft_here(*heada);
	return (1);
}

t_lst	*del_list(t_lst *h)
{
	t_lst *next;
	t_lst *prev;

	ft_putendl("pb");
	next = (h)->next;
	prev = (h)->prev;
	next->prev = prev;
	prev->next = next;
	next->ishead = 1;
	free(h);
	return (next);
}

void	spasi_i_sohrani(t_lst *h, int l, int flag)
{
	dosort(h, 0, l);
	ft_putstr(flag == 1 ? "sb\n" : "");
}

int		sort(t_lst **h, int l, int z, int f)
{
	int i;
	int flag;
	int y;

	i = 0;
	flag = 0;
	y = maxint2(*h);
	while (check(*h, minint(*h), l))
	{
		if (f == 1 && ((*h)->num == z || (*h)->num == y) && i++ < 2 && l-- > 3)
		{
			flag = (*h)->num == y ? flag * 0 : flag + 1;
			(*h) = del_list(*h);
		}
		else
		{
			if ((*h)->num > (*h)->next->num && (*h)->next->num != minint(*h))
				(*h) = s_aorb((*h), 0);
			if (check(*h, minint(*h), l))
				*h = ((*h)->num < (*h)->prev->num && (*h)->num != minint(*h)) ?
				rr_aorb((*h), 0) : r_aorb((*h), 0);
		}
	}
	spasi_i_sohrani(*h, l, flag);
	return (i);
}

void	simple_sort(int ac, char **av, int flag)
{
	t_lst	*heada;
	int		i;

	i = 0;
	heada = NULL;
	while (++i < ac)
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i])
		|| ft_intdupl(heada, ft_atoi(av[i])))
		{
			ft_putendl("Error");
			del_stack(&heada);
			return ;
		}
		heada = create_stake(heada, ft_atoi(av[i]));
	}
	i = sort(&heada, ac - 1, maxint(heada), flag);
	del_stack(&heada);
	while (i-- > 0)
		ft_putstr("pa\nra\n");
}
