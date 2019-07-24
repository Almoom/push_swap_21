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
# include "libft/libft.h"

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



void				do_split(char *s);
int					maxint(t_lst *head);
int					minint(t_lst *head);


#endif
