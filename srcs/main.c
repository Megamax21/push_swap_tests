/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:45:52 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/06 11:10:23 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg_c, char **arg_v)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		nb_args;

	nb_args = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (nb_args < arg_c)
		nb_args++;
	if (ft_fill_stack(arg_c, arg_v, &stack_a) == 0)
		return (0);
	ft_assign_index(&stack_a);
	ft_sort(&stack_a, &stack_b, arg_c - 1);
	ft_print_lst(stack_a);
	ft_safelstclear(&stack_a);
	if (stack_b)
		ft_safelstclear(&stack_b);
	// printf("LE PROGRAMME EST FINI\n");
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

void ft_print_cost(t_cost *c)
{
	printf("***** Afichage Cout *****\n");
	printf("ra %i \n", c -> ra);	
	printf("rb %i \n", c -> rb);
	printf("rr %i \n", c -> rr);
	printf("rra %i \n", c -> rra);
	printf("rrb %i \n", c -> rrb);
	printf("rrr %i \n", c -> rrr);
	printf("actual cost %i \n", c -> actual_cost);
	printf("final cost %i \n", c -> final_cost);
	printf("***** ------------- *****\n");
}

void ft_print_lst(t_list *list)
{
    t_list *current = list;
	printf("===== Afichage Liste =====\n");
    while (current != NULL)
    {
        printf("Index: %d, Contenu: %d\n", current->index, current->content);
        current = current->next;
    }
	printf("===== -------------- =====\n");
}