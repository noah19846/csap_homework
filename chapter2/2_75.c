int signed_high_prod(int x, int y)
{
  int w = sizeof(int) << 3;
  long xx = (long)x;
  long yy = (long)y;
  
  return (int)((xx * yy) >> w);
}

int unsigned_high_prod(unsigned x, unsigned y)
{
  int w = sizeof(int) << 3;
  int x_flag = ((int)x) >> (w - 1);
  int y_flag = ((int)y) >> (w - 1);
  
  return signed_high_prod(x, y) + (x_flag & y) + (y_flag & x);
}
