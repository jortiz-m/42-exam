#include <unistd.h>
#include <stdarg.h>

int     ft_putchar(char c)
{
        return(write(1, &c, 1));
}

void    ft_putstr(char *str, int *len)
{
        if(!str)
                str = "(null)";
        while(*str)
        {
                *len += ft_putchar(*str);
                str++;
        }
}

void    ft_putnbr(int number, int *len)
{
        if(number == -2147483648)
        {
                ft_putstr("-2147483648", len);
                return ;
        }
        if(number < 0)
        {
                *len += ft_putchar('-');
                number = -number;
        }
        if(number >= 10)
                ft_putnbr((number / 10), len);
        *len += ft_putchar('0' + (number % 10));
}

void    ft_puthex(unsigned int  number, int *len)
{
        char    *hex = "0123456789abcdef";

        if(number >= 16)
                ft_puthex((number / 16), len);
        *len += ft_putchar(hex[number % 16]);
}
void    ft_format(va_list av, char c, int *len)
{
        if(c == 's')
                ft_putstr(va_arg(av, char*), len);
        else if(c == 'd')
                ft_putnbr(va_arg(av, int), len);
        else if(c == 'x')
                ft_puthex(va_arg(av, unsigned int), len);
}

int     ft_printf(const char *str, ...)
{
        va_list av;
        int     len;
        int     i;

        i = 0;
        len = 0;
        va_start(av, str);
        while(str[i])
        {
                if(str[i] == '%')
                {
                        i++;
                        ft_format(av, str[i], &len);
                }
                else
                        len += ft_putchar(str[i]);
                i++;
        }
        va_end(av);
        return(len);
}

#include <stdio.h>

int main(void)
{
        int len;

        // Caso de prueba para strings
        len = printf("El uno -> %s\n", "HolaMundo");
        printf("Impreso = %d\n", len);
        len = ft_printf("El mio -> %s\n", "HolaMundo");
        printf("Impreso = %d\n", len);
        printf("\n");

        // Caso de prueba para números decimales
        len = printf("El uno -> %d\n", 42);
        printf("Impreso = %d\n", len);
        len = ft_printf("El mio -> %d\n", 42);
        printf("Impreso = %d\n", len);
        printf("\n");

        // Caso de prueba para números hexadecimales
        len = printf("El uno -> %x\n", 42);
        printf("Impreso = %d\n", len);
        len = ft_printf("El mio -> %x\n", 42);
        printf("Impreso = %d\n", len);
        printf("\n");
    return (0);
}