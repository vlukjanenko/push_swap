/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by majosue           #+#    #+#             */
/*   Updated: 2020/02/11 09:45:44 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_list *stack)
{
	printf("stack \n");
	while (stack)
	{
		printf("|%d|", *(int *)stack->content);
		stack = stack->next;
	}
	printf("\n");
}

int ft_checkarg(int n, char **str)
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

int		main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	t_list *c;

	b = 0;
	a = 0;
	c = 0;
	if (argc < 2 || ft_checkarg(argc, argv))
		return (0);
	if (ft_read2a(&a, argc, argv) || ft_read2c(&c))
	{
		a ? ft_lstdel(&a, del) : a;
		c ? ft_lstdel(&c, del) : c;
		write(2, "Error\n", 6);
		return (0);
	}
	//ft_print_stack(a);
	ft_do_sort(&a, &b, &c);
	//ft_print_stack(a);
	ft_issort(a, b) ? write(1, "KO\n", 3) : write(1, "OK\n", 3);
	a ? ft_lstdel(&a, del) : a;
	c ? ft_lstdel(&c, del) : c;
	b ? ft_lstdel(&b, del) : b;
}
