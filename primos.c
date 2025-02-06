#include <stdio.h>
#include <stdbool.h>

bool	ft_primos(unsigned int number)
{
	int 	i;

	i = 2;
	while(i < number)
	{
		if(number % i == 0)
		{
			printf("El número %i no es primo\n", number);
			return(0);
		}
		i++;
	}
	printf("El número %i es primo\n", number);
	return(1);
}
int main()
{

	ft_primos(37);
	return(0);
}