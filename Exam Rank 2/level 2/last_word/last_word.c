#include <unistd.h>

void	last_word(char *str)
{
	int	i;
	int	end;
	int	start;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'|| str[i] == '\0'))
		i--;
	end = i;
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		i--;
	start = i + 1;
	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
}
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		last_word(argv[1]);	
	}
	write (1, "\n", 1);
	return (0);
}
