#include "unistd.h"

void rev_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		write(1, &str[i],1);
		i--;
	}
}


int main()
{
	char str[10] = "HolaQueTal";

	rev_print(str);
	return ;
}
