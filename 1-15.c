#include <stdio.h>

float conversion(float a);

main()
{
	float celsius, fahr;
	int upper, lower, step;
	upper = 300; 
	lower = 0;
	step = 20;

	fahr = lower;

	while (fahr <= upper)
	{
		printf("%3.0f %6.1f\n", fahr, conversion(fahr));
		fahr += step;
	}
}

float conversion(float fahr)
{
	return 5 * (fahr - 32.0) / 9;
}
