#include <stdlib.h>
int    ft_count_digit(int  nbr)
{
    int counter;

    counter = 0;
    if(nbr == 0)
        return(1);// necesita un espacio;
    if(nbr < 0) //si es negativo para el signo;
        counter = 1;
    while(nbr != 0)
    {
        nbr = nbr / 10;
        counter++;
    }
    return(counter);
}

char    *ft_itoa(int nbr)
{
    char    *str;
    int     size;

    size = ft_count_digit(nbr);
    str = malloc((size + 1)* sizeof(char));
    str[size] = '\0'; //importante las posiciones
    if(nbr == 0)
        return("0");
    if(nbr < 0)
    {
        str[0] = '-'; //esto está ya en el string
        nbr = nbr * (-1); //quiero a positivo mi int para poder dividir
    }
    size--;
    while(nbr > 0)
    {
        str[size] = (nbr % 10) + '0';
        nbr = nbr / 10;
        size--;
    }
    return(str);
}