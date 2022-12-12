/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:40:34 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/12 11:36:05 by alfgarci         ###   ########.fr       */
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

static void	free_split(char **split)
{
	int	aux;

	aux = -1;
	while (*(split + ++aux))
		free(*(split + aux));
	free(split);
}

static void	free_stk(t_stack **stk)
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

int	main(int argc, char **argv)
{
	char	**params;
	t_stack	**a;
	t_stack	**b;
	t_stack	**n;

	if (argc >= 2)
	{
		params = get_param(argc, argv);
		if (check_error(check_param(params)))
		{
			a = make_stack(params);
			b = (t_stack **)malloc(sizeof(t_stack *));
			n = normalize_stk(a);
			free_stk(a);
			push_swap(n, b);
			free_stk(n);
			free_stk(b);
		}
		free_split(params);
		return (0);
	}
	ft_printf("Error: Wrong number of arguments.\n");
	return (-1);
}
