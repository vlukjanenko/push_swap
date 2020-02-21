/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:42:33 by majosue           #+#    #+#             */
/*   Updated: 2020/02/21 21:52:47 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_number_of_elements(t_list *a)
{
	int i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void ft_fill_index(t_list **a, int *array, int n)
{
	t_list *head;
	int i;

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

int ft_get_pos(t_list *a, int index)
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

int ft_fill_array(t_list *a, int **array)
{
	int i;

	i = 0;
	while (a)
	{
		(*array)[i] = ((t_elm *)a->content)->number;
		i++;
		a = a->next;
	}
	ft_qsort(array, 0, i - 1);
	return (0);
}

int ft_get_max_of_3(t_list **a, int *first, int *second, int *bottom)
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

int ft_get_min_of_3(t_list **a, int *first, int *second, int *bottom)
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

void ft_rotate(t_list **a, t_list **b)
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
void ft_swap(t_list **a, t_list **b)
{
	int first;
	int second;
	int bottom;
	int smallest;

	smallest = ft_get_min_of_3(b, &first, &second, &bottom);

	if (second > first)
		ft_ss(a, b, 1);
	else
		ft_sa(a, b, 1);
}

void ft_3_sort(t_list **a, t_list **b)
{
	int first;
	int second;
	int bottom;
	int biggest;

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

int ft_chunk_exist_in_a(t_list *a, int chunk, t_sort *n)
{
	int pos;
	
	n->meet_f = -1;
	n->meet_l = -1;
	pos = 0;
	while (a)
	{
		if (((t_elm*)a->content)->chunk == chunk && n->meet_f == -1)
			n->meet_f = pos;
		if (((t_elm*)a->content)->chunk == chunk && n->meet_f != -1)
			n->meet_l = pos;
		pos++;
		a = a->next;
	}
	if (n->meet_f == -1)
		return (0);
	return (1);
}
void ft_push_chunk_to_b(t_list **a, t_list **b, t_sort *n)
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
void ft_1st_pass(t_list **a, t_list **b, t_sort *n)
{
	int chunk;

	(void)a;
	(void)b;
	(void)n;
	
	chunk = 0;
	while (*a)
	{
		while(ft_chunk_exist_in_a(*a, chunk, n))
			{
				ft_push_chunk_to_b(a, b, n);
			}
		chunk++;
	}
}
void ft_2nd_pass(t_list **a, t_list **b, int n)
{
	int pos;
	int q;
	int bottom_a;
	
	n = ft_get_number_of_elements(*b) - 1;
	while (n >= 0)
	{
		pos = ft_get_pos(*b, n);
		q = ft_get_number_of_elements(*b);
		ft_get_max_of_3(a, &bottom_a, &bottom_a, &bottom_a); 
		if (pos < q / 2)
		{
			while (pos > 0)
			{
				ft_rb(a, b, 1);
				pos--;
			}
		}
		else
		{
			while (pos < q)
			{
				ft_rrb(a, b, 1);
				pos++;
			}
		}
			ft_pa(a, b, 1);
			n--;
	 }
}

void ft_fill_chunks(t_list **a, t_sort *n)
{
	t_list *head;
	int in_chunk;
	
	if (n->n <= 100)
		n->chunks = 5;
	else 
		n->chunks = 11;
	in_chunk = n->n / n->chunks;
	in_chunk = !in_chunk ? 1 : in_chunk;
	head = *a;
	while (*a)
	{
		((t_elm*)(*a)->content)->chunk = ((t_elm*)(*a)->content)->index / in_chunk;
		(*a) = (*a)->next;
	}
	*a = head;
}

int ft_generator(t_list **a, t_list **b)
{
	int *array;
	t_sort n;

	n.n = ft_get_number_of_elements(*a);
	if (!(array = (int *)malloc(sizeof(int) * n.n)))
		return (1);
	ft_fill_array(*a, &array);
	ft_fill_index(a, array, n.n);
	ft_fill_chunks(a, &n);
	ft_1st_pass(a, b, &n);
	ft_2nd_pass(a, b, n.n);
	free(array);
	return (0);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	
	b = 0;
	a = 0;
	if (argc < 2)
		return (0);
	if (ft_read2a(&a, argc, argv, 1))
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
	a ? ft_lstdel(&a, del) : a;
	b ? ft_lstdel(&b, del) : b;
}
