#include "get_next_line.h"

char	*get_next_line(int fd) 			
{					
    char	*buffer;					
	int		bytes_read;						
    int 	i;
	char	c;							

    i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)				
		return (NULL);
	buffer = malloc(42000000);	
	if (!buffer)						
		return (NULL);
    bytes_read = read(fd, &c, 1);				
	while (bytes_read > 0)
	{
		buffer[i] = c;				
		i++;
		if (c == EOF || c == '\n')		
			break ;
            bytes_read = read(fd, &c, 1);	
	}
	if (i == 0 || bytes_read < 0)
	{
		free(buffer);		
		return (NULL);		
	}
	buffer[i] = '\0';			
	return (buffer);		
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (1);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s\n", line);
			free(line);	
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (0);
}
