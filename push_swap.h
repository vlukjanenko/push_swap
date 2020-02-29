/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:43:41 by majosue           #+#    #+#             */
/*   Updated: 2020/02/29 13:50:45 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "get_next_line.h"
# include <limits.h>
# include "mlx.h"
# define WIN_WIDTH 800
# define WIN_HEIGHT 1100
# define COL 0
# define START_COLOUR 0x0000FF
# define END_COLOUR 0xFE2E2E
# include <stdio.h> //for debug

typedef struct	s_point
{
	int		x;
	int		y;
	int		color;
}				t_point;

typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_list		*a;
	t_list		*b;
	t_list		*c;
	t_list		*head_c;
	int			bar_h;
	int			delay;
	double		scale_w;
	t_img		img;
}				t_mlx;

typedef union	u_color
{
	int				composite;
	unsigned char	color[4];
}				t_color;

typedef struct	s_elm
{
	int		number;
	int		chunk;
	int		index;
	t_color	color;
}				t_elm;

typedef struct	s_sort
{
	int meet_f;
	int first;
	int chunks;
	int meet_l;
	int last;
	int n;
}				t_sort;

typedef struct	s_trigger
{
	int		debug;
	int		print;
	char	*arg;
}				t_trigger;

typedef int	(*t_fun)(t_list **, t_list **, int);

int				ft_read2a(t_list **a, int n, char **str, t_trigger d);
int				ft_read2c(t_list **c);
void			del(void *content, size_t size);
void			cleanarr(char ***array);
int				ft_issort(t_list *a, t_list *b);
int				ft_line_valid(char *line);
int				ft_ra(t_list **a, t_list **b, int print);
int				ft_rb(t_list **a, t_list **b, int print);
int				ft_rr(t_list **a, t_list **b, int print);
int				ft_rra(t_list **a, t_list **b, int print);
int				ft_rrb(t_list **a, t_list **b, int print);
int				ft_sa(t_list **a, t_list **b, int print);
int				ft_sb(t_list **a, t_list **b, int print);
int				ft_ss(t_list **a, t_list **b, int print);
int				ft_pb(t_list **a, t_list **b, int print);
int				ft_pa(t_list **a, t_list **b, int print);
int				ft_rrr(t_list **a, t_list **b, int print);
int				ft_issort(t_list *a, t_list *b);
int				ft_issorta(t_list *a);
t_fun			ft_get_f(char *str);
int				ft_do_sort(t_list **a, t_list **b, t_list **c);
void			ft_qsort(int **array, int low, int high);
void			ft_3_sort(t_list **a, t_list **b);
void			ft_1st_pass(t_list **a, t_list **b, t_sort *n);
void			ft_2nd_pass(t_list **a, t_list **b, int n);
int				ft_get_number_of_elements(t_list *a);
void			ft_fill_chunks(t_list **a, t_sort *n);
void			ft_fill_index(t_list **a, int *array, int n);
int				ft_fill_array(t_list *a, int **array);
int				ft_get_pos(t_list *a, int index);
int				ft_show_my_precious(int argc, char **argv,\
t_list **c, t_trigger debug);
int				ft_draw_line(t_mlx *mlx, t_point p1, t_point p2);
int				ft_do_beutifull_sort(t_mlx *mlx);
void			ft_fill_color(t_mlx *mlx);

#endif
