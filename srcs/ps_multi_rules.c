/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_multi_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:11:46 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/05 15:27:44 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) > 1)
		ft_swap(list_a, ' ');
	if (ft_lstsize(list_b) > 1)
		ft_swap(list_b, ' ');
	ft_print_rule("ss", '\0');
}

void	ft_rr(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) > 1)
		ft_rotate(&list_a, ' ');
	if (ft_lstsize(list_b) > 1)
		ft_rotate(&list_b, ' ');
	ft_print_rule("rr", '\0');
}

void	ft_rrr(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) > 1)
		ft_rev_rot(&list_a, ' ');
	if (ft_lstsize(list_b) > 1)
		ft_rev_rot(&list_b, ' ');
	ft_print_rule("rrr", '\0');
}
