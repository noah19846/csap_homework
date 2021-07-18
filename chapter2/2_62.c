#include <stdio.h>

int int_shift_are_arithmatic()
{
    int n = 0;

    return !(n >> 1) && !~((~n) >> 1);
}

int main()
{
    printf("%d\n", int_shift_are_arithmatic());

    return 0;
}