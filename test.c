/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:56:04 by ml-hote           #+#    #+#             */
/*   Updated: 2025/02/25 16:33:53 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On va faire en sorte de tester vite fait des fonctions
afin de gerer les listes chainees, les voir, les manipuler
*/
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
	l2 = l1;

	/* Remplissage de la pile a */
	if (arg_c > 1)
	{
		printf("---\n");
		l1 = ft_lstnew(ft_atoi(arg_v[1])); // On donne a ma liste chainee sa toute premiere valeur
		printf("===\n");
		if (arg_c > 2)
		{
			nb_args = 2;
			while (nb_args < arg_c)
			{
				ft_lstadd_back(&l1, ft_lstnew(ft_atoi(arg_v[nb_args]))); // A chaque fois qu'on trouve un nouvel argument on le rajoute au tout debut de la liste
				nb_args++;
			}
		}
		

		printf("Arguments rajoutes a la liste\n");
		printf_list(l1);	
	}
	ft_putstr_fd("test\n", 1);
	return  (0);
}

int		printf_list(t_list *l)
{
	printf("Debut de fonction ! \n");
	int	i;

	i = 0;
	while (l != NULL)
	{
		ft_putnbr_fd(l->content, 1);
		ft_putchar_fd('\n', 1);
		l = l->next;
		i++;
	}
	printf("La liste a une taille de %i nombres ! \n",i);
	return (i);
}