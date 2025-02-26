/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:56:04 by ml-hote           #+#    #+#             */
/*   Updated: 2025/02/26 13:13:21 by ml-hote          ###   ########.fr       */
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

		printf("rotate, chaque element dans la pile decale d'une position vers le haut ! CA MARCHE !!");

		// print_list(l1, 'a');
		// ft_rotate(&l1, 'a');
		// print_list(l1, 'a');
		
		// print_list (l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_push(&l1, &l2, 'b');
		// ft_rotate(&l2, 'b');
		// print_list(l2, 'b');
		
	}
	
	ft_putstr_fd("test\n", 1);
	return  (0);
}

int		print_list(t_list *l, char name)
{
	printf("\n=====\nAFFICHAGE DE LA PILE %c ! \n", name);
	t_list	*l2;
	int	i;

	i = 0;
	l2 = l;
	while (l2 != NULL)
	{
		ft_putnbr_fd(l2->content, 1); // Affichage de l'element
		ft_putchar_fd('\n', 1);
		l2= l2->next;
		i++;
	}
	printf("La liste a une taille de %i nombres ! \n",i);
	printf("Test avec notre fonction pour avoir la taille d'une pile : %i\n=====\n", ft_lstsize(l));

	return (i);
}

void	ft_swap(t_list *l, char name)
{

	int	first;
	t_list	*l2;

	l2 = l;
	if (ft_lstsize(l) > 1)
	{
		first = l2 -> next -> content;
		l -> next -> content = l -> content;
		l -> content = first;
	}
	ft_putchar_fd('s', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	//print_list(l);
}

/* RAPPEL
Juste un pense bete pour pas que j'oublie que lorsque je veux m'attaquer directement 
a l'adresse de ma pile il faut que je la mette entre parentheses comme ici avec (*a).
*a sans les parentheses ca ne marche pas !
*/

void	ft_push(t_list **from, t_list **to, char name_to)
{
	if (from != NULL)
	{
		ft_lstadd_front(to, ft_lstnew((*from) -> content));
		(*from) = (*from) -> next; 
		ft_putchar_fd('p', 1);
		ft_putchar_fd(name_to, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_rotate(t_list **l, char name)
{
	int	nb;
	int	i;
	int j;
	t_list	*l_adress;

	i = 0;
	j = (ft_lstsize(*l) - 1);
	l_adress = (*l); // On enregistre l'adresse de la premiere valeur pour la redonner a la liste ensuite
	nb = (*l) -> content; // On enregistre la valeur du premier element de la liste

	while (i < j)
	{
		/*	Comment ca marche ?
			Ici on parcourt toutes les valeurs de notre 
			liste afin de donner a chaque contenu la valeur
			du prochain chainon de la liste. Et apres l'avoir
			parcourue on donne a la derniere valeur la valeur 
			du contenu du tout premier chainon.
		*/
		(*l) -> content = (*l) -> next -> content;
		(*l) = (*l) -> next;
		i++;
		// printf("i = %i et taille de l = %i\n", i, j);
	}
	(*l) -> content = nb;
	(*l) = l_adress; // On redonne l'adresse de la premiere valeur a la liste !

	ft_putchar_fd('r', 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
}