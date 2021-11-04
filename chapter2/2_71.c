#include <assert.h>
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum);

int main()
{
  int w = 0xf2345678;

  assert(xbyte(w, 0) == 0x78);
  assert(xbyte(w, 1) == 0x56);
  assert(xbyte(w, 2) == 0x34);
  assert(xbyte(w, 3) == 0xfffffff2);
  return 1;
}

int xbyte(packed_t word, int bytenum)
{
  int size = sizeof(unsigned);
  int left = (size - 1 - bytenum) << 3;
  int right = bytenum << 3;

  return (int)(word << left) >> left >> right;
}