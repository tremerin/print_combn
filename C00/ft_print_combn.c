#include <unistd.h>

void print_array(int *num, int len)
{
    int index;
    char aux;

    index = 0;
    while (index < len)
    {
        aux = num[index] + '0';
        write(1, &aux, 1);
        index++;
    }
}

int are_equal(int *num, int *final_num, int len)
{
    int index;

    index = 0;
    while (index < len)
    {
        if (num[index] == final_num[index])
            index++;
        else
            return(0);
    }
    return(1);
}

void set_array(int *num, int *last_num, int digits)
{
    int index;

    index = 0;
    while (index < digits)
    {
        num[index] = index;
        last_num[index] = 10 - digits + index;
        index++;
    }
}

void count(int *num, int *final_num, int n)
{  
    if (num[n - 1] == final_num[n - 1])
    {
        count(num, final_num, n - 1);
        num[n - 1] = num[n - 2] + 1;
    }
    else   
        num[n - 1] = num[n - 1] + 1;  
}

void ft_print_combn(int n)
{
    int num[10];
    int final_num[10];

    set_array(num, final_num, n);
    while (!are_equal(num, final_num, n))
    {
        print_array(num, n);
        write(1, ", ", 2);
        count(num, final_num, n);
    }
    print_array(num, n);
}
