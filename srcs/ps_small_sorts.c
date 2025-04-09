/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_sorts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:26:42 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/09 16:09:58 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two(t_list **l)
{
	ft_swap(l, 'a');
}

int	ft_check_order(t_list	*l)
{
	if ((l->index == 2 && l->next->index == 1)
		|| (l->index == 3 && l->next->index == 2)
		|| (l->index == 1 && l->next->index == 3))
	{
		return (1);
	}
	if (l->index == 3 && l->next->index == 1)
		return (2);
	if (l->index == 2 && l->next->index == 3)
		return (3);
	return (0);
}

void	ft_sort_three(t_list **l)
{
	int	a;
	int	b;
	int	c;

	a = (*l)->content;
	b = (*l)->next->content;
	c = (*l)->next->next->content;
	if (a > b && b < c && a < c)
		ft_swap(l, 'a');
	else if (a > b && b > c)
	{
		ft_swap(l, 'a');
		ft_rev_rot(l, 'a');
	}
	else if (a > b && b < c && a > c)
		ft_rotate(l, 'a');
	else if (a < b && b > c && a < c)
	{
		ft_swap(l, 'a');
		ft_rotate(l, 'a');
	}
	else if (a < b && b > c && a > c)
		ft_rev_rot(l, 'a');
}

void	ft_sort_four(t_list **a, t_list **b)
{
	while ((*a)->index != 1)
		ft_rotate(a, 'a');
	ft_push(a, b, 'b');
	ft_reset_index(*a);
	ft_assign_index(a);
	ft_sort_three(a);
	ft_push(b, a, 'a');
}

void	ft_sort_five(t_list **a, t_list **b)
{
	while ((*a)->index != 1)
		ft_rotate(a, 'a');
	ft_push(a, b, 'b');
	while ((*a)->index != 2)
		ft_rotate(a, 'a');
	ft_push(a, b, 'b');
	ft_reset_index(*a);
	ft_assign_index(a);
	ft_sort_three(a);
	ft_push(b, a, 'a');
	ft_push(b, a, 'a');
}
