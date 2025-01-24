#include <stdio.h>

int is_power_of_2(unsigned int number) 
{
	if (number == 0)
	return (0);	
    while (number % 2 == 0) 
    {
	    number = number / 2;
	    if(number == 1)
		    return (printf("si"));
    }
    return (printf("no"));

}

int main() 
{
    (is_power_of_2(0));
    return (0);
}
