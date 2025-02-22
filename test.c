/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:56:04 by ml-hote           #+#    #+#             */
/*   Updated: 2025/02/22 18:02:57 by ml-hote          ###   ########.fr       */
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
	printf("Mon programme prend %i arguments \n", arg_c - 1);
	while (nb_args < arg_c)
	{
		printf("arg %i : %s\n", nb_args, arg_v[nb_args]);
		nb_args++;
	}

	/*	Tests sur listes chainees	*/
	printf("Comment ca marche les listes chainees ?\n");
	l1 = ft_lstnew((void *)21);
	l2 = ft_lstnew((void *)22);
	printf("On cree deux variables !\n");
	
	//printf("Test valeur : %i", l1->content);
	ft_lstadd_back(&l1, l2);
	printf_list(l1);
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