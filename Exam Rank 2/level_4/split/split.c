#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_clean_str(char *str)
{
    int 	i;
	int		j;
	char	*clean;

	i = 0, 
	j = 0;
    clean = malloc((ft_strlen(str) + 1) * sizeof(char));
    while (str[i])
    {
        if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') &&
            (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n'))
            i++;
        else
		{
            clean[j] = str[i];
			j++;
			i++;
		}
    }
    clean[j] = '\0';
    return (clean);
}

int ft_count_word(char *str)
{
    int	i;
	int	counter;

	i = 0;
	counter = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            counter++;
            while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
                i++;
        }
    }
    return (counter);
}

char **ft_create(char *str, int word_count)
{
    char 	**split;
	int		i;
	int		a;
	int		b;
	int		end;
	int		start;

    i = 0;
	a = 0;
	b = 0;

	split = malloc((word_count + 1) * sizeof(char *));
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        start = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        end = i;
        split[a] = malloc((end - start + 1) * sizeof(char));
        while (start < end)
		{
            split[a][b] = str[start];
			b++;
			start++;
		}
        split[a][b] = '\0';
        a++;
    }
    split[a] = NULL;
    return (split);
}

char **ft_split(char *str)
{
	char	**split;
	int		word_count;
	char	*clean;

    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    clean = ft_clean_str(str);
    word_count = ft_count_word(clean);
    split = ft_create(clean, word_count);
    free(clean);
    return (split);
}
