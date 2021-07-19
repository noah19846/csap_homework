#include <stdio.h>
#include <assert.h>

int any_odd_one(unsigned x)
{

    return !!(x & 0x55555555);
}

int main()
{
    unsigned x = 0x1, y = 0x2, z = 1 << 31;
    assert(any_odd_one(x));
    assert(!any_odd_one(y));
    assert(any_odd_one(z));

    return 0;
}