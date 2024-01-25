/*
Author: ravargas.42t@gmail.com
convert_binary_to_decimal.c (c) 2024
Desc: program that converts binary to decimal
Created:  2024-01-25T16:38:49.375Z
*/

#ifndef convert_binary_to_decimal
# define convert_binary_to_decimal
#endif

#include <io.h>
#include <stdio.h>

int number_len(char *binary)
{
    int i;

    i = 0;
    if(!binary)
        return -1;
    while(binary[i])
        i++;
    return (i);
}

int power(int a, int n)
{
    int p;

    p = 1;
    if(!n)
        return (1);
    while(n > 0)
    {
        p = p * a;
        --n;
    }
    return (p);
}

int convert_to_dec(char *binary)
{
    int num;
    int i;
    int p;
    int c;
    int digit_converted;

    c = 0;
    num = 0;
    i = number_len(binary);
    printf("Length of binary number is: %d\n", i);
    //101 -> 1 * 2**2 + 0 + 1 = 5
    while(binary[c])
    {
                //1 or 0 to int
        p = power(2,--i);
        printf("2 to the power of %d = %d -> ", i, p);
        digit_converted = (binary[c] - '0') * p;
        num += digit_converted;
        printf("adding: %d\n", digit_converted);
        c++;
    }
    return (num);
}

int main(int argc, char **argv)
{
    char *binary;
    
    binary = argv[1];
    printf("%s converted to decimal is: %d", binary, convert_to_dec(binary));
    if(argc <= 1)
        return (-1);
    return (1);
}