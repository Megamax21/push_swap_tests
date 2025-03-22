/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fill_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:04 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/20 16:24:46 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*	What is ft_check_content ?
	ft_check_content will be used at the start of my push_swap program
	It will check if all of the entered values are integers
	If the value is not an integer then the function will return 0
	In the other case it will return 1
*/

int	ft_fill_stack(int len, char **entries, t_list **stack)
{
	int	i;
	int	value;

	i = 0;
	if (len >= 2)
	{
		(*stack) = ft_lstnew(ft_atoi(entries[1]));
		i = 2;
		while (i < len)
		{
			if (ft_check_content(entries[i]) == 0
				|| ft_check_double(ft_atoi(entries[i]), *stack) == 0
				|| ft_safe_atoi(entries[i], &value) == 0)
			{
				ft_putstr_fd("Error\n", 1);
				return (0);
			}
			ft_lstadd_back(stack, ft_lstnew(value));
			i++;
		}
		return (1);
	}
	return (0);
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

int	ft_print_list(t_list *l, char name)
{
	t_list	*stack_b;
	int		i;

	printf("\n=====\nAFFICHAGE DE LA PILE %c ! \n", name);
	i = 0;
	stack_b = l;
	while (stack_b != NULL)
	{
		printf ("content = %i || index = %i\n", stack_b->content, stack_b->index);
		stack_b = stack_b->next;
		i++;
	}
	printf("La liste a une taille de %i nombres ! \n", i);
	return (i);
}
