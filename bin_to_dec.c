#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int ft_power(int num, int exp)
{
    int res;

    if (exp == 0)
        return (1);
    res = num;
    while (exp > 1)
    {
        res *= num;
        exp--;
    }
    return (res);
}

int bin_to_dec()
{
    size_t  i;
    int num;
    int exp;
    char    s[8] = "10011001";

    i = 7;
    num = 0;
    exp = 0;
    while (i != -1)
    {
        num += (s[i] - '0') * ft_power(2, exp);
        /*printf("%d -- ", num);
        printf("%d\n", i);
        if (exp == 9)
            exit(EXIT_SUCCESS);*/
        exp++;
        i--;
    }
    return (num);
}

int main(int ac, char **av)
{
    printf("%d\n", bin_to_dec());
    return (0);
}
