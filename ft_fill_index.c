/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:44:39 by majosue           #+#    #+#             */
/*   Updated: 2020/02/28 10:46:18 by majosue          ###   ########.fr       */
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

int		ft_fill_array(t_list *a, int **array)
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

int		ft_get_number_of_elements(t_list *a)
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
