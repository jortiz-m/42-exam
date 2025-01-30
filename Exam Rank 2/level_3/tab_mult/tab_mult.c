#include <unistd.h>
int    atoi(const char *str)
{
    int i;
    int number;
    int sing;

    i = 0;
    number = 0;
    sing = 1;
    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-')
    {
        i++;
        sing = -1;
    }
    else if(str[i] == '+')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        number = number * 10 + str[i] - '0';
        i++;
    }
    return(number * sing);
}

void	ft_putnumber(int number)
{
	if(number >= 10)
		ft_putnumber(number / 10);
	number = number % 10 + '0';
	write(1, &number, 1);

}
int main(int ac, char **av)
{
    int i;
    int number;


    i = 1;
    if(ac == 2)
    {
        number = atoi(av[1]);
        while(i < 10)
        {
            ft_putnumber(i);
            write(1, " x ", 3);
            ft_putnumber(number);
            write(1, " = ", 3);
            ft_putnumber(i * number);
            write(1, "\n", 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}