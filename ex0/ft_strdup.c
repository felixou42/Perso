/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:03:08 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/22 20:27:26 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *dup)
{
	int	length;

	length = 0;
	while (*dup != '\0')
	{
		length++;
		*dup++;
	}
	return (length);
}

char	*ft_strdup(char *src)
{
	size_t	size;
	char	*dup;
	int		i;

	i = 0;
	size = ft_strlen(src) + 1;
	dup = malloc(size * sizeof(char));
	while (i < size)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "chaine de caracteres";

	printf("%s", ft_strdup(src));
	return (0);
}*/
