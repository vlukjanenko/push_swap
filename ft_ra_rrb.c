/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rrb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:34:58 by majosue           #+#    #+#             */
/*   Updated: 2020/02/07 15:04:05 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_list **a, t_list **b)
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
	return (0);
}

int	ft_rb(t_list **a, t_list **b)
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
	return (0);
}

int	ft_rr(t_list **a, t_list **b)
{
	ft_ra(a, b);
	ft_rb(a, b);
	return (0);
}

int	ft_rra(t_list **a, t_list **b)
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
	return (0);
}

int	ft_rrb(t_list **a, t_list **b)
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
	return (0);
}
