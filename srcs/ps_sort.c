/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:41:29 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/22 12:17:26 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_list **entries)
{
	int	len;

	len = ft_lstsize(*entries);
	if (ft_check_sorted(entries) == 0)
	{
		if (len == 2)
			ft_sort_two(entries);
		if (len == 3)
			ft_sort_three(entries);	
	}
	
	ft_print_list(*entries, 'a');
}