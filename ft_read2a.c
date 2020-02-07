/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:05:05 by majosue           #+#    #+#             */
/*   Updated: 2020/02/06 17:00:09 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkdup(int number, t_list *a)
{
	while (a)
	{
		if (*(int *)(a->content) == number)
			return (1);
		a = a->next;
	}
	return (0);
}

int	ft_str_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (*str);
}

int	ft_check_int(char *str, t_list **a)
{
	long int number;

	number = ft_atoi_base(str, 10);
	if (number < INT_MIN || number > INT_MAX || ft_checkdup((int)number, *a))
		return (1);
	if (!ft_lstp2back(a, &number, 4))
		return (1);
	return (0);
}

int	ft_check(char *str, t_list **a)
{
	if (ft_str_digit(str) == 0 &&
		ft_strlen(str) <= 11 &&
		ft_strlen(str) > 0 &&
		ft_check_int(str, a) == 0)
		return (0);
	return (1);
}

int	ft_read2a(t_list **a, int n, char **str)
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
