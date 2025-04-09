/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:45:52 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/10 00:13:45 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg_c, char **arg_v)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		nb_args;

	if (arg_c == 1)
		return (0);
	ft_set_values(&stack_a, &stack_b, &nb_args, &args);
	if (arg_c == 2)
	{
		if (ft_handle_two_args(arg_v, &nb_args, &args) == 0)
			return (0);
	}
	else
		ft_handle_more_args(&args, &arg_c, &arg_v);
	while (nb_args < arg_c)
		nb_args++;
	if (ft_fill_stack(arg_c, nb_args, args, &stack_a) == 0)
		return (0);
	ft_assign_index(&stack_a);
	ft_sort(&stack_a, &stack_b, nb_args - 1);
	ft_handle_frees(&args, &stack_a, &stack_b);
	return (0);
}

void	ft_safelstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_free_cost(t_cost *c)
{
	if (c != NULL)
	{
		free(c);
		c = NULL;
	}
}

void	ft_print_cost(t_cost *c)
{
	dprintf(2, "***** Afichage Cout *****\n");
	dprintf(2, "ra %i \n", c->ra);
	dprintf(2, "rb %i \n", c->rb);
	dprintf(2, "rr %i \n", c->rr);
	dprintf(2, "rra %i \n", c->rra);
	dprintf(2, "rrb %i \n", c->rrb);
	dprintf(2, "rrr %i \n", c->rrr);
	dprintf(2, "actual cost %i \n", c->actual_cost);
	dprintf(2, "final cost %i \n", c->final_cost);
	dprintf(2, "***** ------------- *****\n");
}

void	ft_print_lst(t_list *list)
{
	t_list	*current;

	current = list;
	printf("===== Afichage Liste =====\n");
	while (current != NULL)
	{
		dprintf(2, "Index: %d, Contenu: %d\n",
			current->index, current->content);
		current = current->next;
	}
	printf("===== -------------- =====\n");
}
