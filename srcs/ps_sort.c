/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:41:29 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/28 20:06:39 by ml-hote          ###   ########.fr       */
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
		else if (len > 5)
		{
			ft_long_sort(stack_a, stack_b, length);
		}
	}
}

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
	int 	start;
	
	start = 0;
	temp_b = *b;
	best_cost = ft_newcost(0);
	temp_c = ft_newcost(0);
	while (temp_b != NULL)
	{
		ft_empty_cost(&temp_c);
		if (ft_get_cost(ft_find_next_min(temp_b -> index, a), a) >= 0)
		{
			temp_c -> ra = ft_get_cost(ft_find_next_min(temp_b -> index, a), a);
			temp_c -> actual_cost += ft_get_cost(ft_find_next_min(temp_b -> index, a), a);
		}
		else
		{
			temp_c -> rra -= ft_get_cost(ft_find_next_min(temp_b -> index, a), a);
			temp_c -> actual_cost -= ft_get_cost(ft_find_next_min(temp_b -> index, a), a);
		}
		if (ft_get_cost(temp_b -> index, b) >= 0)
		{
			temp_c -> rb = ft_get_cost(temp_b -> index, b);
			temp_c -> actual_cost += ft_get_cost(temp_b -> index, b);
		}
		else
		{
			temp_c -> rrb -= ft_get_cost(temp_b -> index, b);
			temp_c -> actual_cost -= ft_get_cost(temp_b -> index, b);
		}
		if (start == 0)
		{
			ft_rework_cost(&temp_c);
			temp_c -> final_cost = temp_c -> actual_cost;
			best_cost = temp_c;
			(*total_cost) = best_cost;
			start = 1;
		}
		if (temp_c -> actual_cost < temp_c -> final_cost)
		{
			ft_rework_cost(&temp_c);
			temp_c -> final_cost = temp_c -> actual_cost;
			best_cost = temp_c;
			(*total_cost) = best_cost;
			//ft_print_cost(temp_c);
		}		
		best_cost -> actual_cost = 0;
		temp_b = temp_b -> next;
	}
}

void	ft_empty_cost(t_cost **c)
{
	(*c)->ra = 0;
	(*c)->rb = 0;
	(*c)->rr = 0;
	(*c)->rra = 0;
	(*c)->rrb = 0;
	(*c)->rrr = 0;
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

void	ft_long_sort(t_list **a, t_list **b, int length)
{
	t_cost *total_cost;

	total_cost = ft_newcost(0);
	ft_init_sort(a, b, length);
	while (ft_lstsize(*b) > 0)
	{
		// ft_print_list(*a, 'A');
		// ft_print_list(*b, 'B');
		if ((*a)-> index == ft_find_next_min((*b)-> index, a))
		{
			ft_push(b, a, 'a');
		}
		else
		{
			ft_get_total_cost(a, b, &total_cost);
			ft_prepare_stacks(a, b, &total_cost);
			ft_push(b, a, 'a');
			ft_empty_cost(&total_cost);
			total_cost -> final_cost = 0;
		}
		// printf("====\n");
	}
	ft_get_one_on_top(a);
}

void	ft_print_cost(t_cost *c)
{
	printf("RA : %i\n", c -> ra);
	printf("RB : %i\n", c -> rb);
	printf("RR : %i\n", c -> rr);
	printf("RRA : %i\n", c -> rra);
	printf("RRB : %i\n", c -> rrb);
	printf("RRR : %i\n", c -> rrr);
	printf("final : %i\n", c -> final_cost);
}

void	ft_prepare_stacks(t_list **a, t_list **b, t_cost **c)
{
	// ft_print_cost(*c);
	ft_rework_cost(c);
	// ft_print_cost(*c);
	while ((*c) -> ra > 0)
	{
		ft_rotate(a, 'a');
		(*c) -> ra--;
	}
	while ((*c) -> rb > 0)
	{
		ft_rotate(b, 'b');
		(*c) -> rb--;
	}
	while ((*c) -> rr > 0)
	{
		ft_rr(a, b);
		(*c) -> rr--;
	}
	while ((*c) -> rra > 0)
	{
		ft_rev_rot(a, 'a');
		(*c) -> rra--;
	}
	while ((*c) -> rrb > 0)
	{
		ft_rev_rot(b, 'b');
		(*c) -> rrb--;
	}
	while ((*c) -> rrr > 0)
	{
		// printf("RRR ici !!!\n");
		ft_rrr(a, b);
		// ft_print_list(*a, '5');
		// ft_print_list(*b, '6');
		(*c) -> rrr--;
	}
}

void	ft_execute_b(int place, t_list **b)
{
	while (place != 0)
	{
		if (place > 0)
		{
			place--;
			ft_rotate(b, 'b');
		}
		if (place < 0)
		{
			place++;
			ft_rev_rot(b, 'b');
		}
	}
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

	size = ft_lstsize(*a) - 1;
	mid = l / 2;
	if (*b)
		(*b) = (*b)-> next;
	while (size-- > 1)
	{
		if ((*a)-> index == l)
			ft_rotate(a, 'a');
		ft_push(a, b, 'b');
		if ((*b)-> index <= mid)
			ft_rotate(b, 'b');
	}
}
