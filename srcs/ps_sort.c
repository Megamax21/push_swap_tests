/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:41:29 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/01 10:14:15 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_list **stack_a, t_list **stack_b, int length)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (ft_check_sorted(stack_a) == 0)
	{
		if (len == 2)
			ft_sort_two(stack_a);
		else if (len == 3)
			ft_sort_three(stack_a);
		else if (len == 4)
			ft_sort_four(stack_a, stack_b);		
		else if (len == 5)
			ft_sort_five(stack_a, stack_b);
		else if (len > 5)
			ft_long_sort(stack_a, stack_b, length);
	}
}

void	ft_long_sort(t_list **a, t_list **b, int length)
{
	t_cost	*total_cost;

	total_cost = ft_newcost(0);
	ft_init_sort(a, b, length);
	while (ft_lstsize(*b) > 0)
	{
		if ((*a)-> index == ft_find_next_min((*b)-> index, a))
			ft_push(b, a, 'a');
		else
		{
			ft_get_total_cost(a, b, &total_cost);
			ft_rework_cost(&total_cost);
			ft_prepare_rotate(a, b, &total_cost);
			ft_prepare_rev_rot(a, b, &total_cost);
			ft_push(b, a, 'a');
			ft_empty_cost(total_cost);
			total_cost -> final_cost = 0;
		}
	}
	// ft_free_cost(total_cost);
	ft_get_one_on_top(a);
}

void	ft_get_one_on_top(t_list **a)
{
	int	c;

	c = ft_get_cost(1, a);
	if (c < 0)
	{
		while (c < 0)
		{
			ft_rev_rot(a, 'a');
			c++;
		}
	}
	else if (c > 0)
	{
		while (c > 0)
		{
			ft_rotate(a, 'a');
			c--;
		}
	}
}

/*	ft_init_sort
	This function will make it so that at the beginning of the sort algorithm,
	every nodes in stack a will be pushed into stack b excepted the min and max 
	values.	And each time a value is pushed into the b stack, we check if it is
	lower or higher	than the mid value of the index so that it will be rotated
	or not so that my b stack will be a little bit sorted too.
*/
void	ft_init_sort(t_list **a, t_list **b, int l)
{
	int	mid;
	int	size;

	if (!a || !*a) 
		return ;
	size = ft_lstsize(*a);
	mid = l / 2;
	while (size-- > 1)
	{
		if ((*a) && (*a)->index == l)
			ft_rotate(a, 'a');
		ft_push(a, b, 'b');
		if (!(*a))
			return ;
		if (*b && (*b)->index <= mid && (*b)->next)
			ft_rotate(b, 'b');
	}
}

