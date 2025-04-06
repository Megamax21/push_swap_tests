/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:04 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/06 10:35:13 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	What is ft_check_content ?
	ft_check_content will be used at the start of my push_swap program
	It will check if all of the entered values are integers
	If the value is not an integer then the function will return 0
	In the other case it will return 1
*/

int ft_is_all_good(char *v, t_list *s)
{
	if (ft_check_content(v) == 0
		|| ft_check_double(ft_atoi(v), s) == 0)
		return (0);
	return (1);
}

int	ft_fill_stack(int len, char **entries, t_list **stack)
{
	int	i;
	int	value;

	i = 1;
	while (i < len)
	{
		if (ft_safe_atoi(entries[i], &value) == 0
			|| ft_is_all_good(entries[i], *stack) == 0)
		{
			ft_putstr_fd("Error\n", 1);
			ft_safelstclear(stack);
			return (0);
		}
		ft_lstadd_back(stack, ft_lstnew(value));
		i++;
	}
	return (1);
}
/* 	Check content 
	This functions helps check a value at the beginning of 
	push swap when the program takes in the args. It checks
	if the value is a digital one
*/
int	ft_check_content(char *value)
{
	int	i;

	i = 0;
	if (value[0] == '-')
	{
		i++;
		if (ft_strlen(value) < 2)
			return (0);
	}
	while (value[i] != '\0')
	{
		if (ft_isdigit(value[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_double(int val, t_list *l)
{
	t_list	*stack_b;

	stack_b = l;
	while (stack_b != NULL)
	{
		if (stack_b -> content == val)
			return (0);
		stack_b = stack_b -> next;
	}
	return (1);
}

int	ft_get_cost(int ind, t_list **a )
{
	t_list	*temp;
	int		i;
	int		mid;

	mid = ft_lstsize(*a) / 2;
	i = 0;
	temp = *a;
	while (temp != NULL && temp -> index != ind)
	{
		i++;
		temp = temp -> next;
	}
	if (i > mid)
		return ((ft_lstsize(*a) - i) * (-1));
	else
		return (i);
}
