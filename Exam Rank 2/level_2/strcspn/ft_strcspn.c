size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		while (reject[j])
		{
			j = 0;
			if(s[i] == reject[j])
				return (i);		
			j++;
		}
		i++;
	}	
	return (i);
}
