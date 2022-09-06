#include <stdio.h>
#include <assert.h>

int divide_power2(int x, int k)
{
  int w = sizeof(int) >> 3;
  int sign = !!(x >> (w - 1));

  return (x + (sign << k) - sign) >> k;
}

int mul3div4(int x)
{
  return divide_power2((x + (x << 1)), 2);
}

int main()
{
  assert(mul3div4(0) == 0);
  assert(mul3div4(77) == 77 * 3 / 4);
  assert(mul3div4(78) == 78 * 3 / 4);
  assert(mul3div4(79) == 79 * 3 / 4);
  assert(mul3div4(80) == 80 * 3 / 4);
  assert(mul3div4(-77) == (-77) * 3 / 4);
  assert(mul3div4(-78) == (-78) * 3 / 4);
  assert(mul3div4(-79) == (-79) * 3 / 4);
  assert(mul3div4(-80) == (-80) * 3 / 4);
  assert(mul3div4(0x7fffffff) == 0x7fffffff * 3 / 4);
  assert(mul3div4(0x80000000) == (int)0x80000000 * 3 / 4);
  assert(mul3div4(1) == 1 * 3 / 4);
  assert(mul3div4(-1) == (-1) * 3 / 4);
  assert(mul3div4(-53) == (-53) * 3 / 4);
  assert(mul3div4(-56) == (-56) * 3 / 4);
  assert(mul3div4(0x77777777) == 0x77777777 * 3 / 4);

  return 1;
}
