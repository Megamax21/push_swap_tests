/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:56:04 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/04 16:01:48 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On va faire en sorte de tester vite fait des fonctions
afin de gerer les listes chainees, les voir, les manipuler
*/
#include "test.h"

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
	if (name != ' ')
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(name, 1);
		ft_putchar_fd('\n', 1);		
	}
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
		if (name_to != ' ')
		{
			ft_putchar_fd('p', 1);
			ft_putchar_fd(name_to, 1);
			ft_putchar_fd('\n', 1);		
		}
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

	if (name != ' ')
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(name, 1);
		ft_putchar_fd('\n', 1);		
	}
}
	
void	ft_rev_rot(t_list **l, char name)
{
	int		i;
	int		paste;
	int		copy;
	t_list	*l_adress;

	i = ft_lstsize(*l) - 1;
	l_adress = (*l);
	copy = (*l)-> content;
	(*l)-> content = ft_lstlast(*l)-> content;
	(*l) = (*l)-> next;
	i--;
	while (i >= 0)
	{
		paste = copy;
		copy = (*l)-> content;
		(*l)-> content = paste;
		(*l) = (*l)-> next;
		i--;
	}
	(*l) = l_adress;
	if (name != ' ')
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(name, 1);
		ft_putchar_fd('\n', 1);
	}
}


void	ft_ss(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) > 1)
		ft_swap(list_a, ' ');
	if (ft_lstsize(list_b) > 1)
		ft_swap(list_b, ' ');
	ft_putstr_fd("ss\n", 1);
}

void	ft_rr(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) > 1)
		ft_rotate(&list_a, ' ');
	if (ft_lstsize(list_b) > 1)
		ft_rotate(&list_b, ' ');
	ft_putstr_fd("rr\n", 1);

}

void	ft_rrr(t_list *list_a, t_list *list_b)
{
	if (ft_lstsize(list_a) > 1)
		ft_rev_rot(&list_a, ' ');
	if (ft_lstsize(list_b) > 1)
		ft_rev_rot(&list_b, ' ');
	ft_putstr_fd("rrr\n", 1);
}