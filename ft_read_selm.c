/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_selm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:03:56 by majosue           #+#    #+#             */
/*   Updated: 2020/02/10 09:24:38 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_checkdup(int number, t_list *a)
{
	while (a)
	{
		if (((t_elm *)(a->content))->number == number)
			return (1);
		a = a->next;
	}
	return (0);
}

static int	ft_str_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (*str);
}

static int	ft_check_int(char *str, t_list **a)
{
	long int number;
    t_elm element;

	number = ft_atoi_base(str, 10);
	if (number < INT_MIN || number > INT_MAX || ft_checkdup((int)number, *a))
		return (1);
    element.number = number;
    if (!ft_lstp2back(a, &element, sizeof(t_elm)))
		return (1);
	return (0);
}

static int	ft_check(char *str, t_list **a)
{
	if (ft_str_digit(str) == 0 &&
		ft_strlen(str) <= 11 &&
		ft_strlen(str) > 0 &&
		ft_check_int(str, a) == 0)
		return (0);
	return (1);
}

int	ft_read_selm(t_list **a, int n, char **str)
{
	int		i;
	char	**arr;
	char	**begin;

	arr = 0;
	i = 0;
	while (++i < n)
	{
		if (!(arr = ft_strsplit(str[i], ' ')))
			return (1);
		begin = arr;
		while (*arr)
		{
			if (ft_check(*arr, a))
			{
				cleanarr(&begin);
				*a ? ft_lstdel(a, del) : *a;
				return (1);
			}
			arr++;
		}
		cleanarr(&begin);
	}
	return (0);
}
