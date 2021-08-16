#include <assert.h>

unsigned lower_one_mask(unsigned x, int n);

int main()
{
    assert(lower_one_mask(0x12345678, 4) == 0x23456781);
    assert(lower_one_mask(0x12345678, 20) == 0x67812345);
    assert(lower_one_mask(0x12345678, 0) == 0x12345678);
    return 1;
}

unsigned lower_one_mask(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    unsigned left = x << n;
    unsigned right = (x >> (w - n - 1)) >> 1;


    return left + right;
}