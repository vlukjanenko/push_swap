/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:06:02 by majosue           #+#    #+#             */
/*   Updated: 2020/02/26 18:07:38 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_issorta(t_list *a)
{
	while (a && a->next)
	{
		if (((t_elm *)a->content)->index > ((t_elm *)a->next->content)->index)
			return (1);
		a = a->next;
	}
	return (0);
}

int		ft_issort(t_list *a, t_list *b)
{
	while (a && a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (1);
		a = a->next;
	}
	if (b)
		return (1);
	return (0);
}

void	del(void *content, size_t size)
{
	if (content)
	{
		ft_bzero(content, size);
		ft_memdel(&content);
	}
}

void	cleanarr(char ***array)
{
	char **tmp;

	if (*array)
	{
		tmp = *array;
		while (**array)
		{
			free(**array);
			(*array)++;
		}
		free(tmp);
	}
}
