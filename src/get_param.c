/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:09:56 by alfgarci          #+#    #+#             */
/*   Updated: 2022/12/15 20:37:57 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_arr(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static char	**join_split(char **split_1, char **split_2)
{
	unsigned int	len;
	int				i;
	int				j;
	char			**new;

	i = 0;
	j = -1;
	len = len_arr(split_1) + len_arr(split_2);
	new = (char **)malloc((len + 1) * sizeof(char *));
	while (split_1[++j])
		new[i++] = split_1[j];
	j = -1;
	while (split_2[++j])
		new[i++] = split_2[j];
	new[len] = NULL;
	free(split_1);
	free(split_2);
	return (new);
}

char	**get_param(int argc, char **argv)
{
	int		i;
	char	**array;

	i = 1;
	array = ft_split(argv[i++], ' ');
	while (i < argc)
		array = join_split(array, ft_split(argv[i++], ' '));
	return (array);
}

t_stack	**make_stack(char **params)
{
	t_stack	**stk;
	int		i;

	stk = (t_stack **)malloc(sizeof(t_stack *));
	*stk = NULL;
	i = -1;
	while (params[++i] != NULL)
		stk_add_back(stk, stk_new(ft_atoi(params[i])));
	return (stk);
}
