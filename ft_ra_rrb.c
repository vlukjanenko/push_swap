/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:34:58 by majosue           #+#    #+#             */
/*   Updated: 2020/02/21 14:08:37 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_list **a, t_list **b, int print)
{
	t_list *head;
	t_list *tmp;

	(void)b;
	if (*a && (*a)->next)
	{
		tmp = *a;
		head = (*a)->next;
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = tmp;
		tmp->next = 0;
		*a = head;
	}
	if (print)
		write(1, "ra\n", 3);
	return (0);
}

int	ft_rb(t_list **a, t_list **b, int print)
{
	t_list *head;
	t_list *tmp;

	(void)a;
	if (*b && (*b)->next)
	{
		tmp = *b;
		head = (*b)->next;
		while ((*b)->next)
			*b = (*b)->next;
		(*b)->next = tmp;
		tmp->next = 0;
		*b = head;
	}
	if (print)
		write(1, "rb\n", 3);
	return (0);
}

int	ft_rr(t_list **a, t_list **b, int print)
{
	ft_ra(a, b, 0);
	ft_rb(a, b, 0);
	if (print)
		write(1, "rr\n", 3);
	return (0);
}

int	ft_rra(t_list **a, t_list **b, int print)
{
	t_list *head;
	t_list *tmp;

	(void)b;
	if (*a && (*a)->next)
	{
		head = *a;
		while ((*a)->next)
		{
			tmp = *a;
			*a = (*a)->next;
		}
		(*a)->next = head;
		tmp->next = 0;
	}
	if (print)
		write(1, "rra\n", 4);
	return (0);
}

int	ft_rrb(t_list **a, t_list **b, int print)
{
	t_list *head;
	t_list *tmp;

	(void)a;
	if (*b && (*b)->next)
	{
		head = *b;
		while ((*b)->next)
		{
			tmp = *b;
			*b = (*b)->next;
		}
		(*b)->next = head;
		tmp->next = 0;
	}
	if (print)
		write(1, "rrb\n", 4);
	return (0);
}
