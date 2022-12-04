/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:32:08 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/04 19:58:13 by alfgarci         ###   ########.fr       */
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

static int	get_pos(int n, t_stack **stk)
{
	t_stack	*it;
	int		pos;

	it = *stk;
	pos = 0;
	while (it->num != n)
	{
		pos++;
		it = it->next;
	}
	return (pos);
}

static	int	get_min(t_stack **stk)
{
	t_stack	*it;
	int		min;

	it = *stk;
	min = it->num;
	while (it)
	{
		if (it->num < min)
			min = it->num;
		it = it->next;
	}
	return (min);
}

static int	*stk_to_arr(t_stack **stk)
{
	t_stack	*it;
	int		*arr;
	int		i;

	it = *stk;
	i = 0;
	arr = (int *)malloc(sizeof(int) * stk_size(stk));
	while (it)
	{
		arr[i++] = it->num;
		it = it->next;
	}
	return (arr);
}

t_stack	**normalize_stk(t_stack **a)
{
	int		i;
	int		*arr_norm;
	int		*arr_num;
	int		min;
	t_stack	**stk_norm;

	i = -1;
	min = get_min(a);
	stk_norm = malloc(sizeof(t_stack *));
	arr_norm = (int *)malloc(sizeof(int) * stk_size(a));
	arr_num = stk_to_arr(a);
	while (++i < stk_size(a))
	{
		arr_norm[get_pos(min, a)] = i;
		min = next_biggest(arr_num, min, stk_size(a));
	}
	i = -1;
	while (++i < stk_size(a))
		stk_add_back(stk_norm, stk_new(arr_norm[i]));
	free(arr_norm);
	free(arr_num);
	return (stk_norm);
}
