/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:04 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/03 15:41:39 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/*	What is check_content ?
	check_content will be used at the start of my push_swap program
	It will check if all of the entered values are integers
	If the value is not an integer then the function will return 0
	In the other case it will return 1
*/
int	check_content(char *value)
{
	int	i;
	
	i = 0;
	if (value[0] == '-')
		i++;
	while (value[i] != '\0')
	{
		if (ft_isdigit(value[i]) == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_double(int val, t_list *l)
{
	t_list *l2;
	
	l2 = l;
	while (l2 != NULL)
	{
		if (l2 -> content == val)
			return (0);	
		l2 = l2 -> next;
	}
	return (1);
}