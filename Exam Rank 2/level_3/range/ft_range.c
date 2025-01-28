#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int	*array;
	int	len;
	int	temp;
	int	i;

	i = 0;
	len = 0;
	temp = start;
	if(start == end)
	{
		array = malloc(1 * sizeof(int));
		if(!array)
			return(NULL);
		array[0] = 0;
	}
	if(start < end)
	{
		while(temp <= end)
		{
			temp++;
			len++;
		}
	}
	else if(start > end)
	{
		while(temp >= end)
		{
			temp--;
			len++;
		}
	}
	array = malloc((len + 1) * sizeof(int));
	while(i < len)
	{
		if(start < end)
		{
			array[i] = start;
			start++;
		}
		else
		{
			array[i] = start;
			start--;
		}
		i++;
	}

	return(array);
}
