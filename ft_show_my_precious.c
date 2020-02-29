/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_my_precious.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:50:18 by majosue           #+#    #+#             */
/*   Updated: 2020/02/29 11:10:21 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_close(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx->a ? ft_lstdel(&mlx->a, del) : mlx->a;
	mlx->b ? ft_lstdel(&mlx->b, del) : mlx->b;
	mlx->head_c ? ft_lstdel(&mlx->head_c, del) : mlx->head_c;
	exit(0);
}

int		ft_mlx_init(t_mlx *mlx, char *name, t_list **c)
{
	int n;

	n = ft_get_number_of_elements(mlx->a);
	if (!(mlx->mlx_ptr = mlx_init()) ||\
!(mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, name)) ||\
!(mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr,\
	&mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
	mlx->c = *c;
	mlx->head_c = *c;
	mlx->bar_h = ((WIN_HEIGHT - COL) / n) < 2 ? 2 :\
	((WIN_HEIGHT - COL) / n);
	mlx->scale_w = ((WIN_WIDTH - 1) / 2) / (float)n;
	if (n < 50)
		mlx->delay = 1;
	else
		mlx->delay = 0;
	return (0);
}

void	ft_events(t_mlx *mlx)
{
	mlx_hook(mlx->win, 17, 1l << 17, ft_close, mlx);
	mlx_loop_hook(mlx->mlx_ptr, ft_do_beutifull_sort, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int		ft_show_my_precious(int argc, char **argv, t_list **c, t_trigger debug)
{
	t_mlx	mlx;
	int		*array;

	if (debug.debug == 0)
		return (0);
	mlx.a = 0;
	mlx.b = 0;
	if (ft_read2a(&mlx.a, argc, argv, debug) ||\
	!(array = (int *)malloc(sizeof(int) * ft_get_number_of_elements(mlx.a))))
	{
		mlx.a ? ft_lstdel(&mlx.a, del) : mlx.a;
		*c ? ft_lstdel(c, del) : *c;
		write(2, "Error\n", 6);
		return (1);
	}
	ft_fill_array(mlx.a, &array);
	ft_fill_index(&mlx.a, array, ft_get_number_of_elements(mlx.a));
	ft_fill_color(&mlx);
	free(array);
	if (ft_mlx_init(&mlx, "PSWAP", c))
		return (1);
	ft_events(&mlx);
	return (0);
}
