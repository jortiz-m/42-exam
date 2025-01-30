#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    int     i;
    int     end;
    int     start;
    int     flag;

    i = 0;
    if(ac == 2)
    {
        while(av[1][i]) //llego al nulo
            i++;
        while(i >= 0)
        {
            while(av[1][i] == '\0' || av[1][i] == ' ' || av[1][i] == '\t') //me quito del nulo y espacios al final
                i--;
            end = i;
            while(av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')//recorro hacia atrás la última palabra
                i--;
            start = i + 1; //mas uno para colocarme en la primera letra
            flag = start;
            while(start <= end)
            {
                write(1, &av[1][start], 1);
                start++;
            }
            if(flag != 0) //la flag es donde emepezamos para cuando sea cero es la primera palabra
                write(1, " ", 1); //para que no haya un espacio al final de más
        }
    }
    write(1, "\n", 1);
    return(0);
}
