#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list  *head;
    int     temp;

    head = lst;
    while(lst->next)
    {
        if((*cmp)(lst->data, lst->next->data))
            lst = lst->next;
        else
        {
            temp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = temp;
            lst = head;
        }
    }
    lst = head;
    return(lst);
}
