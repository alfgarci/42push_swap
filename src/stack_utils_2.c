/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:46:49 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/16 17:03:09 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_first(t_stack **stk)
{
	t_stack	*it;

	it = *stk;
	return (it->num);
}

int	check_sorted(t_stack **stk)
{
	t_stack	*sig;

	sig = *stk;
	while (sig->next != NULL)
	{
		if (sig->num > sig->next->num)
			return (0);
		sig = sig->next;
	}
	return (1);
}

void	free_stk(t_stack **stk)
{
	t_stack	*sig;
	t_stack	*aux;

	sig = *stk;
	while (sig)
	{
		aux = sig->next;
		free(sig);
		sig = aux;
	}
	free(sig);
	free(stk);
}

t_stack	**make_stack(int *arr, int len_arr)
{
	t_stack	**stk;
	t_stack	*new;
	int		i;

	stk = (t_stack **)malloc(sizeof(t_stack *));
	if (!stk)
		return (NULL);
	*stk = NULL;
	i = -1;
	while (++i < len_arr)
	{
		new = stk_new(arr[i]);
		if (!new)
		{
			free_stk(stk);
			return (NULL);
		}
		stk_add_back(stk, new);
	}
	return (stk);
}
