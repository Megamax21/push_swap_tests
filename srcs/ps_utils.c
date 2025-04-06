/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:16:32 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/04 11:31:50 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_prepare_rotate(t_list **a, t_list **b, t_cost **c)
{
	while ((*c)-> ra > 0)
	{
		ft_rotate(a, 'a');
		(*c)-> ra--;
	}
	while ((*c)-> rb > 0)
	{
		ft_rotate(b, 'b');
		(*c)-> rb--;
	}
	while ((*c)-> rr > 0)
	{
		ft_rr(a, b);
		(*c)-> rr--;
	}
}

void	ft_prepare_rev_rot(t_list **a, t_list **b, t_cost **c)
{
	while ((*c)-> rra > 0)
	{
		ft_rev_rot(a, 'a');
		(*c)-> rra--;
	}
	while ((*c)-> rrb > 0)
	{
		ft_rev_rot(b, 'b');
		(*c)-> rrb--;
	}
	while ((*c)-> rrr > 0)
	{
		ft_rrr(a, b);
		(*c)-> rrr--;
	}
}

void	ft_work_on_a(t_list **a, t_list *tb, t_cost *c)
{
	if (ft_get_cost(ft_find_next_min(tb -> index, a), a) >= 0)
	{
		c -> ra = ft_get_cost(ft_find_next_min(tb -> index, a), a);
		c -> actual_cost += ft_get_cost(ft_find_next_min(tb -> index, a), a);
	}
	else
	{
		c -> rra -= ft_get_cost(ft_find_next_min(tb -> index, a), a);
		c -> actual_cost -= ft_get_cost(ft_find_next_min(tb -> index, a), a);
	}
}

void	ft_work_on_b(t_list **b, t_list *tb, t_cost *c)
{
	if (ft_get_cost(tb -> index, b) >= 0)
	{
		c -> rb = ft_get_cost(tb -> index, b);
		c -> actual_cost += ft_get_cost(tb -> index, b);
	}
	else
	{
		c -> rrb -= ft_get_cost(tb -> index, b);
		c -> actual_cost -= ft_get_cost(tb -> index, b);
	}
}

void	ft_update_temp_cost(t_cost *best_c, t_cost *temp_c, t_cost **total_c)
{
	ft_rework_cost(&temp_c);
	ft_copy_cost(temp_c, best_c);
	temp_c -> final_cost = temp_c -> actual_cost;
	// printf("ET JUSTE AVANT CA DONNE CA :\n");
	//ft_print_cost(*total_c);
	ft_copy_cost(best_c, *total_c);
	// printf("JE TE JURE A TOUT MOMENT CEST LA : \n");
	// ft_print_cost(*total_c);
}
