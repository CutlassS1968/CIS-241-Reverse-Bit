#include <stdio.h>

unsigned reverseBits(unsigned x);
void printBinary(unsigned x);

int main() {
    unsigned out;
    unsigned in;

    printf("This program returns the value of an integer whose bits have been reversed in order.\n");
    printf("Please enter a non-negative integer: ");
    scanf("%u", &in);

    printf("\n%u has a binary representation of", in);
    printBinary(in);

    out = reverseBits(in);
    printf("\n\nreverseBits(%u) == %u\n", in, out);

    printf("\n%u has a binary representation of", out);
    printBinary(out);
    return 0;
}

unsigned reverseBits(unsigned x) {
    unsigned mask = 1;
    unsigned temp = 0;

    for (int i = 0; i <=15; i++) {
        temp <<= 1;
        temp |= (x & mask);
        x >>= 1;
    }
    return temp;
}

void printBinary(unsigned x) {
    int c = 0;
    for (unsigned i = 1 << 31; i > 0; i = i / 2) {
        if (c % 4 == 0) printf(" ");
        (x & i) ? printf("1") : printf("0");
        c++;
    }
}