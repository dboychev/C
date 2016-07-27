#include <stdio.h>

// x &= (x - 1) is equivalent to x = x & (x - 1)
// x = x & (x - 1) Operation (x - 1) makes the integer x smaller with 1
// its rightmost 1-bit turns to 0 and all the 0-bits that stay right to that 1-bit turn to 0
// In that case x's rightmost 1-bit has already turned to 0 (because of (x - 1))
// The operation a & b turn all the 1-bits in a at which positions in b are 0, to 0
// At the position of the rightmost 1-bit of x in (x - 1) definately is a 0-bit

int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x &= (x - 1))
	{
		b++;
	}
	return b;
}

main()
{
	int x = 6;

	printf("%d\n", bitcount(x));

	return 0;
}