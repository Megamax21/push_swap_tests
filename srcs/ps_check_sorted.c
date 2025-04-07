/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:10:12 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/07 15:27:11 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_sorted(t_list **l)
{
	t_list	*temp;

	temp = (*l);
	while (temp->next)
	{
		if (temp->index < temp->next->index)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	ft_reset_index(t_list *lst)
{
	while (lst)
	{
		lst->index = 0;
		lst = lst->next;
	}
}
