/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:47:45 by majosue           #+#    #+#             */
/*   Updated: 2020/02/28 17:03:04 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_rrr(t_list **a, t_list **b, int print)
{
	ft_rra(a, b, 0);
	ft_rrb(a, b, 0);
	if (print)
		write(1, "rrr\n", 4);
	return (0);
}

static void	ft_swap(int **array, int i, int j)
{
	int tmp;

	tmp = (*array)[i];
	(*array)[i] = (*array)[j];
	(*array)[j] = tmp;
}

void		ft_qsort(int **array, int low, int high)
{
	int p;
	int i;

	if (low < high)
	{
		p = high;
		i = low;
		while (i <= p)
		{
			while ((*array)[i] > (*array)[p])
			{
				ft_swap(array, i, --p);
				ft_swap(array, p, p + 1);
			}
			i++;
		}
		ft_qsort(array, low, p - 1);
		ft_qsort(array, p + 1, high);
	}
}
