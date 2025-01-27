char    *ft_strrev(char *str)
{
char    temp;
int     i;
int     len;

i = 0;
	if (!str)
		return(0);
	while(str[i])
		i++;
	i--;
	len = i;
	i = 0;
	while(i < len)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		i++;
		len--;
	}
	return(str);
}
