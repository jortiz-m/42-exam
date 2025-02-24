#include <unistd.h>

int main(int ac, char **av)
{
	unsigned char seen[256] = {0};
	int i;

	i = 0;
	if(ac == 3)
	{
    	while(av[1][i])
   		{
        	if(!seen[(unsigned char)av[1][i]])
        	{
            	write(1, &av[1][i], 1);
           		seen[(unsigned char)av[1][i]] = 1;
        	}
        	i++;
    	}
    	i = 0;
    	while(av[2][i])
    	{
        	if(!seen[(unsigned char) av[2][i]])
        	{
           		write(1, &av[2][i], 1);
            	seen[(unsigned char) av[2][i]] = 1;
        	}
        	i++;
    	}
	}
	write(1, "\\n", 1);
	return(0);
}
