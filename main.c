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
	if (tmp->here == 1)
		printf("%d\t", tmp->num);
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		if (tmp->here == 1)
			printf("%d\t", tmp->num);
	}
	printf("\n");
}

void print_coast(t_lst *heada)
{
	if (heada->here == 1)
	{
		printf("%d->\t", heada->num);
		printf("ra: %d\t", heada->ra);
		printf("rb: %d\t", heada->rb);
		printf("rr: %d\t", heada->rr);
		printf("rra: %d\t", heada->rra);
		printf("rrb: %d\t", heada->rrb);
		printf("rrr: %d\t\n", heada->rrr);
	}
	while (heada->next && heada->next->ishead != 1)
	{
		heada = heada->next;
		if (heada->here == 1)
		{
			printf("%d->\t", heada->num);
			printf("ra: %d\t", heada->ra);
			printf("rb: %d\t", heada->rb);
			printf("rr: %d\t", heada->rr);
			printf("rra: %d\t", heada->rra);
			printf("rrb: %d\t", heada->rrb);
			printf("rrr: %d\t\n", heada->rrr);
		}
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

void dosort(t_lst *head, int flag, int len)
{
	int		i;
	t_lst	*tmp;
	char	*s;
	int t;

	i = 1;
	t = flag == 0 ? minint(head) : maxint(head);
	//printf("%d--\n", len);
	tmp = head;
	while (tmp->num != t)
	{
		tmp = tmp->next;
		i++;
	}
	//printf("%d--\n", i);
	s = i - 1 > len / 2 ? "rr" : "r";
	i = i - 1 > len / 2 ? len - (i - 1) : i - 1;
	//printf("%d--\n", i);
	while (i > 0)
	{
		ft_putstr(s);
		ft_putendl(flag == 0 ? "a" : "b");
		i--;
	}
}

int minint(t_lst *head)
{
    t_lst	*tmp;
    int		min;

    tmp = head;
    min = head->num;
    while (tmp->next && tmp->next->ishead != 1)
    {
        tmp = tmp->next;
        if (min > tmp->num)
            min = tmp->num;
    }
    return (min);
}

int maxint(t_lst *head)
{
	t_lst	*tmp;
	int		max;

	tmp = head;
	max = head->num;
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		if (max < tmp->num)
			max = tmp->num;
	}
	return (max);
}

int maxint2(t_lst *head)
{
	t_lst	*tmp;
	int		max;

	tmp = head;
	max = head->num;
	while (tmp->next && tmp->next->ishead != 1)
	{
		tmp = tmp->next;
		if (max < tmp->num && tmp->num != maxint(head))
			max = tmp->num;
	}
	return (max);
}

int find_rb(int num, t_lst *headb)
{
	int i;

	i = 0;
	if (headb->here == 1)
		i++;
	if (num == headb->num)
		return(i);
	while (headb->next && headb->next->ishead != 1)
	{
		headb = headb->next;
		if (headb->here == 1)
			i++;
		if (num == headb->num)
			return(i);
	}
	return (i);
}

void coast_r(t_lst *heada, t_lst *headb)
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

int find_rrb(int num, t_lst *headb)
{
	int i;

	i = 0;
	while (headb->prev && headb->prev->ishead != 1)
	{
		headb = headb->prev;
		if (num == headb->num)
			return(i);
		if (headb->here == 1)
			i++;
	}
	return (i);
}

void coast_rr(t_lst *heada, t_lst *headb)
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

void coast_rez(t_lst *h)
{
	if (!(h->ra + h->rb + h->rr == 0 || h->rra + h->rrb + h->rrr == 0))
	{
		if (h->ra + h->rb + h->rr < h->rra + h->rrb + h->rrr)
			h->rra = h->rrb = h->rrr = 0;
		else
			h->ra = h->rb = h->rr = 0;
	}
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		if (h->ra + h->rb + h->rr == 0 || h->rra + h->rrb + h->rrr == 0)
			continue ;
		if (h->ra + h->rb + h->rr < h->rra + h->rrb + h->rrr)
			h->rra = h->rrb = h->rrr = 0;
		else
			h->ra = h->rb = h->rr = 0;
	}
}

t_lst *find_cheap(t_lst *h)
{
	int min;
	t_lst *it;

	it = h;
	min = h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr;
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		if (min > h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr
			&& h->here == 1)
		{
			min = h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr;
			it = h;
		}
	}
	return (it);
}

void rr_ab(t_lst **head, int flag)
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

void r_ab(t_lst **head, int flag)
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

void rr(t_lst **heada, t_lst **headb)
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

void rrr(t_lst **heada, t_lst **headb)
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

void p_ab(t_lst **heada, t_lst **headb)
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
			break;
		}
		lst = lst->next;
	}
	ft_putendl("pb");
}

void zero_coast(t_lst *h)
{
	h->ra = h->rb = h->rr = h->rra = h->rrb = h->rrr = 0;
	while (h->next && h->next->ishead != 1)
	{
		h = h->next;
		h->ra = h->rb = h->rr = h->rra = h->rrb = h->rrr = 0;
	}
}

void driver(t_lst *min, t_lst **heada, t_lst **headb)
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

void ft_throw(int n)
{
	int i;

	i = -1;
	while (++i < n)
		ft_putendl("pa");
}

t_lst	*sort_list(t_lst* lst, int (*cmp)(int, int))
{
	t_lst *tmp;
	int swap;

	tmp = lst;
	while (lst->next && lst->next->ishead != 1)
	{
		if (!cmp(lst->num, lst->next->num))
		{
			swap = lst->next->num;
			lst->next->num = lst->num;
			lst->num = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	return (tmp);
}

int ascending(int a, int b)
{
	return (a > b);
}

void ft_here(t_lst *h)
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

int create_both(t_lst **heada, t_lst **headb, int ac, char **av)
{
	int i;
	int (*cmd)(int, int);


	i = 0;
	cmd = &ascending;
	while (++i < ac)
	{
		if (ft_notvalid(av[i]))
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

int solver(t_lst *heada)
{
	int n;

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

void push_swap(int ac, char **av)
{
	t_lst *heada;
	t_lst *headb;
	int i;

	heada = headb = NULL;
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

t_lst *rr_aorb(t_lst *head, int flag)
{
	head->ishead = 0;
	head = head->prev;
	head->ishead = 1;
	ft_putendl(flag == 0 ? "rra" : "rrb");
	return (head);
}

t_lst *r_aorb(t_lst *head, int flag)
{
	head->ishead = 0;
	head = head->next;
	head->ishead = 1;
	ft_putendl(flag == 0 ? "ra" : "rb");
	return (head);
}

t_lst *s_aorb(t_lst *head, int flag)
{
	int t;

	t = head->num;
	head->num = head->next->num;
	head->next->num = t;
	ft_putendl(flag == 0 ? "sa" : "sb");
	return (head);
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

t_lst *del_list(t_lst *h)
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

int sort(t_lst **h, int l, int z, int f)
{
	int i;
	int flag;
	int y;

	i = flag = 0;
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
	dosort(*h, 0, l);
	ft_putstr(flag == 1 ? "sb\n" : "");
	return (i);
}

void simple_sort(int ac, char **av, int flag)
{
	t_lst *heada;
	int i;

	i = 0;
	heada = NULL;
	while (++i < ac)
	{
		if (ft_notvalid(av[i]))
		{
			ft_putendl("Error");
			del_stack(&heada);
			return ;
		}
		heada = create_stake(heada, ft_atoi(av[i]));
	}
	//ft_here(heada);
	i = sort(&heada, ac - 1, maxint(heada), flag);
	del_stack(&heada);
	while (i-- > 0)
		ft_putstr("pa\nra\n");
}

void del_split(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
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
		//printf("%s", s);
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
	// int i;
	//
	// i = 0;
	// while (++i < ac)
	// 	printf("%s ", av[i]);
	// printf("\n");
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
