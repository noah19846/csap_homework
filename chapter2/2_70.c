#include <assert.h>

int fits_bits(int x, int n);

int main()
{
  assert(!fits_bits(1, 1));
  assert(fits_bits(1, 2));
  assert(fits_bits(-2, 2));
  assert(!fits_bits(-4, 2));
  return 1;
}

int fits_bits(int x, int n)
{
  int w = sizeof(int) << 3;
  int o = w - n;

  return (x << o >> o) == x;
}