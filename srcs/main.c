/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:45:52 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/09 16:28:05 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg_c, char **arg_v)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		nb_args;
	int		i;

	if (arg_c == 1)
		return (0);
	nb_args = 1;
	stack_a = NULL;
	stack_b = NULL;
	args = NULL;
	if (arg_c == 2)
	{
		if (ft_safe_atoi(arg_v[1], &i) && ft_check_content(arg_v[1]) == 1)
			return (0);
		nb_args = ft_countword(arg_v[1], ' ');
		if (nb_args == 0)
			return (0);
		args = ft_split(arg_v[1], ' ');
		if (!args || !args[0])
		{
			ft_putstr_fd("Error\n", 2);
			if (args)
				free_lst(args);
			return (0);
		}
	}
	else
	{
		i = 0;
		args = ft_calloc(arg_c, sizeof(char *));
		while (i < arg_c - 1)
		{
			args[i] = ft_strdup(arg_v[i + 1]);
			i++;
		}
		arg_c--;
	}
	while (nb_args < arg_c)
		nb_args++;
	if (ft_fill_stack(arg_c, nb_args, args, &stack_a) == 0)
		return (0);
	ft_assign_index(&stack_a);
	ft_sort(&stack_a, &stack_b, nb_args - 1);
	if (arg_c == 2)
		free_lst(args);
	ft_safelstclear(&stack_a);
	if (stack_b)
		ft_safelstclear(&stack_b);
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
