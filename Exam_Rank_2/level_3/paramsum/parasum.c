#include <unistd.h>

void ft_putnbr(int number)
{
	if(number >= 10)
		ft_putnbr(number / 10);
	number = number % 10 + '0';
	write(1, &number, 1); 
}
int	main(int ac, char **av)
{
	ft_putnbr(ac - 1);
	write(1, "\n", 1);
	return(0);
}
