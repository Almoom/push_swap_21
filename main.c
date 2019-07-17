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

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	rez;

	i = 0;
	sign = 1;
	rez = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] >= '0'
	&& str[i + 1] <= '9')
		sign = -1 * (str[i++] - 44);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (rez > 922337203685477580)
			return ((1 + sign) / -2);
		if (rez == 922337203685477580 && str[i] - 48 > 8 + (1 + sign) / -2)
			return ((1 + sign) / -2);
		rez = rez * 10 + (str[i++] - '0');
	}
	return ((int)rez * sign);
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

	i = 0;
	t = flag == 0 ? minint(head) : maxint(head);
	tmp = head;
	while (tmp->num != t)
	{
		tmp = tmp->next;
		i++;
	}
	s = i > len / 2 ? "rr" : "r";
	i = i > len / 2 ? len - i : i;
	while (i > 0)
	{
		printf("%s%s\n", s, flag == 0 ? "a" : "b");
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
		printf("rrr: %d\t", heada->rrr);
		printf("\n");
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
			printf("rrr: %d\t", heada->rrr);
			printf("\n");
		}
	}
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
		if (min > h->ra + h->rb + h->rr + h->rra + h->rrb + h->rrr && h->here == 1)
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
	printf("%s\n", flag == 0 ? "rra" : "rrb");
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
	printf("%s\n", flag == 0 ? "ra" : "rb");
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
	printf("%s\n", "rr");
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
	printf("%s\n", "rrr");
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
	printf("%s\n", "pb");
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
		printf("%s\n", "pa");
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

void create_both(t_lst **heada, t_lst **headb, int ac, char **av)
{
	int i;
	int (*cmd)(int, int);
	t_lst *lst;

	i = 0;
	cmd = &ascending;
	while (++i < ac)
	{
		*heada = create_stake(*heada, ft_atoi(av[i]));
		*headb = create_stake(*headb, ft_atoi(av[i]));
	}
	sort_list(*headb, cmd);
	lst = *heada;
	lst->here = 1;
	while (lst->next && lst->next->ishead != 1)
	{
		lst = lst->next;
		lst->here = 1;
	}
}

void del_stack(t_lst **head, int n)
{
	t_lst *t;
	int i;

	t = NULL;
	i = 0;
	while (i < n)
	{
		t = (*head)->next;
		free(*head);
		*head = t;
		i++;
	}
}

void push_swap(int ac, char **av)
{
	t_lst *heada;
	t_lst *headb;
	int i;

	heada = headb = NULL;
	create_both(&heada, &headb, ac, av);
	p_ab(&heada, &headb);
	p_ab(&heada, &headb);
	// print(heada);
	// print(headb);
	i = ac - 3;
	while (i > 0)
	{
		coast_r(heada, headb);
		coast_rr(heada, headb);
		coast_rez(heada);
		//print_coast(heada);
		driver(find_cheap(heada), &heada, &headb);
		zero_coast(heada);
		// print(heada);
		// print(headb);
		i--;
	}
	dosort(headb, 1, ac - 1);
	ft_throw(ac - 1);
	del_stack(&heada, ac - 1);
	del_stack(&headb, ac - 1);
}

void simple_sort(int ac, char **av)
{

}

int main(int ac, char **av)
{
	// 10 3 4 5 9 -2 13 0 6 11 8 -5 -3 -99 1000 18 -11 --58
	// 16 12 17 10 7 9 1 19 8 4 2 15 13 6 20 14 18 5 11 3 --127 --75
	// 20	19	18	17	16	15	14	13	12	11	10	9	8	7	6	5	4	3	2	1

	if (ac > 6)
		push_swap(ac, av);
	else if (ac > 3 && ac <= 6)
		simple_sort(ac, av);
	else if (ac == 3 && ft_atoi(av[1]) > ft_atoi(av[2]))
		printf("%s\n", "sa");
	return (0);
}
