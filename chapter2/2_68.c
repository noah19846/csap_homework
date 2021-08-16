#include <assert.h>

int lower_one_mask(int x);

int main()
{
    assert(lower_one_mask(1) == 0x1);
    assert(lower_one_mask(5) == 0x1f);
    assert(lower_one_mask(32) == 0xffffffff);
    return 1;
}

int lower_one_mask(int x)
{
    int r1 = 1 << (x - 1);
    int r2 = r1 << 1;

    return r2 - 1;
}