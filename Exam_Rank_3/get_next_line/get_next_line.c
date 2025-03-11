#include <unistd.h> //read
#include <stdio.h> //printf
#include <stdlib.h> //malloc
#include <fcntl.h> //fd

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


char *ft_strdup(char *line)
{
	char *new;
	int i = 0;
	while(line[i])
		i++;
	new = malloc((i + 1)* sizeof(char *));
	if(!new)
		return(NULL);
	i = 0;
	while(line[i])
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return(new);
}

char *get_next_line(int fd)
{
	char			line[70000]; //el que devuelvo
	static char		buffer[BUFFER_SIZE]; //donde hago la lectura
	static int 		buffer_read; //lo que leemos
	static int		buffer_pos; //lo que hemos copiado
	int i;

	i = 0;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	while(1)
	{
		if(buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if(buffer_read <= 0)
				break;
		}
		if(line[i - 1] == '\n')
			break;
		line[i] = buffer[buffer_pos];
		i++;
		buffer_pos++;
	}
	line[i] = '\0';
	if(i == 0)
		return(NULL);
	return(ft_strdup(line));
}