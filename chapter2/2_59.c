#include <stdio.h>


int get_mix(int x, int y)
{
    int low = x & 0xff;
    int rest = y & (~0xff);

    return low + rest;
}

int main()
{
    printf("%x\n", get_mix(0x89abcdef, 0x76543210));

    return 0;
}