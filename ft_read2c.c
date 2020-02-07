/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read2c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majosue <majosue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:17:32 by majosue           #+#    #+#             */
/*   Updated: 2020/02/07 14:14:04 by majosue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Validate instructions
*/

int	ft_line_valid(char *line)
{
	char	*cmd[11];
	int		i;

	cmd[0] = "sa";
	cmd[1] = "sb";
	cmd[2] = "ss";
	cmd[3] = "pa";
	cmd[4] = "pb";
	cmd[5] = "ra";
	cmd[6] = "rb";
	cmd[7] = "rr";
	cmd[8] = "rra";
	cmd[9] = "rrb";
	cmd[10] = "rrr";
	i = -1;
	while (++i < 11)
	{
		if (ft_strequ(cmd[i], line))
			return (i);
	}
	return (-1);
}

int	ft_read2c(t_list **c)
{
	char *line;

	line = 0;
	while (get_next_line(0, &line) &&
				ft_line_valid(line) >= 0 &&
				ft_lstp2back(c, line, ft_strlen(line) + 1))
	{
		free(line);
		line = 0;
	}
	if (line)
	{
		free(line);
		return (1);
	}
	return (0);
}
