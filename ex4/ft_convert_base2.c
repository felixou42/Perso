/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 21:35:20 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/30 14:25:12 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_power(int a, int b)
{
	int	power;

	power = 1;
	while (b > 0)
	{
		power *= a;
		b--;
	}
	return (power);
}

int	ft_log(int a, int base)
{
	int	log;

	log = 0;
	while (ft_power(base, log) <= a)
		log++;
	return (log);
}

void	normalize_nbr(char *nbr, char *nbr_norm, int check_negative) 
{
	int	i;
	int	len_nbr;

	len_nbr = ft_strlen(nbr);
	i = 0;
	if (check_negative == 1)
	{
		nbr_norm = malloc(len_nbr);
		while (nbr[i + 1])
		{
			nbr_norm[i] = nbr[i + 1];
			i++;
		}
	}
	else
	{
		nbr_norm = malloc(len_nbr + 1);
		while (nbr[i])
		{
			nbr_norm[i] = nbr[i];
			i++;
		}
	}
	nbr_norm[i] = '\0';
}
