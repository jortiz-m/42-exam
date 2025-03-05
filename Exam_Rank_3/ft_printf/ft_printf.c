# include <stdarg.h>
# include <unistd.h>

int     ft_putchar(char c)
{
        return(write(1, &c, 1));
}

int     ft_putstr(char *str)
{
        size_t  count;

        count = 0;
        if (!str)
                str = "(null)";
        while (*str)
        {
                count += ft_putchar(*str);
                str++;
        }
        return (count);
}

int     ft_putnbr(int n)
{
        size_t  count;

        count = 0;
        if (n == -2147483648)
                return (write(1, "-2147483648", 11));
        if (n < 0)
        {
                count += ft_putchar('-');
                n = n * (-1);
        }
        if (n >= 10)
                count += ft_putnbr(n / 10);
        count += ft_putchar('0' + (n % 10));
        return (count);
}

size_t  ft_puthex(int n)
{
        size_t  count;

        count = 0;
        if (n >= 16)
                count += ft_puthex(n / 16);
        count += ft_putchar("0123456789abcdef" [n % 16]);
        return (count);
}

int     ft_format(va_list lst, char c)
{
        int     totallen;

        totallen = 0;
        if (c == 's')
                totallen = ft_putstr(va_arg (lst, char *));
        else if (c == 'd' || c == 'i')
                totallen = ft_putnbr(va_arg (lst, int));
        else if (c == 'x')
                totallen = ft_puthex(va_arg (lst, size_t));
        else if (c == '%')
                totallen = ft_putchar('%');
        else
                return (0);
        return (totallen);
}

int     ft_printf(const char *str, ...)
{
        va_list args;
        int     i;
        int     len;

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
                        len += ft_putchar(str[i]);
                i++;
        }
        va_end (args);
        return (len);
}

#include <stdio.h>
#include <limits.h>

// Prototipo de tu función ft_printf
int ft_printf(const char *format, ...);

int main(void)
{
    int count_ft;
    int count_std;

    // Caso de prueba para strings
    printf("\nPrueba para strings:\n");
    count_ft = ft_printf("ft_printf: %s\n", "Hola, mundo!");
    count_std = printf("printf:    %s\n", "Hola, mundo!");
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para enteros
    printf("\nPrueba para enteros:\n");
    count_ft = ft_printf("ft_printf: %d\n", 42);
    count_std = printf("printf:    %d\n", 42);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para enteros negativos
    printf("\nPrueba para enteros negativos:\n");
    count_ft = ft_printf("ft_printf: %d\n", -42);
    count_std = printf("printf:    %d\n", -42);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para hexadecimales
    printf("\nPrueba para hexadecimales:\n");
    count_ft = ft_printf("ft_printf: %x\n", 255);
    count_std = printf("printf:    %x\n", 255);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para el valor máximo de un int
    printf("\nPrueba para el valor máximo de un int:\n");
    count_ft = ft_printf("ft_printf: %d\n", INT_MAX);
    count_std = printf("printf:    %d\n", INT_MAX);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para el valor mínimo de un int
    printf("\nPrueba para el valor mínimo de un int:\n");
    count_ft = ft_printf("ft_printf: %d\n", INT_MIN);
    count_std = printf("printf:    %d\n", INT_MIN);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para strings
    printf("\nPrueba para strings:\n");
    count_ft = ft_printf("ft_printf: %s\n", "Hola, mundo!");
    count_std = printf("printf:    %s\n", "Hola, mundo!");
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para enteros
    printf("\nPrueba para enteros:\n");
    count_ft = ft_printf("ft_printf: %d\n", 42);
    count_std = printf("printf:    %d\n", 42);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para enteros negativos
    printf("\nPrueba para enteros negativos:\n");
    count_ft = ft_printf("ft_printf: %d\n", -42);
    count_std = printf("printf:    %d\n", -42);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para hexadecimales
    printf("\nPrueba para hexadecimales:\n");
    count_ft = ft_printf("ft_printf: %x\n", 255);
    count_std = printf("printf:    %x\n", 255);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para hexadecimales con mayúsculas
    printf("\nPrueba para hexadecimales con mayúsculas:\n");
    count_ft = ft_printf("ft_printf: %X\n", 255);
    count_std = printf("printf:    %X\n", 255);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para el valor máximo de un int
    printf("\nPrueba para el valor máximo de un int:\n");
    count_ft = ft_printf("ft_printf: %d\n", INT_MAX);
    count_std = printf("printf:    %d\n", INT_MAX);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Caso de prueba para el valor mínimo de un int
    printf("\nPrueba para el valor mínimo de un int:\n");
    count_ft = ft_printf("ft_printf: %d\n", INT_MIN);
    count_std = printf("printf:    %d\n", INT_MIN);
    printf("Caracteres impresos por ft_printf: %d\n", count_ft);
    printf("Caracteres impresos por printf:    %d\n", count_std);

    // Casos raros o edge cases
    printf("\n=== Casos raros o edge cases ===\n");

     // Caso de prueba para strings
     printf("\nPrueba para strings:\n");
     count_ft = ft_printf("ft_printf: %s\n", "Hola, mundo!");
     count_std = printf("printf:    %s\n", "Hola, mundo!");
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // Caso de prueba para enteros
     printf("\nPrueba para enteros:\n");
     count_ft = ft_printf("ft_printf: %d\n", 42);
     count_std = printf("printf:    %d\n", 42);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // Caso de prueba para enteros negativos
     printf("\nPrueba para enteros negativos:\n");
     count_ft = ft_printf("ft_printf: %d\n", -42);
     count_std = printf("printf:    %d\n", -42);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // Caso de prueba para hexadecimales
     printf("\nPrueba para hexadecimales:\n");
     count_ft = ft_printf("ft_printf: %x\n", 255);
     count_std = printf("printf:    %x\n", 255);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // Caso de prueba para hexadecimales con mayúsculas
     printf("\nPrueba para hexadecimales con mayúsculas:\n");
     count_ft = ft_printf("ft_printf: %X\n", 255);
     count_std = printf("printf:    %X\n", 255);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // Caso de prueba para el valor máximo de un int
     printf("\nPrueba para el valor máximo de un int:\n");
     count_ft = ft_printf("ft_printf: %d\n", INT_MAX);
     count_std = printf("printf:    %d\n", INT_MAX);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // Caso de prueba para el valor mínimo de un int
     printf("\nPrueba para el valor mínimo de un int:\n");
     count_ft = ft_printf("ft_printf: %d\n", INT_MIN);
     count_std = printf("printf:    %d\n", INT_MIN);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // Casos raros o edge cases
     printf("\n=== Casos raros o edge cases ===\n");
 
     // 1. Cadena vacía
     printf("\n1. Cadena vacía:\n");
     count_ft = ft_printf("ft_printf: %s\n", "");
     count_std = printf("printf:    %s\n", "");
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // 2. Puntero nulo (NULL) para %s
     printf("\n2. Puntero nulo (NULL) para %%s:\n");
     count_ft = ft_printf("ft_printf: %s\n", NULL); // Manejo manual de NULL
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
 
     // 3. Número cero
     printf("\n3. Número cero:\n");
     count_ft = ft_printf("ft_printf: %d\n", 0);
     count_std = printf("printf:    %d\n", 0);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // 4. Hexadecimal con cero
     printf("\n4. Hexadecimal con cero:\n");
     count_ft = ft_printf("ft_printf: %x\n", 0);
     count_std = printf("printf:    %x\n", 0);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // 5. Múltiples especificadores en un solo formato
     printf("\n5. Múltiples especificadores en un solo formato:\n");
     count_ft = ft_printf("ft_printf: %s %d %x\n", "Hola", 42, 255);
     count_std = printf("printf:    %s %d %x\n", "Hola", 42, 255);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // 6. Especificador sin argumento (corregido)
     printf("\n6. Especificador sin argumento:\n");
     count_ft = ft_printf("ft_printf: %s %d\n", "Hola", 42); // Eliminamos %x
     count_std = printf("printf:    %s %d\n", "Hola", 42);   // Eliminamos %x
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // 8. Caracteres no imprimibles en una cadena
     printf("\n8. Caracteres no imprimibles en una cadena:\n");
     count_ft = ft_printf("ft_printf: %s\n", "Hola\tmundo\n");
     count_std = printf("printf:    %s\n", "Hola\tmundo\n");
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);
 
     // 9. Especificador desconocido (corregido)
     printf("\n9. Especificador desconocido:\n");
     count_ft = ft_printf("ft_printf: %k\n", 42); // Prueba tu función
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
 
     // 10. Números grandes en hexadecimal
     printf("\n10. Números grandes en hexadecimal:\n");
     count_ft = ft_printf("ft_printf: %x\n", 0xDEADBEEF);
     count_std = printf("printf:    %x\n", 0xDEADBEEF);
     printf("Caracteres impresos por ft_printf: %d\n", count_ft);
     printf("Caracteres impresos por printf:    %d\n", count_std);

    return 0;
}