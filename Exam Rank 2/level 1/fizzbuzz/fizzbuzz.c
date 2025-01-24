#include <unistd.h>

void	ft_writenumber(int n)
{
	char	c;

	if(n >= 10)
		ft_writenumber(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int main()
{
	int n;

	n = 1;
	while (n <= 100)
	{
		if (n % 3 == 0)
			write(1, "Fizz", 4);
		else if (n % 5 == 0)
			write(1, "buzz", 4);
		else if (n % 15 == 0)
			write (1, "Fizzbuzz", 8);
		else
			ft_writenumber(n);
		write(1, "\n", 1);
		n++;
	}
	return (0);
}
