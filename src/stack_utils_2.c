/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:46:49 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/05 13:51:19 by alfgarci         ###   ########.fr       */
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

int	get_pos(int n, t_stack **stk)
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
