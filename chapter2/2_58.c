#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian()
{
    int x = 1;
    size_t len = sizeof(int);
    byte_pointer str = (byte_pointer)&x;

    return str[len - 1] == 0;
}

int main()
{
    printf("This machine is litter endian? (1 for yes, 0 for no)\n");
    printf("%d\n", is_little_endian());

    return 0;
}