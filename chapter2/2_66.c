#include <assert.h>

int left_most_one(unsigned x);

int main()
{
    assert(left_most_one(0x80010101) == 0x80000000);
    assert(left_most_one(0x10010010) == 0x10000000);
    return 1;
}

int left_most_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    // | 0x80000000 的原因是 x 的最高位为 1 时，最终 ~x 会为 0
    return x & ((~x >> 1) | 0x80000000);
}