char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	len = 0;
	while(str[len])
		len++;
	len--;
	i = 0;
	while(i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	return(str);
}

