#include <unistd.h>

int main(int ac, char **av)
{
        int     j = 1;
        int     i = 0;

        if(ac == 1)
                write(1, "\n", 1);
        while(j < ac)
        {
                i = 0;
                while(av[j][i])
                {
                        if(av[j][i + 1] == ' ' || av[j][i + 1] == '\0')
                        {
                                if(av[j][i] >= 'a' && av[j][i] <= 'z')
                                {
                                        av[j][i] = av[j][i] - 32;
                                }
                        }
                        else if(av[j][i] >= 'A' && av[j][i] <= 'Z')
                                av[j][i] = av[j][i] + 32;
                        write(1, &av[j][i], 1);
                        i++;
                }
                write(1, "\n", 1);
                j++;
        }
        return(0);
}
