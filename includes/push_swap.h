/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:57:06 by ml-hote           #+#    #+#             */
/*   Updated: 2025/03/28 20:00:36 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

/* TEST FUNCTIONS */

typedef struct s_cost
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int final_cost;
	int actual_cost;
}		t_cost;
/* Returns an int that represents the length of the linked list
	an takes a linked list as the l argument */
int		ft_check_sorted(t_list **l);
int		ft_check_content(char *value);
int		ft_check_double(int val, t_list *l);
int		ft_find_min(t_list **l);
int		ft_find_max(t_list **l);
int		ft_check_order(t_list *l);
int		ft_get_cost(int ind, t_list **a);
int		ft_fill_stack(int len, char **entries,t_list **stack);
int		ft_find_next_min(int i, t_list **l);
int		ft_assign_next_min(int ind, int min, t_list **l);
int		ft_print_list(t_list *l, char name);
int		ft_rework_cost(t_cost **c);
void	ft_swap(t_list **l, char name);
void	ft_push(t_list **from, t_list **to, char name_to);
void	ft_rotate(t_list **l, char name);
void	ft_rev_rot(t_list **l, char name);
void	ft_ss(t_list **list_a, t_list **list_b);
void	ft_rr(t_list **list_a, t_list **list_b);
void	ft_rrr(t_list **list_a, t_list **list_b);
void	ft_print_rule(char* rule, char stack);
void	ft_assign_index(t_list **l);
void	ft_sort_two(t_list **l);
void	ft_sort(t_list **stack_a, t_list **stack_b, int	length);
void	ft_sort_three(t_list **l);
void	ft_long_sort(t_list **a, t_list **b, int length);
void	ft_init_sort(t_list **a, t_list **b, int legnth);
void	ft_prepare_stacks(t_list **a, t_list **b, t_cost **c);
void	ft_get_one_on_top(t_list	**a);
void	ft_safelstclear(t_list **lst);
void	ft_execute_b(int place, t_list **b);
void	ft_get_total_cost(t_list **a, t_list **b, t_cost **total_cost);
void	ft_print_cost(t_cost *c);
void	ft_empty_cost(t_cost **c);
t_cost	*ft_newcost(int final_cost);

#endif