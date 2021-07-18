#include <stdio.h>

int is_sa(int x)
{

    int result = !(~x) || !x || !((x & 0xff) - 0xff) || !(((x >> ((sizeof(int) - 1) << 3)) & 0xff) - 0xff);
    return result;
}

int main()
{
    printf("%d\n", is_sa(0x0));
    printf("%d\n", is_sa(-1));
    printf("%d\n", is_sa(0xff));
    printf("%d\n", is_sa(0xff000000));
    printf("%d\n", is_sa(0x8f000000));

    return 0;
}