#include <stdio.h>

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    // 当 K 等于 0 时， 1 << 32 还是 1
    int len_minus1 = (sizeof(int) << 3) - 1;
    int mask = ((1 << (len_minus1 - k) << 1) - 1);

    return xsra & mask;
}

int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    int len_minus1 = (sizeof(int) << 3) - 1;
    int sym = (x & (1 << len_minus1)) || 0;
    int syms = (sym << k) - sym;
    int mask = syms << (len_minus1 - k + 1);

    return xsrl | mask;
}

int main()
{
    printf("%.8x\n", srl(0xf2345678, 0));
    printf("%.8x\n", srl(0xf2345678, 4));
    printf("%.8x\n", srl(0xf2345678, 8));
    printf("%.8x\n", srl(0xf2345678, 12));
    printf("%.8x\n", srl(0xf2345678, 16));
    printf("%.8x\n", srl(0xf2345678, 31));

    printf("\n");
    printf("%.8x\n", sra(0xf2345678, 0));
    printf("%.8x\n", sra(0xf2345678, 4));
    printf("%.8x\n", sra(0xf2345678, 8));
    printf("%.8x\n", sra(0xf2345678, 12));
    printf("%.8x\n", sra(0xf2345678, 16));
    printf("%.8x\n", sra(0xf2345678, 31));

    printf("\n");
    printf("%.8x\n", sra(0x12345678, 0));
    printf("%.8x\n", sra(0x12345678, 4));
    printf("%.8x\n", sra(0x12345678, 8));
    printf("%.8x\n", sra(0x12345678, 12));
    printf("%.8x\n", sra(0x12345678, 16));
    printf("%.8x\n", sra(0x12345678, 31));

    return 0;
}