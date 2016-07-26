#include <stdio.h>

main()
{
	char c;
	int  array[10];


	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		array[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c != '\n' && c != '\t' && c != ' ')
		{
			array[count]++;
		}
		else
		{
			count++;
		}
	}

	for (int i = 0; i < count; i++)
	{
		int j = 0;
		while (j < array[i])
		{
			printf("%c", '+');
			j++;
		}
		printf("\n");
	}
	printf("\n");
}