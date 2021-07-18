#include <stdio.h>

unsigned replace_byte(unsigned x, int i, char b)
{
    int limit = (int)sizeof(unsigned);

    if (i > limit -1 || i < 0)
    {
        return x;
    }

    unsigned mask = i == 0 ? 0 : (1 << 8 * i) - 1;
    unsigned low = x & mask;
    unsigned target = b << 8 * i;
    unsigned high = x & (~mask) << 8;

    return high + target + low;
}

int main()
{
    printf("%x\n", replace_byte(0x89abcdef, 0, 0x12));
    printf("%x\n", replace_byte(0x89abcdef, 1, 0x12));
    printf("%x\n", replace_byte(0x89abcdef, 2, 0x12));
    printf("%x\n", replace_byte(0x89abcdef, 3, 0x12));
    printf("%x\n", replace_byte(0x89abcdef, 4, 0x12));
    printf("%x\n", replace_byte(0x89abcdef, -1, 0x12));

    return 0;
}