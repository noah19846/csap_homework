#include <assert.h>

int divide_power2(int x, int k)
{
  int w = sizeof(int) >> 3;
  int sign = !!(x >> (w - 1));

  return (x + (sign << k) - sign) >> k;
}

int threefourths(int x)
{
  int w = sizeof(int) >> 3;
  int sign = !!(x >> (w - 1));
  int onefourth = divide_power2(x, 2);
  int rest = x - (onefourth << 2);
  int flag = rest != 0;

  return x - onefourth - ((flag ^ sign) - sign);
}

int main()
{
  assert(threefourths(0x7777777) == 3 * 0x7777777 / 4);
  assert(threefourths(0x77777777) == (long)0x77777777 * 3 / 4);
  assert(threefourths(0x80000000) == -(long int)0x80000000 * 3 / 4);
  assert(threefourths(15) == 3 * 15 / 4);
  assert(threefourths(-15) == 3 * (-15) / 4);
  assert(threefourths(0) == 0);
  assert(threefourths(-16) == (-16) / 4 * 3);
  assert(threefourths(-15) == 3 * (-15) / 4);
  assert(threefourths(-14) == 3 * (-14) / 4);
  assert(threefourths(-13) == 3 * (-13) / 4);
  assert(threefourths(16) == 3 * 16 / 4);
  assert(threefourths(15) == 3 * 15 / 4);
  assert(threefourths(14) == 3 * 14 / 4);
  assert(threefourths(13) == 3 * 13 / 4);

  return 1;
}
