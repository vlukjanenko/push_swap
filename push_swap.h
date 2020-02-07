/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:43:41 by majosue           #+#    #+#             */
/*   Updated: 2020/02/07 15:12:34 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdio.h> //for debugging

typedef int	(*t_fun)(t_list **, t_list **);
int			ft_read2a(t_list **a, int n, char **str);
int			ft_read2c(t_list **c);
void		del(void *content, size_t size);
void		cleanarr(char ***array);
int			ft_issort(t_list *a, t_list *b);
int			ft_line_valid(char *line);
int			ft_ra(t_list **a, t_list **b);
int			t_rb(t_list **a, t_list **b);
int			ft_rr(t_list **a, t_list **b);
int			ft_rra(t_list **a, t_list **b);
int			ft_rrb(t_list **a, t_list **b);
int			ft_sa(t_list **a, t_list **b);
int			ft_sb(t_list **a, t_list **b);
int			ft_ss(t_list **a, t_list **b);
int			ft_pb(t_list **a, t_list **b);
int			ft_pa(t_list **a, t_list **b);
int			ft_rrr(t_list **a, t_list **b);
int			ft_issort(t_list *a, t_list *b);
t_fun		ft_get_f(char *str);
int			ft_do_sort(t_list **a, t_list **b, t_list **c);

#endif
