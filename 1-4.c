#include <stdio.h>

main()
{
	float celsius, fahr;
	int lower, upper, step;
	lower = -15;
	upper = 30;
	step = 3;
	celsius = lower;
	printf("Celsius to Fahrenheit\n");
	while (celsius <= upper)
	{
		fahr = celsius * 9 / 5 + 32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius += step;
	}
}