# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *str)
{
	size_t	count;

	count = 0;
	if (!str == NULL)
		str = "(null)";
	while (*str)
	{ 
		count += (write(1, &str, 1));
		str++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	size_t	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar('0' + (n % 10));
	return (count);
}

int	ft_puthex(size_t lst, char c)
{
	size_t	count;

	count = 0;
	if (lst >= 16)
		count += ft_puthex(lst / 16, c);
	if (c == 'x')
		ft_putchar("0123456789abcdef" [lst % 16]);
	count ++;
	return (count);
}

static int	ft_format(va_list lst, char c )
{
	int	totallen;

	totallen = 0;
	if (c == 's')
		totallen = ft_putstr(va_arg (lst, char *));
	else if (c == 'd' || c == 'i')
		totallen = ft_putnbr(va_arg (lst, size_t));
	else if (c == 'x')
		totallen = ft_puthex(va_arg (lst, size_t));
    else if (c == '%')
        totallen = ft_putchar('%');
    else
        return (0);
	return (totallen);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	if (write(1, "", 0) == -1)
		return (-1);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            len += ft_format(args, str[i]);
        }
        else
        {
            len += ft_putchar(str[i]);
        }
        i++;
    }
	va_end (args);
	return (len);
}