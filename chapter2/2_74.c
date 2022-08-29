#include <assert.h>
#include <limits.h>

int t_add_ok(int x, int y)
{
  int w = sizeof(int) << 3;
  int result = x + y;
  int s1 = !(x >> (w - 1));
  int s2 = !(y >> (w - 1));
  int s3 = !(result >> (w - 1));     // 若溢出，0 正溢出 -> INT_MAX，1 负溢出 -> INT_MIN
  int o_flag = s1 == s2 && s1 != s3; // 1 溢出，0 不溢出

  return !o_flag;
}

int t_sub_ok(int x, int y)
{
  return (y != INT_MIN && t_add_ok(x, -y)) || (y == INT_MIN && !t_add_ok(x, y));
}

int main()
{
  assert(1 == t_sub_ok(-1, INT_MIN));
  assert(1 == t_sub_ok(0, INT_MIN + 1));
  assert(0 == t_sub_ok(1, INT_MIN + 1));
  assert(0 == t_sub_ok(0, INT_MIN));
  assert(0 == t_sub_ok(1, INT_MIN));
}
