#include <stdio.h>

int any(char s1[], char s2[])
{
	int i = 0, j = 0;
	int num = -1;
	while (s1[i] != s2[j] && s1[i] != '\n')
	{
		if (s2[j + 1] == '\n')
		{
			j = 0;
			i++;
		}

		else
		{
			j++;
		}
	}

	if (s1[i] == s2[j])
	{
		num = i;
	}

	return num;
}

main()
{
	char s1[30], s2[30];
	char c;
	int len = 0;

	printf("Enter your string: ");
	while ((c = getchar()) != EOF)
	{
		s1[len] = c;
		len++;
	}
	s1[len] = '\0';

	len = 0;
	printf("Now enter the second string: ");
	while ((c = getchar()) != EOF)
	{
		s2[len] = c;
		len++;
	}
	s2[len] = '\0';

	printf("%d\n", any(s1, s2));
}