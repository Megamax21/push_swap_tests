/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 02:49:14 by ml-hote           #+#    #+#             */
/*   Updated: 2025/04/07 20:38:29 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_safe_atoi(const char *s, int *out)
{
	int			sign;
	size_t			i;
	long int	nb;

	nb = 0;
	i = 0;
	sign = 1;
	if (!s)
		return (0);
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (i == ft_strlen(s))
		return (0);
	if ((s[i] == '+' || s[i] == '-'))
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (nb > (2147483647 / 10) || (nb == (2147483647 / 10)
				&& (s[i] - '0') > 7 + (sign == -1)))
			return (0);
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	*out = sign * (int)nb;
	return (1);
}
