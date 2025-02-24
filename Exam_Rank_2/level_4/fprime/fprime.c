#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int flag;
    int number;
    int i;
    
    flag = 1;
    if(ac == 2)
    {
        number = atoi(av[1]);
        if(number == 0)
        {
            printf("\n");
            return (0);
        }
        if(number == 1)
            printf("1");
        while(number % 2 == 0)
        {
            if(flag == 0)
                printf("*");
            number = number / 2;
            printf("2");
               flag = 0;
        }
        i = 3   ;
        while(i * i <= number)
        {
            while(number % i == 0)
            {
                if(flag == 0)
                    printf("*");
                printf("%d", i);
                number = number / i;
                flag = 0;
            }
            i = i + 2;
        }
        if(number > 2)
        {
            if(flag == 0)
                printf("*");
            flag = 0;
            printf("%d", number);
        }   
	}
    printf("\n");
    return(0);
}

