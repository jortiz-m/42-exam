#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    char    *str;
    int     i;
    int     start;
    int     end;
    int     flag;
    int     printed;

    printed = 0;
    flag = 0;
    end = 0;
    i = 0;
    str = av[1];
    if(ac == 2)
    {
        while(str[i] == ' ' || str[i] == '\t')
            i++;
        start = i;
        while(str[i] && (str[i] != ' ' && str[i] != '\t')) 
            i++;
        end = i;
        while(str[i] == ' ' || str[i] == '\t')
            i++;
        while(str[i])
        {
            if(str[i] == ' ' || str[i] == '\t')
                flag = 1;
            else
            {
                if(flag == 1)
                    write(1, " ", 1);
                flag = 0;
                write(1, &str[i], 1);
                printed = 1;
            }
            i++;
        }
        if(printed == 1 && start < end)
            write(1, " ", 1);
        while(start < end)
        {
            write(1, &str[start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return(0);
}
