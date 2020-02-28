/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:33:18 by majosue           #+#    #+#             */
/*   Updated: 2020/02/28 16:51:57 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double			percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

unsigned char	get_light(unsigned char start, unsigned char end, double pnt)
{
	return ((unsigned char)((1 - pnt) * start + pnt * end));
}

void			ft_set_light(t_color *result, double percentage)
{
	t_color start;
	t_color end;

	start.composite = START_COLOUR;
	end.composite = END_COLOUR;
	result->color[0] = get_light((start.color)[0], (end.color)[0], percentage);
	result->color[1] = get_light((start.color)[1], (end.color)[1], percentage);
	result->color[2] = get_light((start.color)[2], (end.color)[2], percentage);
	result->color[3] = 0;
}

void			ft_fill_color(t_mlx *mlx)
{
	int		end;
	t_list	*head;
	double	p;

	head = mlx->a;
	end = ft_get_number_of_elements(mlx->a) - 1;
	while (head)
	{
		p = percent(0, end, ((t_elm *)head->content)->index);
		ft_set_light(&((t_elm *)head->content)->color, p);
		head = head->next;
	}
}
