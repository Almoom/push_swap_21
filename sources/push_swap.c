/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:38:53 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 20:38:55 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	dosort(t_lst *head, int flag, int len)
{
	int		i;
	t_lst	*tmp;
	char	*s;
	int		t;

	i = 1;
	t = flag == 0 ? minint(head) : maxint(head);
	tmp = head;
	while (tmp->num != t)
	{
		tmp = tmp->next;
		i++;
	}
	s = i - 1 > len / 2 ? "rr" : "r";
	i = i - 1 > len / 2 ? len - (i - 1) : i - 1;
	while (i > 0)
	{
		ft_putstr(s);
		ft_putendl(flag == 0 ? "a" : "b");
		i--;
	}
}

void	push_swap(int ac, char **av)
{
	t_lst	*heada;
	t_lst	*headb;
	int		i;

	heada = NULL;
	headb = NULL;
	if (create_both(&heada, &headb, ac, av) && !solver(heada))
	{
		p_ab(&heada, &headb);
		p_ab(&heada, &headb);
		i = ac - 2;
		while (--i > 0)
		{
			coast_r(heada, headb);
			coast_rr(heada, headb);
			coast_rez(heada);
			driver(find_cheap(heada), &heada, &headb);
			zero_coast(heada);
		}
		dosort(headb, 1, ac - 1);
		ft_throw(ac - 1);
	}
	del_stack(&heada);
	del_stack(&headb);
}

int		check(t_lst *head, int min, int len)
{
	t_lst	*tmp;
	int		i;

	tmp = head;
	i = 1;
	if (!head->next)
		return (0);
	while (tmp->num != min)
		tmp = tmp->next;
	while (1)
	{
		if (tmp->num > tmp->next->num)
			break ;
		tmp = tmp->next;
		i++;
		if (i == len)
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	while (av[i] && ac > 2)
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i]) || ft_strdupl(av, av[i], i)
		|| ft_atoi(av[1]) == ft_atoi(av[2]))
		{
			ft_putendl("Error");
			return (0);
		}
		i++;
	}
	if (ac == 2 && ft_strchr(av[1], ' '))
		do_split(av[1]);
	else if (ac > 3 && ac < 6)
		simple_sort(ac, av, 0);
	else if (ac == 6)
		simple_sort(ac, av, 1);
	else if (ac > 6)
		push_swap(ac, av);
	else if (ac == 3 && ft_atoi(av[1]) > ft_atoi(av[2]))
		ft_putendl("sa");
	return (0);
}

void	do_split(char *s)
{
	char	**av;
	char	*t[10000];
	int		i;

	i = -1;
	if (!ft_strcmp(s, " "))
	{
		ft_putendl("Error");
		return ;
	}
	av = ft_strsplit(s, ' ');
	while (av[++i])
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i]) || ft_strdupl(av, av[i], i))
		{
			ft_putendl("Error");
			del_split(av);
			return ;
		}
		t[i + 1] = av[i];
	}
	t[i + 1] = 0;
	if (i > 1)
		main(i + 1, t);
	del_split(av);
}
