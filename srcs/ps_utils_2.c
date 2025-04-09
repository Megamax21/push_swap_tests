/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:05:36 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/10 00:12:47 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_next_min(int i, t_list **l)
{
	t_list	*tmp;
	int		next_min;

	tmp = (*l);
	next_min = ft_find_i_max(l);
	while (tmp != NULL)
	{
		if (tmp->index > i && tmp->index < next_min)
			next_min = tmp->index;
		tmp = tmp->next;
	}
	return (next_min);
}

int	ft_handle_two_args(char **av, int *nb_args, char ***args)
{
	int	i;

	i = 0;
	if (ft_safe_atoi(av[1], &i) && ft_check_content(av[1]) == 1)
		return (0);
	*nb_args = ft_countword(av[1], ' ');
	if (*nb_args == 0)
		return (0);
	*args = ft_split(av[1], ' ');
	if (!args || !args[0])
	{
		ft_putstr_fd("Error\n", 2);
		if (*args)
			free_lst(*args);
		return (0);
	}
	return (1);
}

void	ft_handle_more_args(char ***args, int *ac, char ***av)
{
	int	i;

	i = 0;
	(*args) = ft_calloc(*ac, sizeof(char *));
	while (i < *ac - 1)
	{
		(*args)[i] = ft_strdup((*av)[(i) + 1]);
		(i)++;
	}
	(*ac)--;
}

void	ft_set_values(t_list **a, t_list **b, int *nb_args, char ***args)
{
	(*a) = NULL;
	(*b) = NULL;
	(*args) = NULL;
	(*nb_args) = 1;
}

void	ft_handle_frees(char ***args, t_list **a, t_list **b)
{
	if (*args)
		free_lst(*args);
	if (*a)
		ft_safelstclear(a);
	if (*b)
		ft_safelstclear(b);
}
