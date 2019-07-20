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
// typedef struct		s_list
// {
// 	struct s_list	*prev;
// 	struct s_list	*next;
// 	int				num;
// 	int				ishead;
// 	int				len;
// }					t_list;
// typedef struct		s_l
// {
// 	struct s_l		*next;
// 	int				num;
// }					t_l;
int					maxint(t_lst *head);
int					minint(t_lst *head);
int					main(int ac, char **av);
int					ft_notvalid(char *s);
void 				del_stack(t_lst **head, int n);
#endif
