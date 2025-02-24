#ifndef LIST_H
# define LIST_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    struct s_list   *next;
    void            *data;
}   t_list;

#endif