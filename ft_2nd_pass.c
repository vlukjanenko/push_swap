/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2nd_pass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:55:53 by majosue           #+#    #+#             */
/*   Updated: 2020/02/29 16:03:11 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_pos(t_list *a, int index)
{
	int i;

	i = 0;
	while (a)
	{
		if (((t_elm *)a->content)->index == index)
			return (i);
		a = a->next;
		i++;
	}
	return (0);
}

void	ft_2nd_pass(t_list **a, t_list **b, int n)
{
	int pos;
	int q;

	n = ft_get_number_of_elements(*b) - 1;
	while (n >= 0)
	{
		pos = ft_get_pos(*b, n);
		//printf("next from top b %d, from bottom - %d\n", pos, n - pos);
				//------------
				
		q = ft_get_number_of_elements(*b);
		if (pos < q / 2)
		{
			pos++;
			while (--pos > 0)
				ft_rb(a, b, 1);
		}
		else
		{
			pos--;
			while (++pos < q)
				{
						ft_rrb(a, b, 1);
				}
		}
		ft_pa(a, b, 1);
		n--;
	}
}
