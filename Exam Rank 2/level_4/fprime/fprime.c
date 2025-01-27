#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int	number;
	int	flg;
	int	i;

	if(argc == 2)
	{	
		number = atoi(argv[1]);
		if(number == 1)
			printf("1");
		else
		{
			flg = 1;
			while(number % 2 == 0)
			{
				if(flg == 0)
					printf("*");
				printf("2");
				number = number / 2;
				flg = 0;
			}
			i = 3;
			while(i * i <= number)
			{
				while(number % i == 0)
				{
					if(flg == 0)
						printf("*");
					printf("%d", i);
					number = number / i;
					flg = 0;
				}
				i += 2;
			}
			if(number > 2)
			{
				if(!flg)
					printf("*");
				printf("%d", i);
			}
		}
	}
	printf("\n");
	return(0);
}
