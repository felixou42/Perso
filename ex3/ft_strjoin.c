/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:07:04 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/29 16:30:10 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen_total(int size, char **strs, char *sep)
{
	int		count;
	int		count_sep;
	char	*temp;

	count = 0;
	while (*strs)
	{
		temp = *strs;
		while (**strs)
		{
			count++;
			(*strs)++;
		}
		*strs = temp;
		strs++;
	}
	count_sep = 0;
	temp = sep;
	while (sep[count_sep])
		count_sep++;
	sep = temp;
	count += (size - 1) * count_sep;
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		i;
	int		j;
	int		total;

	total = ft_strlen_total(size, strs, sep);
	if (size == 0)
		return (malloc(0));
	join = malloc((total + 1) * sizeof(char));
	j = 0;
	while (*strs)
	{
		i = 0;
		while ((*strs)[i])
			join[j++] = (*strs)[i++];
		i = 0;
		if (j < total)
		{
			while (sep[i])
				join[j++] = sep[i++];
		}
		*strs++;
	}
	join[j + 1] = '\0';
	return (join);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*strs[] = {"123", "234", "345", "456", "567", NULL};
	char	*sep = "-";
	int		size = 5;

	printf("%s\n", ft_strjoin(size, strs, sep));
	return (0);
}*/
