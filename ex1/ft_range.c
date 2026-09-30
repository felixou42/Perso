/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:07:15 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/23 12:12:31 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	size_t	strlen;
	int		*tab;
	int		i;

	strlen = max - min + 1;
	tab = malloc(strlen * sizeof(int));
	i = 0;
	while (i < strlen)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
/*
#include <stdio.h>

int	main(void)
{
	int i = 0;
	while (i < 49)
	{
		printf("%d, ", ft_range(408, 457)[i]);
		i++;
	}
	return (0);
}*/
