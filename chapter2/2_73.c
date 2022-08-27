#include <stdio.h>
#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y)
{
  int w = sizeof(int) << 3;
  int result = x + y;
  int s1 = !(x >> (w - 1));
  int s2 = !(y >> (w - 1));
  int s3 = !(result >> (w - 1));     // 若溢出，0 正溢出 -> INT_MAX，1 负溢出 -> INT_MIN
  int o_flag = s1 == s2 && s1 != s3; // 1 溢出，0 不溢出
  int mask = (1 << (w - 1)) - !s3;

  return result & (mask | (o_flag - 1)) | (mask & (!o_flag - 1));
}

int main()
{
  assert(INT_MAX == saturating_add(INT_MAX, INT_MAX));
  assert(INT_MIN == saturating_add(INT_MIN, INT_MIN));
  assert(INT_MAX == saturating_add(INT_MAX, 1));
  assert(INT_MIN == saturating_add(INT_MIN, -2));
  assert(-1 == saturating_add(INT_MAX, INT_MIN));
  assert(14 == saturating_add(13, 1));

  return 0;
}
