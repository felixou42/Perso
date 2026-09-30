int	clean_seps(char *str, char *charset, int i)
{
	int	j;
	int	sep_check;

	sep_check = 1;
	while (sep_check > 0)
	{
		sep_check = 0;
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				i++;
				sep_check++;
			}
			j++;
		}
	}
	return (i);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	i;
	int	j;
	int	char_is_sep;

	i = clean_seps(str, charset, 0);
	if (str[i] == '\0')
		return (0);
	count = 1;
	char_is_sep = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				if (char_is_sep == 0)
					count++;
				char_is_sep = 1;
			}
			j++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	result = malloc((word_count(str, charset) + 1) * sizeof(*char));
	while (str[i])
	{
		if (sep_check(str[i], charset))
			i++;
		else
		{
			
