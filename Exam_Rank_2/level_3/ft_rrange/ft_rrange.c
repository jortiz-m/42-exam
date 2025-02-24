#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
        int     *array;
        int     size;
        int     i;

        i = 0;
        if(start < end)
        {
                size = end - start;
                array = malloc((size + 1) * sizeof(int));
                while(start <= end)
                {
                        array[i] = end;
                        end--;
                        i++;
                }
        }
        else if(start > end)
        {
                size = start - end;
                array = malloc((size + 1) * sizeof(int));
                while(start >= end)
                {
                        array[i] = end;
                        end++;
                        i++;
                }
        }
        else
                array[0] = start;
        return(array);
}
