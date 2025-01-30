#include <unistd.h>
#include <stdlib.h>

void    ft_print_str(char *str)
{
    int flag;
    int i;

    i = 0;
    flag = 0;
    while(str[i])
    {
        if(str[i] == ' ' || str[i] == '\t')
            flag = 1;
        else if(str[i] != ' ' || str[i] != '\t')
        {
            if(flag == 1)
            {
                write(1, " ", 1);
                flag = 0;
            }
            write(1, &str[i], 1);
        }
        i++;
    }
}

char    *ft_res(char *str)
{
    int i;
    char *res;

    i = 0;
    while(str[i] && (str[i] != ' ' && str[i] != '\t'))
        i++;
    res = malloc((i + 1) * sizeof(char));
    i = 0;
    while(*str != ' ' && *str != '\t')
    {
        res[i] = *str;
        str++;
        i++;
    }
    res[i] = '\0';
    return(res);
}

int main(int ac, char **av)
{
    int     i;
    char    *res;
    char    *str;

    i = 0;
    if(ac >= 2)
    {
        str = av[1];
        while(*str == ' ' || *str == '\t') //quito el principio
            str++;
        res = ft_res(str); //tengo el principio en esta variable con el nulo
        while(*str && (*str != ' ' && *str != '\t')) //quito la palabra
            str++;
        while(*str == ' ' || *str == '\t') //quito los espacios y tab del medio
            str++;
        ft_print_str(str);
        if(ac == 2)
            write(1, " ", 1);
        ft_print_str(res);
    }
    write(1, "\n", 1);
    return(0);
}