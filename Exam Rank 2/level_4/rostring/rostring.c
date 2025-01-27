#include <stdlib.h>
#include <unistd.h>

char	*ft_save(char *str) // coseguir la primera palabra y gardarla para ponerla al final
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (str[len] != ' ' && str[len] != '\t') // +1 para el nulo
		len++;
	res = malloc((len + 1) * sizeof(char*));
	while(*str && i < len)
	{
		res[i] = *str;
		i++;
		str++;
	}
	res[i] = '\0'; 
	return(res);
}

void	ft_print(char *str)
{
	int	flag;

	flag = 0;
	while(*str)
	{
		if(*str != ' ' && *str != '\t')
		{
			if(flag)
			{
				write(1, " ", 1);
				flag = 0;
			}
			write(1, str, 1);
		}
		else if (*str == ' ' && *(str + 1) != ' ')
			flag = 1;
		else if (*str == '\t' && *(str + 1) != '\t')
			flag = 1;	
		str++;
	}
}

int main(int ac, char **av)
{
	char	*str;
	char	*res;

	str = av[1];
	if(ac == 2)
	{
		while(*str == ' ' || *str == '\t') //quitando espacios de delante
			str++;
		res = ft_save(str); //coger la primera palabra
		while(*str && (*str != ' ' && *str != '\t')) //quito la primera palabra de mi argumento
			str++;
		while(*str == ' ' || *str == '\t') //quitando espacios multiples después de quitar la primera palabra
			str++;
		ft_print(str);
		write(1, " ", 1);
		ft_print(res);
	}
	write(1, "\n", 1);
	return (0);
}