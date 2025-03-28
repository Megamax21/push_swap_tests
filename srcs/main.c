/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:45:52 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/28 21:22:48 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg_c, char **arg_v)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		nb_args;

	nb_args = 1;
	while (nb_args < arg_c)
		nb_args++;
	if (ft_fill_stack(arg_c, arg_v, &stack_a) == 0)
		return (0);
	ft_assign_index(&stack_a);
	ft_sort(&stack_a, &stack_b, arg_c - 1);
	// if (ft_check_sorted(&stack_a) == 0)
	// ft_safelstclear(&stack_a);
	// ft_safelstclear(&stack_b);
	// ft_print_list(stack_b, 'b');
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

int	ft_print_list(t_list *l, char name)
{
	t_list	*stack_b;
	int		i;

	printf("\n=====\nAFFICHAGE DE LA PILE %c ! \n", name);
	i = 0;
	stack_b = l;
	while (stack_b != NULL)
	{
		printf ("content = %i || index = %i\n", stack_b->content, stack_b->index);
		stack_b = stack_b->next;
		i++;
	}
	printf("La liste %c a une taille de %i nombres ! \n", name, i);
	return (i);
}
