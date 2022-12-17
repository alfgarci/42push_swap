/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:40:34 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/16 17:49:14 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_error(int result)
{
	if (result == 1)
		ft_printf("Error: Bad format\n");
	else if (result == 2)
		ft_printf("Error: Out of range\n");
	else if (result == 3)
		ft_printf("Error: Duplicate numbers\n");
	else
		return (1);
	return (0);
}

static int	exit_a(char **params)
{
	free_split(params);
	return (-1);
}

static int	exit_b(char **params, t_stack **a)
{
	free_split(params);
	free_stk(a);
	return (-1);
}

int	main(int argc, char **argv)
{
	char	**params;
	t_stack	**b;
	t_stack	**a;

	if (argc >= 2)
	{
		params = get_param(argc, argv);
		if (check_error(check_param(params)))
		{
			a = normalize_stk(params);
			if (!a)
				return (exit_a(params));
			b = (t_stack **)malloc(sizeof(t_stack *));
			if (!b)
				return (exit_b(params, a));
			*b = NULL;
			push_swap(a, b);
			free_stk(a);
			free_stk(b);
		}
		free_split(params);
		return (0);
	}
	ft_printf("Error: Wrong number of arguments.\n");
	return (-1);
}
