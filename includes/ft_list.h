/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljalikak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:14:21 by ljalikak          #+#    #+#             */
/*   Updated: 2019/06/19 14:14:22 by ljalikak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_lst
{
	struct s_lst	*prev;
	struct s_lst	*next;
	int				num;
	int				ishead;
	int				here;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_lst;

/*
**	common_valid.c
*/

int					ft_notvalid(char *s);
int					ft_strdupl(char **av, char *s, int n);
int					ft_intdupl(t_lst *h, int n);
int					ft_isint(char *s);
int					ft_isint2(char *s, int n, int len, int minus);

/*
**	common_born_kill_stack.c
*/

int					ft_lenstack(t_lst *h);
void				del_stack(t_lst **head);
t_lst				*create_list(int num, int ishead);
t_lst				*create_stake(t_lst *head, int n);
void				del_split(char **s);

/*
**	push_swap2.c
*/

int					find_rb(int num, t_lst *headb);
void				coast_r(t_lst *heada, t_lst *headb);
int					find_rrb(int num, t_lst *headb);
void				coast_rr(t_lst *heada, t_lst *headb);
void				coast_rez(t_lst *h);

/*
**	push_swap3.c
*/

t_lst				*find_cheap(t_lst *h);
void				three_zero(t_lst *h, int flag);
int					maxint(t_lst *head);
int					maxint2(t_lst *head);
int					minint(t_lst *head);

/*
**	push_swap4.c
*/

void				rr_ab(t_lst **head, int flag);
void				r_ab(t_lst **head, int flag);
void				rr(t_lst **heada, t_lst **headb);
void				rrr(t_lst **heada, t_lst **headb);
void				p_ab(t_lst **heada, t_lst **headb);

/*
**	push_swap5.c
*/

void				zero_coast(t_lst *h);
void				driver(t_lst *min, t_lst **heada, t_lst **headb);
void				ft_throw(int n);
void				ft_here(t_lst *h);
int					solver(t_lst *heada);

/*
**	push_swap6.c
*/

t_lst				*rr_aorb(t_lst *head, int flag);
t_lst				*r_aorb(t_lst *head, int flag);
t_lst				*s_aorb(t_lst *head, int flag);
t_lst				*sort_list(t_lst *lst, int (*cmp)(int, int));
int					ascending(int a, int b);

/*
**	push_swap7.c
*/

int					create_both
					(t_lst **heada, t_lst **headb, int ac, char **av);
t_lst				*del_list(t_lst *h);
int					sort(t_lst **h, int l, int z, int f);
void				simple_sort(int ac, char **av, int flag);
void				spasi_i_sohrani(t_lst *h, int l, int flag);

/*
**	checker2.c
*/

void				ft_rab(t_lst **head);
void				ft_rr(t_lst **heada, t_lst **headb);
void				ft_rrab(t_lst **head);
void				ft_rrr(t_lst **heada, t_lst **headb);
void				ft_sab(t_lst **head);

/*
**	checker3.c
*/

void				ft_ss(t_lst **heada, t_lst **headb);
void				ft_p(t_lst **from, t_lst **to);
void				ft_build(t_lst **heada, t_lst **headb, char *s);
int					ft_valid_op(char *s);

/*
**	checker4.c
*/

t_lst				*ft_dellist(t_lst *h);
t_lst				*list_before(t_lst *head, int n);

int					check(t_lst *head, int min, int len);
void				dosort(t_lst *head, int flag, int len);
void				do_split(char *s);
void				do_split2(char *s);
#endif
