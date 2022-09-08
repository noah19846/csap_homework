#include <assert.h>

int get_k_0(int k)
{
  return k == 0 ? -1 : -1 - ((2 << (k - 1)) - 1);
}

int get_j_0_k_1(int k, int j)
{
  return get_k_0(j) ^ get_k_0(k + j);
}

int main()
{
  assert(-1 == get_k_0(0));
  assert(0xfffffffe == get_k_0(1));
  assert(0xfffffffc == get_k_0(2));
  assert(0xfffffff8 == get_k_0(3));
  assert(0xfffffff0 == get_k_0(4));
  assert(0xfffff000 == get_k_0(12));
  assert(0xffff0000 == get_k_0(16));
  assert(0xc0000000 == get_k_0(30));
  assert(0x80000000 == get_k_0(31));
  assert(0 == get_k_0(32));

  assert(0 == get_j_0_k_1(0, 31));
  assert(0x40000000 == get_j_0_k_1(1, 30));
  assert(0x80000000 == get_j_0_k_1(1, 31));
  assert(0x1f000 == get_j_0_k_1(5, 12));
  assert(0xfff000 == get_j_0_k_1(12, 12));
  assert(0x1fffc000 == get_j_0_k_1(15, 14));
  assert(0xffff0000 == get_j_0_k_1(16, 16));
  assert(-1 == get_j_0_k_1(32, 0));

  return 1;
}
