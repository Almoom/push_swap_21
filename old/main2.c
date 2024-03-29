/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:13:24 by ljalikak          #+#    #+#             */
/*   Updated: 2019/06/19 14:13:26 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void print(t_lst *tmp)
{
	if (!tmp)
	{
		printf("%s\n", "NULL");
		return ;
	}
	//if (tmp->here == 1)
		printf("%d\t", tmp->num);
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		//if (tmp->here == 1)
			printf("%d\t", tmp->num);
	}
	printf("\n");
}

int ft_notvalid(char *s)
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

int ft_lenstack(t_lst *h)
{
	int i;

	i = 1;
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		i++;
	}
	return (i);
}

void del_stack(t_lst **head)
{
	t_lst *t;
	int i;
	int len;

	if (!(*head))
		return ;
	len = ft_lenstack(*head);
	t = NULL;
	i = 0;
	while (i < len)
	{
		t = (*head)->next;
		free(*head);
		*head = t;
		i++;
	}
}

t_lst	*create_list(int num, int ishead)
{
	t_lst *list;

	if (!(list = (t_lst*)malloc(sizeof(*list))))
		return (NULL);
	list->num = num;
	list->ishead = ishead;
	list->here = 0;
	list->prev = NULL;
	list->next = NULL;
	list->ra = 0;
	list->rb = 0;
    list->rr = 0;
    list->rrb = 0;
    list->rra = 0;
    list->rrr = 0;
	return (list);
}

t_lst *create_stake(t_lst *head, int n)
{
	t_lst *tmp;
	t_lst *list;

	list = NULL;
	tmp = head;
	if (!head)
		head = create_list(n, 1);
	else
	{
		while (tmp->next && tmp->next->ishead != 1)
			tmp = tmp->next;
		list = create_list(n, 0);
		tmp->next = list;
		list->prev = tmp;
		list->next = head;
		head->prev = list;
	}
	return (head);
}

int ft_valid_op(char *s)
{
	if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rra")
	|| !ft_strcmp(s, "rrb") || !ft_strcmp(s, "rr") || !ft_strcmp(s, "rrr")
	|| !ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "ss")
	|| !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb"))
		return (1);
	return (0);
}

void del_split(char **s, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void ft_rab(t_lst **head)
{
	if (!(*head) || !(*head)->next)
		return ;
	(*head)->ishead = 0;
	(*head) = (*head)->next;
	(*head)->ishead = 1;
}

void ft_rr(t_lst **heada, t_lst **headb)
{
	ft_rab(heada);
	ft_rab(headb);
}

void ft_rrab(t_lst **head)
{
	if (!(*head) || !(*head)->prev)
		return ;
	(*head)->ishead = 0;
	(*head) = (*head)->prev;
	(*head)->ishead = 1;
}

void ft_rrr(t_lst **heada, t_lst **headb)
{
	ft_rrab(heada);
	ft_rrab(headb);
}

void ft_sab(t_lst **head)
{
	int t;


	if (!(*head) || !(*head)->next)
		return ;
	t = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = t;
}

void ft_ss(t_lst **heada, t_lst **headb)
{
	ft_sab(heada);
	ft_sab(headb);
}

t_lst *ft_dellist(t_lst *h)
{
	t_lst *next;
	t_lst *prev;

	next = prev = NULL;
	if (!h)
		return (NULL);
	if ((h)->next && (h)->next == (h)->prev)
	{
		next = (h)->next;
		next->ishead = 1;
		next->next = NULL;
		next->prev = NULL;
	}
	else if ((h)->next && (h)->prev)
	{
		next = (h)->next;
		prev = (h)->prev;
		next->prev = prev;
		prev->next = next;
		next->ishead = 1;

	}
	free(h);
	h = NULL;
	return (next);
}

t_lst *list_before(t_lst *head, int n)
{
	t_lst *list;

	list = NULL;
	if (!head)
		list = create_list(n, 1);
	else
	{
		list = create_list(n, 1);
		head->ishead = 0;
		if (head->prev && head->next)
		{
			head->prev->next = list;
			list->prev = head->prev;
			list->next = head;
			head->prev = list;
		}
		else
		{
			list->next = head;
			list->prev = head;
			head->next = list;
			head->prev = list;
		}
	}
	return (list);
}

void ft_p(t_lst **from, t_lst **to)
{
	if (!(*from))
		return ;
	*to = list_before(*to, (*from)->num);
	*from = ft_dellist(*from);
}

void ft_build(t_lst **heada, t_lst **headb, char *s)
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
	// printf("%s\n", s);
	// print(*heada);
	// print(*headb);
}

int reader(t_lst **heada, t_lst **headb)
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

void ft_solve(t_lst *heada, t_lst *headb)
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

int ft_dupl(t_lst *h, int n)
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

void checker(int ac, char **av)
{
	t_lst *heada;
	t_lst *headb;
	int i;

	i = 0;
	heada = headb = NULL;
	while (++i < ac)
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i])
		|| ft_dupl(heada, ft_atoi(av[i])))
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

int ft_isint2(char *s, int n, int len, int minus)
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

int ft_isint(char *s)
{
	int i;
	int j;
	int flag;
	int minus;

	i = j = flag = minus = 0;
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
		if (ft_isdigit(s[i]))
		{
			flag = 1;
			j++;
		}
		i++;
	}
	return (ft_isint2(s, i - j, j, minus));
}

int ft_strdupl(char **av, char *s, int n)
{
	int i;

	i = 1;
	while (i < n)
	{
		//printf("%s--%s\n", av[i], s);
		if (!ft_strcmp(av[i], s))
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	// 10 3 4 5 9 -2 13 0 6 11 8 -5 -3 -99 1000 18 -11 --58
	// 16 12 17 10 7 9 1 19 8 4 2 15 13 6 20 14 18 5 11 3 --127 --75
	int i;

	i = 1;
	while (av[i] && ac > 2)
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i]) || ft_strdupl(av, av[i], i))
		{
			//printf("%d--%d--%d\n", ft_notvalid(av[i]), !ft_isint(av[i]), ft_strdupl(av, av[i], i));
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

void do_split(char *s)
{
	char **av;
	char *t[10000];
	int i;

	i = -1;
	if (!ft_strcmp(s, " "))
	{
		ft_putendl("Error");
		return ;
	}
	av = ft_strsplit(s, ' ');
	while (av[++i])
	{
		if (ft_notvalid(av[i]) || !ft_isint(av[i]))
		{
			ft_putendl("Error");
			del_split(av, i + 1);
			return ;
		}
		t[i + 1] = av[i];
	}
	t[i + 1] = 0;
	if (i > 1)
		main(i + 1, t);
	del_split(av, i);
}
