/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by majosue           #+#    #+#             */
/*   Updated: 2020/03/03 11:44:02 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkarg(int n, char **str)
{
	int i;

	i = 0;
	while (++i < n)
	{
		if (ft_strlen(str[i]))
			return (0);
	}
	return (1);
}

int	ft_init_debug_n_stacks(t_list **a, t_list **b, t_list **c, t_trigger *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	if (!(d->arg = ft_strtrim(d->arg)))
		exit(1);
	if (ft_strequ(d->arg, "-v"))
		d->debug = 1;
	else
		d->debug = 0;
	d->print = 0;
	free(d->arg);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;
	t_list		*c;
	t_trigger	debug;

	if (argc < 2 || ft_checkarg(argc, argv))
		return (0);
	debug.arg = argv[1];
	ft_init_debug_n_stacks(&a, &b, &c, &debug);
	if (argc == 2 && debug.debug)
		return (0);
	if (ft_read2a(&a, argc, argv, debug) || ft_read2c(&c))
	{
		a ? ft_lstdel(&a, del) : a;
		c ? ft_lstdel(&c, del) : c;
		write(2, "Error\n", 6);
		return (0);
	}
	ft_do_sort(&a, &b, &c);
	ft_issort(a, b) ? write(1, "KO\n", 3) : write(1, "OK\n", 3);
	a ? ft_lstdel(&a, del) : a;
	b ? ft_lstdel(&b, del) : b;
	ft_show_my_precious(argc, argv, &c, debug);
	c ? ft_lstdel(&c, del) : c;
	return (0);
}
