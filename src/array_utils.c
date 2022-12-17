/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:43:56 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/16 17:06:18 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(int n, int *arr, int len_arr)
{
	int	pos;
	int	i;

	pos = 0;
	i = -1;
	while (++i < len_arr)
		if (arr[i] == n)
			return (i);
	return (i);
}

void	free_split(char **split)
{
	int	aux;

	aux = -1;
	while (*(split + ++aux))
		free(*(split + aux));
	free(split);
}
