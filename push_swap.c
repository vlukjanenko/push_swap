/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:42:33 by majosue           #+#    #+#             */
/*   Updated: 2020/02/06 12:34:30 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

    b = 0;
	a = 0;
	if (argc < 2)
		return (0);
	if (ft_read2a(&a, argc, argv))
	{
	    a ? ft_lstdel(&a, del) : a;
    	write(2, "Error\n", 6);
		return (0);
	}
    if (a == 0)
       ft_putstr("Pustota");
    printf("sort check = %d", ft_issort(a, b));
    a ? ft_lstdel(&a, del) : a;
    }
    