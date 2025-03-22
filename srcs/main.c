#include "../includes/push_swap.h"

int		main(int arg_c, char **arg_v)
{
	t_list	*stack_a;
	
	/*	Petits tests pour voir si je me souviens toujours
		bien des argc argv !	*/

	int		nb_args;

	nb_args = 1;
	printf("\nMon programme prend %i arguments \n", arg_c - 1);
	while (nb_args < arg_c)
	{
		printf("arg %i : %s\n", nb_args, arg_v[nb_args]);
		nb_args++;
	}

	/*	Tests sur listes chainees	*/
	printf("Comment ca marche les listes chainees ?\n");
	
	if (ft_fill_stack(arg_c, arg_v, &stack_a) == 0)
		return (0);
	else
		printf("C'est passe\n");

	ft_assign_index(&stack_a);
	ft_print_list(stack_a, '1');
	//ft_swap(&stack_a, 'a');
	ft_sort(&stack_a);
	ft_print_list(stack_a, '3');
	return  (0);
}
