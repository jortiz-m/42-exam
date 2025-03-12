#include <unistd.h> //read
#include <stdio.h> //printf
#include <stdlib.h> //malloc

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *ft_strdup(char *str)
{
        char    *new;
        int     i;

        i = 0;
        while(str[i])
                i++;
        new = malloc((i + 1) * sizeof(char*));
        i = 0;
        while(str[i])
        {
                new[i] = str[i];
                i++;
        }
        new[i] = '\0';
        return(new);
}

char    *get_next_line(int fd)
{
        char            line[70000];
        static char     buffer[BUFFER_SIZE];
        static int      buffer_copy;
        static int      buffer_read;
        int             i;

        i = 0;
        if(fd < 0 || BUFFER_SIZE <= 0)
                return(NULL);
        while(1)
        {
                if(buffer_copy >= buffer_read)
                {
                        buffer_read = read(fd, buffer, BUFFER_SIZE);
                        buffer_copy = 0;
                        if(buffer_read <= 0)
                                break ;
                }
                if(line[i - 1] == '\n')
                        break ;
                line[i] = buffer[buffer_copy];
                i++;
                buffer_copy++;
        }
        line[i] = '\0';
        if(i == 0)
                return (NULL);
        return(ft_strdup(line));
}
