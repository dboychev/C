#include <stdio.h>

void squeeze(char s1[], char s2[])
{
	int len = strlen(s1);
	for (int i = 0; s1[i] != '\0'; i++)
	{
		for (int j = 0; s2[j] != '\0'; j++)
		if (s1[i] == s2[j])
		{
			s1[i] = ' ';
		}
	}

	int j = 0;
	for (int i = 0; s1[i] != '\0'; i++)
	{
		for (int j = i; s1[j] != '\0'; j++)
		{
			if (s1[i] == ' ')
			{
				if (s1[j] != ' ')
				{
					s1[i] = s1[j];
					s1[j] = ' ';
				}
			}
		}
	}

	printf("New string: ");
	for (int i = 0; s1[i] != '\0'; i++)
	{
		printf("%c", s1[i]);
	}
	printf("\n");
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

	squeeze(s1, s2);
}