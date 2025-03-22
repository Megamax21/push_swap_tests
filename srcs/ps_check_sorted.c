/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:10:12 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/22 12:17:08 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_sorted(t_list **l)
{
	t_list	*l_adress;

	l_adress = (*l);
	while ((*l)-> next != NULL)
	{
		if (((*l)-> index) < (*l)-> next-> index)
			(*l) = (*l)-> next;
		else
		{
			(*l) = l_adress;
			return (0);
		}
	}
	(*l) = l_adress;
	return (1);
}
