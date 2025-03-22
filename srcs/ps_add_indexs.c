/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_add_indexs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:04 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/16 20:32:18 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* The find min function
	The find min function works in two times.
	
	PART 1
	First, it will go through the stack to check what is the minimum.
	PART 2
	Then it will get back into the stack until it finds it again (At
	this moment min will be assigned to the minimal value of the stack)
	to give it index value of 1.
	
	At the end we will return the value of min so that the def_index
	function will now where to start to put the values.
*/
int	ft_find_min(t_list **l)
{
	t_list	*l_adress;
	int		min;

	l_adress = (*l);
	min = (*l)-> content;
	(*l) = (*l)-> next;
	while ((*l) != NULL)
	{
		if ((*l)-> content < min)
			min = (*l)-> content;
		(*l) = (*l)-> next;
	}
	(*l) = l_adress;
	while ((*l) != NULL)
	{
		if ((*l)-> content == min)
			(*l)-> index = 1;
		(*l) = (*l)-> next;
	}
	(*l) = l_adress;
	return (min);
}

int	ft_find_max(t_list **l)
{
	t_list	*l_adress;
	int		max;

	l_adress = (*l);
	max = (*l)-> content;
	(*l) = (*l)-> next;
	while ((*l) != NULL)
	{
		if ((*l)-> content > max)
			max = (*l)-> content;
		(*l) = (*l)-> next;
	}
	(*l) = l_adress;
	return (max);
}

int	ft_find_next_min(int ind, int min, t_list **l)
{
	t_list	*l_adress;
	int		next_min;

	l_adress = (*l);
	next_min = ft_find_max(l);
	while ((*l) != NULL)
	{
		if ((*l)-> content > min && (*l)-> content < next_min)
			next_min = (*l)-> content;
		(*l) = (*l)-> next;
	}
	(*l) = l_adress;
	while ((*l) != NULL)
	{
		if ((*l)-> content == next_min)
			(*l)-> index = ind;
		(*l) = (*l)-> next;
	}
	(*l) = l_adress;
	return (next_min);
}

void	ft_assign_index(t_list **l)
{
	int	ind;
	int	j;
	int	n_min;

	ind = 2;
	j = ft_lstsize(*l) - 1;
	n_min = ft_find_min(l);
	while (j > 0)
	{
		n_min = ft_find_next_min(ind, n_min, l);
		ind++;
		j--;
	}
}
