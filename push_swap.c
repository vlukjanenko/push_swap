/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:42:33 by majosue           #+#    #+#             */
/*   Updated: 2020/02/28 11:13:12 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_0_pass(t_list **a, t_list **b)
{
	int sort;

	ft_3_sort(a, b);
	while ((sort = ft_issorta(*a)) || *b)
	{
		if (sort == 1)
		{
			ft_pb(a, b, 1);
		}
		else
		{
			ft_pa(a, b, 1);
		}
		ft_3_sort(a, b);
	}
}

int		ft_generator(t_list **a, t_list **b)
{
	int		*array;
	t_sort	n;

	n.n = ft_get_number_of_elements(*a);
	if (!(array = (int *)malloc(sizeof(int) * n.n)))
		return (1);
	ft_fill_array(*a, &array);
	ft_fill_index(a, array, n.n);
	if (n.n <= 5)
	{
		ft_0_pass(a, b);
	}
	else
	{
		ft_fill_chunks(a, &n);
		ft_1st_pass(a, b, &n);
		ft_2nd_pass(a, b, n.n);
	}
	free(array);
	return (0);
}

void	free_stacks(t_list **a, t_list **b)
{
	*a ? ft_lstdel(a, del) : *a;
	*b ? ft_lstdel(b, del) : *b;
}

void	ft_init_stacks_debug(t_list **a, t_list **b, t_trigger *d)
{
	*a = 0;
	*b = 0;
	d->print = 1;
	d->debug = 0;
}

int		main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_trigger	d;

	ft_init_stacks_debug(&a, &b, &d);
	if (argc < 2)
		return (0);
	if (ft_read2a(&a, argc, argv, d))
	{
		a ? ft_lstdel(&a, del) : a;
		write(2, "Error\n", 6);
		return (0);
	}
	if (!(ft_issort(a, b)))
	{
		a ? ft_lstdel(&a, del) : a;
		return (0);
	}
	if (ft_generator(&a, &b))
	{
		a ? ft_lstdel(&a, del) : a;
		write(2, "Error\n", 6);
		return (0);
	}
	free_stacks(&a, &b);
}
