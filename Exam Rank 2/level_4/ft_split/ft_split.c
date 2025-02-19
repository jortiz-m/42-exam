#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char	*ft_clean_str(char *str)
{
	int	i;
	int	j;
	char	*clean;

	i = 0;
	j = 0;
	clean = malloc((ft_strlen(str) + 1) * sizeof(char));
	while(str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') &&
		(str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n'))	
			i++;
		else
			clean[j] = str[i];
		j++;
		i++;
	}
	clean[j] = '\0';
	return(clean);
}

int	ft_count_word(char *str)
{
	int	i;
	int	counter;

	i = 0;
	while(str[i])
	{
		if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			counter++;
		i++;
	}
	return(counter);
}

char	**ft_create(char *str)
{
	char 	**split;
	int		start;
	int		end;
	int		i;
	int		a;
	int		b;

	i = 0;
	a = 0;
	b = 0;
	while(str[i])
	{
		start = i;
		while(str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		end = i;
		while(start < end)
		{
			split[a][b] = str[start];
			start++;
			b++;
		}
		split[a][b] = '\0';
		a++;
		while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
                        i++;
	}
	split[a] = NULL;
	return(split);
}

char    **ft_split(char *str)
{
	int	word;
	int	len_word;
	char	*clean;
	char	**split;

	while(*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	clean = ft_clean_str(str);
	word = ft_count_word(clean);
	split = malloc((word + 1) * sizeof (char *)); //char * o char?
	split[word] = '\0'; // revisar bien
	split = ft_create(clean);
	return(split);
}
