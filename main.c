#include "ft_printf.h"

int main()
{
    int ret1;
    int ret2;

/*	char c;
	c = 'z';
	ret1 = ft_printf("%--4c\n",'1');
    ret2 = printf("%--4c\n", '1');
    printf("ma fct --4 c 1 null: ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
	ret1 = ft_printf("%-10c%*c%c*\n",'0', 10, '1', '2');
    ret2 = printf("%-10c%*c%c*\n",'0', 10, '1', '2');
    printf("ma fct -10 *(10) c null: ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("%-7.5s\n", "tubular");
    ret2 = printf("%-7.5s\n", "tubular");
    printf("ma fct -7.5s tubular : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

	ret1 = ft_printf(" %4.2s %-4.2s \n", "123", "4567");
    ret2 = printf(" %4.2s %-4.2s \n", "123", "4567");
    printf("ma fct 4.2s -4.2s s null: ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

    ret1 = ft_printf(" %-9.1s \n", NULL);
    ret2 = printf(" %-9.1s \n", NULL);
    printf("ma fct -9.1s null : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

	ret1 = ft_printf(" %*.0s %.2s ", 10, "123", "4567");
    ret2 = printf(" %*.0s %.2s ", 10, "123", "4567");
    printf("ma fct 10.* 71 s null: ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

	int *p = 18;
	ret1 = ft_printf("hello %p\n", &p);
    ret2 = printf("hello %p\n", &p);
    printf("ma fct p null: ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

	ret1 = ft_printf("hello %0-.21p\n", &p);
    ret2 = printf("hello %0-.21p\n", &p);
    printf("ma fct 0-.21 p null: ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

int max = 2147483647;
	ret1 = ft_printf("%0*.*i\n", 21, 10, -101);
    ret2 = printf("%0*.*i\n", 21, 10, -101);
    printf("ma fct 0*.0i -21 max : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

*/
    ret1 = ft_printf("%-4.*i \n", -4, 0);
    ret2 = printf("%-4.*i \n", -4, 0);
    printf("ma fct -4.*i -4 ret1 %i vraie fct : ret2 %i\n", ret1, ret2);

/*
    ret1 = ft_printf("%-3.i\n", -120);
    ret2 = printf("%-3.i\n", -120);
    printf("ma fct -3.i, 135 : ret1 %i vraie fct : ret2 %i\n", ret1, ret2);
*/
	return (0);
}
