/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:43:40 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 20:38:43 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stk_new(int num)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
		return (0);
	tmp->num = num;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*stk_last(t_stack *stk)
{
	while (stk)
	{
		if (!stk->next)
			return (stk);
		stk = stk->next;
	}
	return (stk);
}

void	stk_add_front(t_stack **stk, t_stack *new)
{
	if (stk)
	{
		if (*stk)
			new->next = *stk;
		*stk = new;
	}
}

void	stk_add_back(t_stack **stk, t_stack *new)
{
	t_stack	*last_element;

	if (stk)
	{
		if (*stk)
		{
			last_element = stk_last(*stk);
			last_element->next = new;
		}
		else
			*stk = new;
	}
}

int	stk_size(t_stack **stk)
{
	t_stack	*it;
	int		i;

	it = *stk;
	i = 0;
	while (it)
	{
		it = it->next;
		i++;
	}
	return (i);
}
