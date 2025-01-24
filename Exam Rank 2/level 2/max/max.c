#include <stdio.h>

int	max(int	*tab, unsigned int len)
{
	int	i;
	int	j;
	int	save;
	int	ter;

	ter = 0;
	i = 0;
	j = 1;
	while(len >= ter)
	{
		if (tab[i] > tab[j])
		{
			j++;	
			save = tab[i];
		}
		else
		{
			i++;
			i = j;
		}
		ter++;
	}
	return (save);
}

int	main()
{
	int array[6] = {25, 34, 445, 22, 3, 61};
	unsigned int len = 6;
	printf("%i \n", max(array, len));
	return (0);
}
