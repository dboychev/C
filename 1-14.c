#include <stdio.h>

main()
{
	char c;
	char array[128];


	int count = 0;
	for (int i = 0; i < 128; i++)
	{
		array[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		count++;
		array[c]++;
	}

	//VERTICAL
	/*for (int i = 1; i < 128; i++)
	{
		if (array[i] != 0 && (i != 32 && i != 9 && i != 10))
		{
			printf("%3d\t", array[i]);
		}
	}
	printf("\n");
	for (int i = 1; i < 128; i++)
	{
		if (array[i] != 0 && (i != 32 && i != 9 && i != 10))
		{
			printf("%3c\t", i - 48 + '0');
		}
	}*/

	// HORIZONTAL HISTOGRAM
	for (int i = 1; i < 128; i++)
	{
		if (array[i] != 0 && (i != 32 && i != 9 && i != 10))
		{
			printf("%1c ", i - 48 + '0');
			for (int j = 0; j < array[i]; j++)
			{
				printf("%1c", '+');
			}
			printf("\n");
		}
	}
}