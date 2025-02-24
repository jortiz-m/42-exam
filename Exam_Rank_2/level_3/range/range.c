#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
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
int main(void)
{
    int start = 0;
    int end = -3;
    int *array;
    int len;
    int i;

    // Determinar la longitud del array
    len = (start > end) ? (start - end) : (end - start);
    len += 1; // Incluir ambos extremos

    array = ft_rrange(start, end);
    if (!array)
    {
        printf("Error al asignar memoria\n");
        return (1);
    }

    // Imprimir el array
    printf("Array generado: ");
    for (i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");

    // Liberar memoria
    free(array);

    return (0);
}
