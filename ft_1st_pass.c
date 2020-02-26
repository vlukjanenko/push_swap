/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1st_pass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:47:47 by majosue           #+#    #+#             */
/*   Updated: 2020/02/26 12:08:52 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_index(t_list **a, int *array, int n)
{
	t_list	*head;
	int		i;

	head = *a;
	i = -1;
	while (++i < n)
	{
		while (((t_elm *)(*a)->content)->number != array[i])
			*a = (*a)->next;
		((t_elm *)(*a)->content)->index = i;
		*a = head;
	}
}

void	ft_fill_chunks(t_list **a, t_sort *n)
{
	t_list	*head;
	int		q;

	if (n->n <= 100)
		n->chunks = 5;
	else
		n->chunks = 11;
	q = n->n / n->chunks;
	q = !q ? 1 : q;
	head = *a;
	while (*a)
	{
		((t_elm *)(*a)->content)->chunk = ((t_elm *)(*a)->content)->index / q;
		(*a) = (*a)->next;
	}
	*a = head;
}

int		ft_chunk_exist_in_a(t_list *a, int chunk, t_sort *n)
{
	int pos;

	n->meet_f = -1;
	n->meet_l = -1;
	pos = 0;
	while (a)
	{
		if (((t_elm *)a->content)->chunk == chunk && n->meet_f == -1)
			n->meet_f = pos;
		if (((t_elm *)a->content)->chunk == chunk && n->meet_f != -1)
			n->meet_l = pos;
		pos++;
		a = a->next;
	}
	if (n->meet_f == -1)
		return (0);
	return (1);
}

void	ft_push_chunk_to_b(t_list **a, t_list **b, t_sort *n)
{
	n->n = ft_get_number_of_elements(*a);
	if (n->meet_f <= n->n - n->meet_l)
	{
		while (n->meet_f > 0)
		{
			ft_ra(a, b, 1);
			n->meet_f--;
		}
	}
	else
	{
		while (n->meet_l < n->n)
		{
			ft_rra(a, b, 1);
			n->meet_l++;
		}
	}
	ft_pb(a, b, 1);
}

void	ft_1st_pass(t_list **a, t_list **b, t_sort *n)
{
	int chunk;

	chunk = 0;
	while (*a)
	{
		while (ft_chunk_exist_in_a(*a, chunk, n))
		{
			ft_push_chunk_to_b(a, b, n);
		}
		chunk++;
	}
}
