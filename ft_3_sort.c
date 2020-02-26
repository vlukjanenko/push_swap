/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:30:14 by majosue           #+#    #+#             */
/*   Updated: 2020/02/26 13:19:20 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_max_of_3(t_list **a, int *first, int *second, int *bottom)
{
	t_list *head;

	if (*a && (*a)->next)
	{
		head = *a;
		*first = ((t_elm *)(*a)->content)->index;
		*second = ((t_elm *)(*a)->next->content)->index;
		while ((*a)->next)
			(*a) = (*a)->next;
		*bottom = ((t_elm *)(*a)->content)->index;
		*a = head;
		if (*first > *second && *first > *bottom)
			return (1);
		if (*second > *first && *second > *bottom)
			return (2);
	}
	return (3);
}

int		ft_get_min_of_3(t_list **a, int *first, int *second, int *bottom)
{
	t_list *head;

	if (*a && (*a)->next)
	{
		head = *a;
		*first = ((t_elm *)(*a)->content)->index;
		*second = ((t_elm *)(*a)->next->content)->index;
		while ((*a)->next)
			(*a) = (*a)->next;
		*bottom = ((t_elm *)(*a)->content)->index;
		*a = head;
		if (*first < *second && *first < *bottom)
			return (1);
		if (*second < *first && *second < *bottom)
			return (2);
	}
	return (3);
}

void	ft_rotate(t_list **a, t_list **b)
{
	int first;
	int second;
	int bottom;
	int smallest;

	smallest = ft_get_min_of_3(b, &first, &second, &bottom);
	if (smallest == 1)
		ft_rr(a, b, 1);
	else
		ft_ra(a, b, 1);
}

void	ft_swap(t_list **a, t_list **b)
{
	int first;
	int second;
	int bottom;
	int smallest;

	first = 0;
	second = 0;
	bottom = 0;
	smallest = ft_get_min_of_3(b, &first, &second, &bottom);
	if (second > first)
		ft_ss(a, b, 1);
	else
		ft_sa(a, b, 1);
}

void	ft_3_sort(t_list **a, t_list **b)
{
	int first;
	int second;
	int bottom;
	int biggest;

	first = 0;
	second = 0;
	bottom = 0;
	biggest = ft_get_max_of_3(a, &first, &second, &bottom);
	if (biggest == 1)
		ft_rotate(a, b);
	if (biggest == 2 && bottom > first)
	{
		ft_swap(a, b);
		ft_rotate(a, b);
	}
	if (biggest == 2 && bottom < first)
	{
		ft_rra(a, b, 1);
		ft_3_sort(a, b);
	}
	ft_get_max_of_3(a, &first, &second, &bottom);
	if (first > second)
		ft_swap(a, b);
}
