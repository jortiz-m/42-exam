#include <unistd.h>

int main(int  argc, char **argv)
{
	int	i;
	int	flg;

	i = 0;
	flg = 0;
	if(argc == 2)
	{
		while(argv[1][i] == 32 || argv[1][i] == '\t')
				i++;
		while(argv[1][i])
		{
			if(argv[1][i] == 32 || argv[1][i] == '\t')
				flg = 1;
			if(!(argv[1][i] == 32 || argv[1][i] == '\t'))
			{
				if (flg == 1)
					write(1, " ", 1);
				flg = 0;
				write(1, &argv[1][i], 1);	
			}
			i++;		
		}
	}
	write(1, "\n", 1);
	return(0);
}
