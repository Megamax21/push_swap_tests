/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:03:39 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/20 16:22:22 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_list **from, t_list **to, char name_to)
{
	if (from != NULL)
	{
		ft_lstadd_front(to, ft_lstnew((*from)-> content));
		(*to)-> index = (*from)-> index;
		(*from) = (*from)-> next;
		ft_print_rule("p", name_to);
	}
}

void	ft_swap(t_list **l, char name)
{
	t_list	*first;
	t_list	*second;

	if (!l || !*l || !(*l)->next)
		return;
	first = *l;
	second = (*l)->next;
	first->next = second->next;
	second->next = first;
	*l = second;
	ft_print_rule("s", name);
}


void	ft_rotate(t_list **l, char name)
{
	t_list *first;
	t_list *last;
	
	first = *l;
	last = *l;
	if (*l && (*l)->next) 
	{
		while (last->next)
			last = last->next;

		*l = first->next;
		first->next = NULL; 
		last->next = first;
	}
	ft_print_rule("r", name);
}

void	ft_rev_rot(t_list **l, char name)
{
	t_list *prev;
	t_list *last;

	prev = NULL;
	last = *l;
	if (*l && (*l)->next) 
	{
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *l;
		*l = last;
	}
	ft_print_rule("rr", name);
}


void	ft_print_rule(char *rule, char stack)
{
	ft_putstr_fd(rule, 1);
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}
