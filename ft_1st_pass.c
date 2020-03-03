/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1st_pass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:47:47 by majosue           #+#    #+#             */
/*   Updated: 2020/02/29 16:47:57 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* int ft_find_max(t_list *b)
{
	int max;
	
	max = -1;
	if (b)
		max =  ((t_elm*)b->content)->index;
	while (b)
	{
		if (max < ((t_elm*)b->content)->index)
			max = ((t_elm*)b->content)->index;
		b = b->next;
	}
	return (max);
}
 */
int ft_find_min(t_list *b, int el)
{

	int min;
	
	min = -1;
	if (b)
		min =  ((t_elm*)b->content)->index;
	while (b)
	{
		if (min > ((t_elm*)b->content)->index && min > el)
			min = ((t_elm*)b->content)->index;
		b = b->next;
	}
	return (min);
}

static void ft_rotate(t_list **a, t_list **b, int el, int steps)
{
	int q;
	int pos;
	int min = 0;
	
	min = ft_find_min(*b, el);
	pos = ft_get_pos(*b, min);
	q = ft_get_number_of_elements(*b);
	if (pos < q / 2 && steps <= pos && *b && min != ((t_elm*)(*b)->content)->index)	
			ft_rr(a, b, 1);
		else 
			ft_ra(a, b, 1);
}

static void ft_rrotate(t_list **a, t_list **b, int el, int steps)
{
	int q;
	int pos;
	int min = 0;

	min = ft_find_min(*b, el);
	pos = ft_get_pos(*b, min);
	q = ft_get_number_of_elements(*b);
	if (pos >= q / 2 && steps <= q - pos && *b && min != ((t_elm*)(*b)->content)->index)
		{	
				ft_rrr(a, b, 1);
		}
		else 
			ft_rra(a, b, 1);
}
int  ft_get_el(t_list *a, int n)
{
	int i;
	i = -1;
	while (++i < n)
	{
		a = a->next;
	}
return (((t_elm*)a->content)->index);
}



static void ft_correctb(t_list **a, t_list **b, int el)
{
	int q;
	int pos;
	int min = 0;

	min = ft_find_min(*b, el);
	pos = ft_get_pos(*b, min);
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
}

void	ft_push_chunk_to_b(t_list **a, t_list **b, t_sort *n)
{
	int el;
	
	n->n = ft_get_number_of_elements(*a);
	if (n->meet_f <= n->n - n->meet_l)
	{
		while (n->meet_f > 0)
		{
			ft_rotate(a, b, (el = ft_get_el(*a, n->meet_f)), n->meet_f);
			n->meet_f--;
		}	
	}
	else
	{
		while (n->meet_l < n->n)
		{
			ft_rrotate(a, b, (el = ft_get_el(*a, n->meet_f)), n->meet_l);
			n->meet_l++;
		}
	}
	ft_correctb(a, b, el);
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
