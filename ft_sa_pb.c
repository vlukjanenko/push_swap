/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:33:36 by majosue           #+#    #+#             */
/*   Updated: 2020/02/07 15:05:16 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_list **a, t_list **b)
{
	void *tmp;

	(void)b;
	if (*a && (*a)->next)
	{
		tmp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = tmp;
	}
	return (0);
}

int	ft_sb(t_list **a, t_list **b)
{
	void *tmp;

	(void)a;
	if (*b && (*b)->next)
	{
		tmp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = tmp;
	}
	return (0);
}

int	ft_ss(t_list **a, t_list **b)
{
	ft_sa(a, b);
	ft_sb(a, b);
	return (0);
}

int	ft_pb(t_list **a, t_list **b)
{
	int		content;
	t_list	*new;
	t_list	*tmp;

	if (*a)
	{
		content = *(int *)(*a)->content;
		if (!(new = ft_lstnew(&content, 4)))
			return (1);
		if (!*b)
			*b = new;
		else
			ft_lstadd(b, new);
		tmp = *a;
		*a = (*a)->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}

int	ft_pa(t_list **a, t_list **b)
{
	int		content;
	t_list	*new;
	t_list	*tmp;

	if (*b)
	{
		content = *(int *)(*b)->content;
		if (!(new = ft_lstnew(&content, 4)))
			return (1);
		if (!*a)
			*a = new;
		else
			ft_lstadd(a, new);
		tmp = *b;
		*b = (*b)->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}
