#include <assert.h>

int divide_power2(int x, int k)
{
  int w = sizeof(int) >> 3;
  int sign = !!(x >> (w - 1));

  return (x + (sign << k) - sign) >> k;
}

int main()
{
  assert(divide_power2(-13, 2) == -13 / 4);
  assert(divide_power2(0, 2) == 0 / 4);
  assert(divide_power2(-0x1234fd3, 6) == -0x1234fd3 / 64);
  assert(divide_power2(13, 2) == 13 / 4);
  assert(divide_power2(-16, 4) == -16 / 16);
  assert(divide_power2(-15, 4) == -15 / 16);
  return 1;
}
