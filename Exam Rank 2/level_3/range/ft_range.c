#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
{
    int size;
    int *array;
    int i;

    i = 0;
    if (start > end)
    {
        size = start - end;
        array = malloc((size + 1) * sizeof(int));
        if (!array)
            return (NULL);
        while (start >= end)
        {
            array[i] = start;
			start--;
			i++;
        }
    }
    else if (start < end)
    {
        size = end - start;
        array = malloc((size + 1) * sizeof(int));
        if (!array)
            return (NULL);
        while (start <= end)
        {
            array[i] = start;
			start++;
			i++;
        }
    }
    else
    {
        array = malloc(1 * sizeof(int));
        if (!array)
            return (NULL);
        array[0] = start;
    }
    return (array);
}
