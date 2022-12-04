/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:40:34 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/04 23:53:25 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_error(int result)
{
	if (result == 1)
		ft_printf("Error: Mal formato\n");
	else if (result == 2)
		ft_printf("Error: Fuera de rango\n");
	else if (result == 3)
		ft_printf("Error: Numero duplicado\n");
	else
		return (1);
	return (0);
}
/*
void	l(){
	system("leaks push_swap");
}
*/
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

void	show_stack(char *s, t_stack *a)
{

	t_stack	*sig = a;

	ft_printf("%s\n", s);
	ft_printf("-------\n");
	while (sig->next != NULL)
	{
		ft_printf("%d\n", sig->num);
		sig = sig->next;
	}
	ft_printf("%d\n", sig->num);
	ft_printf("-------\n");
}

int	main(int argc, char **argv)
{
	char	**params;
	t_stack **a;
	t_stack **b;
	t_stack **n;

//	atexit(l);

	if (argc >= 2)
	{
		params = get_param(argc, argv);
		if (check_error(check_param(params)))
		{
			a = make_stack(params);
			b = (t_stack **)malloc(sizeof(t_stack *));
			
//			show_stack("INICIAL", *a);
			/*
			s(a);
			show_stack("S", *a);
			r(a);
			show_stack("R", *a);
			show_stack("RR", *a);
			p(a, b);
			show_stack("PA ->AAAAAAAAAAAAA", *a);
			show_stack("PA ->BBBBBBBBBBBBB", *b);
			rr(a);
			show_stack("RR", *a);
			*/
			n = normalize_stk(a);
			free_stk(a);
//			show_stack("NORMALIZADA", *n);
			push_swap(n, b);
//			show_stack("ORDENADA", *n);
			free_stk(n);
			free_stk(b);
		}
		free_split(params);
	}

	return (0);
}
