#include "test.h"

int		main(int arg_c, char **arg_v)
{
	t_list	*l1;
	t_list	*l2;
	
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
		
	if (arg_c > 1)
	{
		printf("---\n");
		l1 = ft_lstnew(ft_atoi(arg_v[1])); // On donne a ma liste chainee sa toute premiere valeur
		printf("---\n");

		l2 = NULL;
		/* Remplissage de la pile a et de la pile b*/
		if (arg_c > 2)
		{
			nb_args = 2;
			while (nb_args < arg_c)
			{
				if (check_content(arg_v[nb_args]) == 0 || check_double(ft_atoi(arg_v[nb_args]), l1) == 0)
				{
					ft_putstr_fd("Error\n", 1);
					return (0);
				}
				
				ft_lstadd_back(&l1, ft_lstnew(ft_atoi(arg_v[nb_args]))); // A chaque fois qu'on trouve un nouvel argument on le rajoute au tout debut de la liste
				nb_args++;
			}
		}
		


		printf("Arguments rajoutes a la liste\n");
		print_list(l1, 'a');	
		//print_list(l2);
		
		// ====== TESTS DES REGLES ======
		printf("\n\nTESTS AVEC LES REGLES\n");
		printf("sa : swap les 2 premiers elements au sommet de la pile a... CA MARCHE, pareil pour sb\n");
		
		// printf("a avant :");
		// print_list(l1, 'a');
		// ft_swap(l1, 'a');
		// printf("a apres :");
		// print_list(l1, 'a');
		
		printf("\n\npb et pa... MARCHENT !\n");
		
		// print_list(l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// print_list(l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// print_list(l1, 'a');
		// print_list(l2, 'b');
		// ft_swap(l2, 'b');
		// print_list(l2, 'b');
		// ft_push(&l2, &l1, 'a');
		// print_list(l1, 'a');
		// print_list(l2, 'b');
		// ft_push(&l2, &l1, 'a');
		// print_list(l1, 'a');
		// print_list(l2, 'b');

		printf("rotate, chaque element dans la pile decale d'une position vers le haut ! CA MARCHE !!\nPAREIL POUR REVERSE ROTATE ! \n");

		// print_list(l1, 'a');
		// ft_rev_rot(&l1, 'a');
		// ft_push(&l1, &l2, 'b');
		// print_list(l1, 'a');
		
		// print_list (l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_rotate(&l2, 'b');
		// print_list(l2, 'b');
	
		printf("On va essayer avec rrr, rr et ss | TOUT EST BON ! On passe au reste\n");
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// print_list(l1, 'a');
		// print_list(l2, 'b');
		// ft_rrr(l1, l2);
		// print_list(l1, 'a');
		// print_list(l2, 'b');
	}
	
	ft_putstr_fd("test\n", 1);
	return  (0);
}
