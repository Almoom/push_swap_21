/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:47:26 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 17:47:28 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		reader(t_lst **heada, t_lst **headb)
{
	char *arr;

	arr = NULL;
	while (ft_get_next_line(0, &arr))
	{
		if (ft_valid_op(arr))
		{
			ft_build(heada, headb, arr);
			ft_memdel((void**)(&arr));
		}
		else
		{
			ft_putendl("Error");
			ft_memdel((void**)(&arr));
			return (1);
		}
	}
	ft_memdel((void**)(&arr));
	return (0);
}

void	ft_solve(t_lst *heada, t_lst *headb)
{
	int n;

	n = heada->num;
	if (headb)
	{
		ft_putendl("KO");
		return ;
	}
	while (heada->next && heada->next->ishead != 1)
	{
		heada = heada->next;
		if (n < heada->num)
			n = heada->num;
		else
		{
			ft_putendl("KO");
			return ;
		}
	}
	ft_putendl("OK");
}

void	checker(int ac, char **av)
{
	t_lst	*heada;
	t_lst	*headb;
	int		i;

	i = 0;
	heada = NULL;
	headb = NULL;
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
	if (!reader(&heada, &headb))
	{
		ft_solve(heada, headb);
	}
	del_stack(&heada);
	del_stack(&headb);
}

int		main(int ac, char **av)
{
	int i;

	i = 1;
	while (av[i] && ac > 2)
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i]) || ft_strdupl(av, av[i], i))
		{
			ft_putendl("Error");
			return (0);
		}
		i++;
	}
	if (ac == 2)
		do_split(av[1]);
	else if (ac > 2)
		checker(ac, av);
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
