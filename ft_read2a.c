/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:05:05 by majosue           #+#    #+#             */
/*   Updated: 2020/02/21 17:02:44 by majosue          ###   ########.fr       */
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
	char *tmp;

	if (*str == '-' || *str == '+')
		str++;
	tmp = str;
	while (ft_isdigit(*str))
		str++;
	if ((tmp - str) == 0)
		return (1);
	return (*str);
}

int	ft_check_int(char *str, t_list **a, int for_push_swap)
{
	long int	number;
	t_elm		content;

	number = ft_atoi_base(str, 10);
	if (number < INT_MIN || number > INT_MAX || ft_checkdup((int)number, *a))
		return (1);
	if (for_push_swap)
	{
		content.number = number;
		if (!ft_lstp2back(a, &content, sizeof(t_elm)))
			return (1);
	}
	else
	{
		if (!ft_lstp2back(a, &number, 4))
			return (1);
	}
	return (0);
}

int	ft_check(char *str, t_list **a, int for_push_swap)
{
	if (ft_str_digit(str) == 0 &&
		ft_strlen(str) <= 11 &&
		ft_strlen(str) > 0 &&
		ft_check_int(str, a, for_push_swap) == 0)
		return (0);
	return (1);
}

int	ft_read2a(t_list **a, int n, char **str, int for_push_swap)
{
	int		i;
	char	**arr;
	char	**begin;

	arr = 0;
	i = 0;
	while (++i < n)
	{
		if (!(arr = ft_strsplit(str[i], ' ')) ||
			(!*(begin = arr) && ft_strlen(str[i])))
		{
			cleanarr(&begin);
			return (1);
		}
		while (*arr)
		{
			if (ft_check(*arr++, a, for_push_swap))
			{
				cleanarr(&begin);
				return (1);
			}
		}
		cleanarr(&begin);
	}
	return (0);
}
