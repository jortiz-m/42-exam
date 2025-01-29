#include <unistd.h>
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	i = 0;
	while(str[i] == 32 || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] -'0';
		i++;
	}
	return(num * sign);		
}

void	ft_putnbr(int number)
{
	if(number >= 10)
		ft_putnbr(number / 10);
	number = number % 10 + '0';
	write(1, &number, 1);

}
int main(int ac, char **av)
{
	int	i;
	int	number;

	i = 1;
	if(ac == 2)
	{
		number = ft_atoi(av[1]);
		while(i < 10)
		{
			ft_putnbr(number);
			write(1, " x ", 3);
            ft_putnbr(i);
            write(1, " = ", 3);
            ft_putnbr(i * number);
            write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}