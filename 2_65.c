#include <assert.h>

int odd_ones(unsigned x);

int main()
{
    assert(!odd_ones(0x10010101));
    assert(odd_ones(0x10010010));
    return 1;
}

int odd_ones(unsigned x)
{
    // 利用 xor 操作将偶数个 1 化为 0
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 0b1;
}