/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:38:15 by majosue           #+#    #+#             */
/*   Updated: 2020/02/28 11:03:25 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_fun	ft_get_f(char *str)
{
	t_fun	f[11];
	int		i;

	f[0] = &ft_sa;
	f[1] = &ft_sb;
	f[2] = &ft_ss;
	f[3] = &ft_pa;
	f[4] = &ft_pb;
	f[5] = &ft_ra;
	f[6] = &ft_rb;
	f[7] = &ft_rr;
	f[8] = &ft_rra;
	f[9] = &ft_rrb;
	f[10] = &ft_rrr;
	i = ft_line_valid(str);
	return (f[i]);
}

int		ft_do_sort(t_list **a, t_list **b, t_list **c)
{
	t_fun	f;
	t_list	*tmp;

	tmp = *c;
	while (tmp)
	{
		f = ft_get_f(tmp->content);
		f(a, b, 0);
		tmp = tmp->next;
	}
	return (0);
}
