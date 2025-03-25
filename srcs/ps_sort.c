/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:41:29 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/25 13:37:34 by ml-hote          ###   ########.fr       */
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
		if (len == 3)
			ft_sort_three(stack_a);
		if (len > 5)
			ft_long_sort(stack_a, stack_b, length);
	}
}

void	ft_long_sort(t_list **a, t_list **b, int length)
{
	ft_init_sort(a, b, length);
	while (ft_lstsize(*b) > 0)
	{
		if ((*a)-> index == ft_find_next_min((*b)-> index, a))
			ft_push(b, a, 'a');
		else
		{
			if (ft_lstsize(*b) > 2)
			{
				ft_prepare_b(a, b);
			}
			ft_prepare_a(a, b);
			ft_push(b, a, 'a');
		}
	}
	ft_get_one_on_top(a);
}

void	ft_prepare_a(t_list **a, t_list **b)
{
	int	cost;

	cost = ft_get_cost(ft_find_next_min((*b)-> index, a), a);
	if (cost > 0)
	{
		while (cost > 0)
		{
			ft_rotate(a, 'a');
			cost--;
		}
	}
	else if (cost < 0)
	{
		while (cost < 0)
		{
			ft_rev_rot(a, 'a');
			cost ++;
		}
	}
}

void	ft_prepare_b(t_list **a, t_list **b)
{
	t_list	*temp;
	int		lower_cost;
	int		l;
	int		i;
	int		place;

	temp = (*b);
	place = 0;
	lower_cost = ft_lstsize(*b);
	i = 0;
	l = ft_lstsize(*b);
	while (l > 0)
	{
		if (ft_get_cost(ft_find_next_min(temp -> index, a), a) < lower_cost)
		{
			lower_cost = ft_get_cost(ft_find_next_min(temp -> index, a), a);
			place = i;
		}
		temp = temp -> next;
		i++;
		l--;
	}
	l = ft_lstsize(*b);
	place--;
	if (place > l / 2)
		place = (l - place) * (-1);
	
	ft_execute_b(place, b);
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

void	ft_get_one_on_top(t_list	**a)
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
	while (size-- > 1)
	{
		if ((*a)-> index == 1 || (*a)-> index == l)
			ft_rotate(a, 'a');
		else if ((*a)-> index > (*a)-> next -> index)
			ft_swap(a, 'a');
		ft_push(a, b, 'b');
	}
	if ((*b)-> index <= mid)
		ft_rotate(b, 'b');
	if ((*a)-> index == 1)
		ft_swap(a, 'a');
}
