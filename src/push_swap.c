/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:23:40 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 17:09:31 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_3_algorithm(t_stack **a)
{
	int		size;

	size = stk_size(a);
	if (size <= 3)
	{
		if (stk_first(a) == (size - 1))
			r(a, 'a');
		else if (stk_first(a) == 0
			|| (stk_first(a) == 1 && stk_last(*a)->num != 2))
			rr(a, 'a');
		if (check_sorted(a) != 1)
			s(a, 'a');
	}
}

static void	small_5_algorithm(t_stack **a, t_stack **b)
{
	int	size;
	int	cont;

	cont = 0;
	size = stk_size(a);
	while (cont < (size - 3))
	{
		if (stk_first(a) >= 3)
		{
			p(a, b, 'b');
			cont++;
		}
		else
			r(a, 'a');
	}
	if (check_sorted(a) == 0)
		small_3_algorithm(a);
	if (stk_first(b) == 4)
		s(b, 'b');
	while (stk_size(b) != 0)
	{
		p(b, a, 'a');
		r(a, 'a');
	}
}

/*Radix Sort*/
static void	big_algorithm(t_stack **a, t_stack **b)
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

void	push_swap(t_stack **a, t_stack **b)
{
	if (check_sorted(a) == 0)
	{
		if (stk_size(a) <= 3)
			small_3_algorithm(a);
		else if (stk_size(a) <= 5)
			small_5_algorithm(a, b);
		else
			big_algorithm(a, b);
	}
}
