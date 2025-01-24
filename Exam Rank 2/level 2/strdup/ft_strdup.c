char	*ft_strdup(const char *s1)
{
	int	i;
	int	len;
	char	*str;

	i = 0;
	while(s1[i])
		i++;
	len = i;
	str = (malloc(len + 1) * sizeof(char));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s1)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
