/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:03:39 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/05 15:30:27 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **from, t_list **to, char name_to)
{
	if (from != NULL)
	{
		ft_lstadd_front(to, ft_lstnew((*from)-> content));
		(*from) = (*from)-> next;
		ft_print_rule("p", name_to);
	}
}

void	ft_swap(t_list *l, char name)
{
	int		first;
	t_list	*stack_b;

	stack_b = l;
	if (ft_lstsize(l) > 1)
	{
		first = stack_b -> next -> content;
		l -> next -> content = l -> content;
		l -> content = first;
	}
	ft_print_rule("s", name);
}

void	ft_rotate(t_list **l, char name)
{
	int		nb;
	int		i;
	int		j;
	t_list	*l_adress;

	i = 0;
	j = (ft_lstsize(*l) - 1);
	l_adress = (*l);
	nb = (*l)-> content;
	while (i < j)
	{
		(*l)-> content = (*l)-> next -> content;
		(*l) = (*l)-> next;
		i++;
	}
	(*l)-> content = nb;
	(*l) = l_adress;
	ft_print_rule("r", name);
}

void	ft_rev_rot(t_list **l, char name)
{
	int		i;
	int		paste;
	int		copy;
	t_list	*l_adress;

	i = ft_lstsize(*l) - 1;
	l_adress = (*l);
	copy = (*l)-> content;
	(*l)-> content = ft_lstlast(*l)-> content;
	(*l) = (*l)-> next;
	i--;
	while ((i--) >= 0)
	{
		paste = copy;
		copy = (*l)-> content;
		(*l)-> content = paste;
		(*l) = (*l)-> next;
	}
	(*l) = l_adress;
	ft_print_rule("rr", name);
}
