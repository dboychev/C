#include <stdio.h>

#define MAXLINE	100

void reverse(char s[])
{
	int i = 0;
	while (s[i] != ' ')
	{
		i++;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c", s[j]);
	}
	printf("\n");
}

main()
{
	char arr[MAXLINE];
	int count = 0;
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c != '\n' && c != ' ' && c != '\t')
		{
			arr[count] = c;
			count++;
		}

		else
		{
			arr[count] = ' ';
			reverse(arr);
			count = 0;
		}
	}
	return 0;
}