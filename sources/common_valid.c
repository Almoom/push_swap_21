/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:13:17 by ljalikak          #+#    #+#             */
/*   Updated: 2019/07/24 16:13:20 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_notvalid(char *s)
{
	int i;

	i = 0;
	if (!s[1] && !ft_isdigit(s[0]))
		return (1);
	while (s[i])
	{
		if (s[i + 1] && (s[i] == '-' || s[i] == '+') && ft_isdigit(s[i + 1]))
			i++;
		if (!ft_isdigit(s[i]) && s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int		ft_strdupl(char **av, char *s, int n)
{
	int i;

	i = 1;
	while (i < n)
	{
		if (!ft_strcmp(av[i], s))
			return (1);
		i++;
	}
	return (0);
}

int		ft_intdupl(t_lst *h, int n)
{
	if (!h)
		return (0);
	if (n == h->num)
		return (1);
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		if (n == h->num)
			return (1);
	}
	return (0);
}

int		ft_isint2(char *s, int n, int len, int minus)
{
	int i;

	i = 0;
	while (i < n)
	{
		s++;
		i++;
	}
	if (len < 10)
		return (1);
	if (len == 10)
	{
		if (minus && ft_strcmp(s, "2147483648") <= 0)
			return (1);
		if (!minus && ft_strcmp(s, "2147483647") <= 0)
			return (1);
	}
	return (0);
}

int		ft_isint(char *s)
{
	int i;
	int j;
	int flag;
	int minus;

	i = 0;
	j = 0;
	flag = 0;
	minus = 0;
	while (s[i])
	{
		if (i == 0 && s[i] == '-')
			minus = 1;
		if (i == 0 && (s[i] == '-' || s[i] == '+') && !ft_isdigit(s[i + 1]))
			i++;
		while (s[i] == '0' && flag == 0)
			i++;
		if (!s[i])
			return (1);
		if (ft_isdigit(s[i]) && j++ <= i)
			flag = 1;
		i++;
	}
	return (ft_isint2(s, i - j, j, minus));
}
