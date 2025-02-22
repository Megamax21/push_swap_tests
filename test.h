/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:57:06 by ml-hote           #+#    #+#             */
/*   Updated: 2025/02/22 16:59:13 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdint.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

/* TEST FUNCTIONS */

/* Returns an int that represents the length of the linked list
	an takes a linked list as the l argument */
int		printf_list(t_list *l);

#endif // LIBFT