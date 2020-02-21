/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:33:36 by majosue           #+#    #+#             */
/*   Updated: 2020/02/21 14:07:20 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_list **a, t_list **b, int print)
{
	void *tmp;

	(void)b;
	if (*a && (*a)->next)
	{
		tmp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = tmp;
	}
	if (print)
		write(1, "sa\n", 3);
	return (0);
}

int	ft_sb(t_list **a, t_list **b, int print)
{
	void *tmp;

	(void)a;
	if (*b && (*b)->next)
	{
		tmp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = tmp;
	}
	if (print)
		write(1, "sb\n", 3);
	return (0);
}

int	ft_ss(t_list **a, t_list **b, int print)
{
	ft_sa(a, b, 0);
	ft_sb(a, b, 0);
	if (print)
		write(1, "ss\n", 3);
	return (0);
}

int	ft_pb(t_list **a, t_list **b, int print)
{
	t_list *tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		if (*b)
			*b = tmp;
		else
			tmp->next = 0;
		*b = tmp;
	}
	if (print)
		write(1, "pb\n", 3);
	return (0);
}

int	ft_pa(t_list **a, t_list **b, int print)
{
	t_list *tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		if (*a)
			*a = tmp;
		else
			tmp->next = 0;
		*a = tmp;
	}
	if (print)
		write(1, "pa\n", 3);
	return (0);
}
