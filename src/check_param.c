/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:20:20 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/04 22:21:18 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_range(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		if ((ft_atoi(array[i]) == 0
				|| ft_atoi(array[i]) == -1) && ft_strlen(array[i]) > 2)
			return (-1);
	return (1);
}

static int	check_dups(char **array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		j = i;
		while (array[++j])
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				return (-1);
	}
	return (1);
}

static int	check_format(char **array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		if (ft_isdigit(array[i][0]) || array[i][0] == '-')
		{
			j = 0;
			while (array[i][++j])
				if (!ft_isdigit(array[i][j]))
					return (-1);
		}
		else
			return (-1);
	}
	return (1);
}

int	check_param(char **array)
{
	if (check_format(array) == -1)
		return (1);
	if (check_range(array) == -1)
		return (2);
	if (check_dups(array) == -1)
		return (3);
	return (0);
}
