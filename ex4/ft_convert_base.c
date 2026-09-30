/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwildesh <fwildesh@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 21:34:29 by fwildesh          #+#    #+#             */
/*   Updated: 2026/09/30 14:28:53 by fwildesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_power(int a, int b);
int	ft_log(int a, int base);
void	normalize_nbr(char *nbr, char *nbr_norm, int check_negative);

int	search_digit(char digit, char *base_from)
{
	int	i;

	i = 0;
	while (base_from[i])
	{
		if (base_from[i] == digit)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert_dec(char *nbr, char *base_from, int len_from, int check_negative)
{
	int		nbr_in_dec;
	int		digit_in_base_from;
	int		i;
	int		len_nbr;
	char	*nbr_norm;

	normalize_nbr(nbr, nbr_norm, check_negative);
	len_nbr = ft_strlen(nbr_norm);
	i = 0;
	nbr_in_dec = 0;
	while (nbr_norm[i])
	{
		digit_in_base_from = search_digit(nbr_norm[i], base_from);
		nbr_in_dec += digit_in_base_from * ft_power(len_from, len_nbr - i - 1);
		i++;
	}
	return (nbr_in_dec);
}

char	*ft_convert_base_to(int nbr_in_dec, char *base_to, int len_to, int check_negative)
{
	char	*nbr_in_base_to;
	int		digits;
	int		i;
	int		j;

	digits = ft_log(nbr_in_dec, len_to);
	if (check_negative == 1)
		nbr_in_base_to = malloc(digits + 2);
	else
		nbr_in_base_to = malloc(digits + 1);
	i = check_negative;
	while (i < digits + check_negative)
	{
		j = 1;
		nbr_in_base_to[i] = base_to[0];
		while (nbr_in_dec >= ft_power(len_to, digits - i - 1))
		{
			nbr_in_base_to[i] = base_to[j];
			nbr_in_dec -= ft_power(len_to, digits - i - 1);
			j++;
		}
		i++;
	}
	nbr_in_base_to[i] = '\0';
	return (nbr_in_base_to);
}

int	base_parsing(char *base, int len)
{
	int	i;
	int	j;

	if (len < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i;
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	nbr_in_dec;
	int	len_from;
	int	len_to;
	int	check_negative;

	len_from = ft_strlen(base_from);
	len_to = ft_strlen(base_to);
	if (!base_parsing(base_from, len_from) || !base_parsing(base_to, len_to))
		return (NULL);
	if (nbr[0] == '-')
		check_negative = 1;
	else
		check_negative = 0;
	nbr_in_dec = ft_convert_dec(nbr, base_from, len_from, check_negative);
	return (ft_convert_base_to(nbr_in_dec, base_to, len_to, check_negative));
}

#include <stdio.h>
int	main(void)
{
	char *nbr = "11101110111000101111001100010";
	char *base_from = "01";
	char *base_to = "mOTgUet_";
	printf("%s\n", ft_convert_base(nbr, base_from, base_to));
	return (0);
}
