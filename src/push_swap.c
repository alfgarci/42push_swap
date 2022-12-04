/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:23:40 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/05 00:03:25 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stk_first(t_stack **stk)
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

void	push_swap(t_stack **a, t_stack **b)
{
	int	i;
	int	j;
	int	tmp;
	int	size;
	int	msb;

	i = -1;
	msb = 0;
	size = stk_size(a);
	while (((size - 1) >> msb) != 0)
		msb++;
	while (++i < msb)
	{
		j = -1;
		while (++j < size)
		{
			tmp = stk_first(a);
			if ((tmp >> i & 1) == 1)
				r(a, 'a');
			else
				p(a, b, 'b');
		}
		while (stk_size(b) != 0)
			p(b, a, 'a');
	}
}
