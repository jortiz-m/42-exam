#include <stdio.h>

int		ft_max(int* tab, unsigned int len)
{
	int	max;
	int	i;

	i = 0;
	max = tab[0];
	while(i < len)
	{
		if(max < tab[i])
			max = tab[i];
		i++;
	}
	return(max);
}

int main()
{
	int max[] = {1, 8, 6, 3};
	unsigned int len = 4;
	printf("%d", ft_max(max, len));
	return(0);
}
