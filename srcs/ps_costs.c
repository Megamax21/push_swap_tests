/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:42:23 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/30 20:08:55 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_cost	*ft_newcost(int final_cost)
{
	t_cost	*new;

	new = (t_cost *)malloc(sizeof(t_cost));
	if (!new)
		return (NULL);
	new->ra = 0;
	new->rb = 0;
	new->rr = 0;
	new->rra = 0;
	new->rrb = 0;
	new->rrr = 0;
	new->final_cost = final_cost;
	new->actual_cost = 0;
	return (new);
}

void	ft_get_total_cost(t_list **a, t_list **b, t_cost **total_cost)
{
	t_list	*temp_b;
	t_cost	*best_cost;
	t_cost	*temp_c;
	int		start;

	start = 0;
	temp_b = *b;
	best_cost = ft_newcost(0);
	temp_c = ft_newcost(0);
	while (temp_b != NULL)
	{
		ft_empty_cost(temp_c);
		ft_work_on_a(a, temp_b, temp_c);
		ft_work_on_b(b, temp_b, temp_c);
		if (start == 0)
		{
			ft_update_temp_cost(best_cost, temp_c, total_cost);
			start = 1;
		}
		if (temp_c -> actual_cost < temp_c -> final_cost)
			ft_update_temp_cost(best_cost, temp_c, total_cost);
		temp_c -> actual_cost = 0;
		temp_b = temp_b -> next;
	}
}

void	ft_empty_cost(t_cost *c)
{
	c->ra = 0;
	c->rb = 0;
	c->rr = 0;
	c->rra = 0;
	c->rrb = 0;
	c->rrr = 0;
}

void	ft_copy_cost(t_cost *from, t_cost *to)
{
	to -> ra = from -> ra;
	to -> rb = from -> rb;
	to -> rr = from -> rr;
	to -> rra = from -> rra;
	to -> rrb = from -> rrb;
	to -> rrr = from-> rrr;
	to -> actual_cost = from-> actual_cost;
	to -> final_cost = from-> final_cost;
}

int	ft_rework_cost(t_cost **c)
{
	int	i;

	i = 0;
	while ((*c)-> ra > 0 && (*c)-> rb > 0)
	{
		(*c)-> ra--;
		(*c)-> rb--;
		(*c)-> final_cost--;
		(*c)-> rr++;
		i++;
	}
	while ((*c)-> rra > 0 && (*c)-> rrb > 0)
	{
		(*c)-> rra--;
		(*c)-> rrb--;
		(*c)-> final_cost--;
		(*c)-> rrr++;
	}
	return (i);
}
