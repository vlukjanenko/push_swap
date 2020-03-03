/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 11:59:43 by majosue           #+#    #+#             */
/*   Updated: 2020/03/03 11:17:30 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_draw_separator(t_mlx *mlx)
{
	t_point p1;
	t_point p2;

	p1.color = 0xFFFFFF;
	p1.x = WIN_WIDTH / 2;
	p1.y = 0;
	p2.x = WIN_WIDTH / 2;
	p2.y = WIN_HEIGHT;
	ft_draw_line(mlx, p1, p2);
}

void	ft_draw_stack(t_list *a, t_mlx *mlx, int pos)
{
	int		h;
	t_point	p1;
	t_point	p2;

	h = mlx->bar_h;
	p1.x = pos ? WIN_WIDTH / 2 + 1 : 0;
	p1.y = COL;
	while (a)
	{
		while (p1.y < h)
		{
			p2.x = (((t_elm *)a->content)->index + 1) * mlx->scale_w +\
			(pos ? WIN_WIDTH / 2 + 1 : 0);
			p2.y = p1.y;
			p1.color = ((t_elm *)a->content)->color.composite;
			ft_draw_line(mlx, p1, p2);
			(p1.y)++;
		}
		h += mlx->bar_h;
		a = a->next;
	}
}

void	ft_draw_black(t_mlx *mlx)
{
	int i;
	int m;

	i = COL * WIN_WIDTH - 1;
	m = WIN_HEIGHT * WIN_WIDTH;
	while (++i < m)
	{
		mlx->img.data[i] = 0;
	}
	ft_draw_separator(mlx);
}

int		ft_do_beutifull_sort(t_mlx *mlx)
{
	t_fun f;

	ft_draw_black(mlx);
	ft_draw_stack(mlx->a, mlx, 0);
	ft_draw_stack(mlx->b, mlx, 1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win, 150, 10, 0xFFFFFFFF, "Stack - A");
	mlx_string_put(mlx->mlx_ptr, mlx->win, (WIN_WIDTH + 1) / 2 + 150, 10,\
	0xFFFFFFFF, "Stack - B");
	sleep(mlx->delay);
	if (mlx->c)
	{
		f = ft_get_f((mlx->c)->content);
		f(&(mlx->a), &(mlx->b), 0);
		mlx->c = (mlx->c)->next;
	}
	return (0);
}
