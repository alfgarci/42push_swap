/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:32:08 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/16 17:49:05 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	next_biggest(int *arr, int num, int tam)
{
	int	next;
	int	i;
	int	j;
	int	nums;
	int	*tmp;

	i = -1;
	nums = 0;
	j = -1;
	while (++i < tam)
		if (arr[i] > num)
			nums++;
	if (nums == 0)
		return (num);
	tmp = (int *)malloc(nums * sizeof(int));
	i = -1;
	while (++i < tam)
		if (arr[i] > num)
			tmp[++j] = arr[i];
	next = tmp[0];
	while (nums-- > 0)
		if (tmp[nums] < next)
			next = tmp[nums];
	free(tmp);
	return (next);
}

static	int	get_min(int *arr, int tam_arr)
{
	int	min;
	int	i;

	i = -1;
	min = arr[0];
	while (++i < tam_arr)
		if (arr[i] < min)
			min = arr[i];
	return (min);
}

static int	*make_int_arr(char **char_arr)
{
	int	*arr;
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (char_arr[len])
		len++;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < len)
		arr[i] = ft_atoi(char_arr[i]);
	return (arr);
}

static int	len_char_arr(char **char_arr)
{
	int	i;

	i = 0;
	while (char_arr[i])
		i++;
	return (i);
}

t_stack	**normalize_stk(char **params)
{
	int		i;
	int		*arr_norm;
	int		*arr_num;
	int		min;
	t_stack	**stk_norm;

	i = -1;
	arr_norm = (int *)malloc(sizeof(int) * len_char_arr(params));
	if (!arr_norm)
		return (NULL);
	arr_num = make_int_arr(params);
	min = get_min(arr_num, len_char_arr(params));
	while (++i < len_char_arr(params))
	{
		arr_norm[get_pos(min, arr_num, len_char_arr(params))] = i;
		min = next_biggest(arr_num, min, len_char_arr(params));
	}
	stk_norm = make_stack(arr_norm, len_char_arr(params));
	free(arr_norm);
	free(arr_num);
	if (!stk_norm)
		return (NULL);
	return (stk_norm);
}
