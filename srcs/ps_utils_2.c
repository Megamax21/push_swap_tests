/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:05:36 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/09 16:31:38 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_next_min(int i, t_list **l)
{
	t_list	*tmp;
	int		next_min;

	tmp = (*l);
	next_min = ft_find_i_max(l);
	while (tmp != NULL)
	{
		if (tmp->index > i && tmp->index < next_min)
			next_min = tmp->index;
		tmp = tmp->next;
	}
	return (next_min);
}
