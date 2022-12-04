/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:41:07 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/04 22:22:18 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack **stk, char c)
{
	int		aux;
	t_stack	*first;

	first = *stk;
	if (stk_size(stk) >= 2)
	{
		aux = first->num;
		first->num = first->next->num;
		first->next->num = aux;
	}
	ft_printf("s%c\n", c);
}

void	r(t_stack **stk, char c)
{
	t_stack	*first;
	t_stack	*second;

	first = *stk;
	second = first->next;
	stk_add_back(stk, stk_new(first->num));
	*stk = second;
	free(first);
	ft_printf("r%c\n", c);
}

void	rr(t_stack **stk, char c)
{
	t_stack	*last;
	t_stack	*sig;

	last = stk_last(*stk);
	sig = *stk;
	while (sig->next->next != NULL)
		sig = sig->next;
	last->next = *stk;
	sig->next = NULL;
	*stk = last;
	ft_printf("rr%c\n", c);
}

void	p(t_stack **src, t_stack **dst, char c)
{
	t_stack	*first;
	t_stack	*second;

	if (src)
	{
		if (*src)
		{
			first = *src;
			second = first->next;
			stk_add_front(dst, stk_new(first->num));
			*src = second;
			free(first);
		}
	}
	ft_printf("p%c\n", c);
}
