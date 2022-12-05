/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:59:07 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/05 14:03:23 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/*moves.c*/
void	s(t_stack **stk, char c);
void	r(t_stack **stk, char c);
void	rr(t_stack **stk, char c);
void	p(t_stack **src, t_stack **dst, char c);

/*stack_utils.c*/
t_stack	*stk_last(t_stack *stk);
void	stk_add_back(t_stack **stk, t_stack *new);
void	stk_add_front(t_stack **stk, t_stack *new);
t_stack	*stk_new(int elem);
int		stk_size(t_stack **stk);

/*stacks_utils_2.c*/
int		stk_first(t_stack **stk);
int		check_sorted(t_stack **stk);
int		get_pos(int n, t_stack **stk);

/*check_param.c*/
int		check_param(char **array);

/*get_param.c*/
char	**get_param(int argc, char **argv);
t_stack	**make_stack(char **params);

/*normalize_stk.c*/
t_stack	**normalize_stk(t_stack **a);

/*push_swap.c*/
void	push_swap(t_stack **a, t_stack **b);

#endif
