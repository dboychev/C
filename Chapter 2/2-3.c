#include <stdio.h>

int htoi(char s[])
{
	unsigned int number = 0;
	int count = 0;
	while (s[count] != NULL)
	{
		count++;
	}

	for (int i = 0; i <= count; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			number = number * 16 + (s[i] - '0');
		}

		else
		{
			if (s[i] >= 'a' && s[i] <= 'f')
			{
				s[i] = 10 + (s[i] - 'a');
				number = number * 16 + s[i];
			}

			if (s[i] >= 'A' && s[i] <= 'F')
			{
				s[i] = 10 + (s[i] - 'A');
				number = number * 16 + s[i];
			}
		}
	}
	return number;
}


main()
{
	char num[10] = "2BB";
	printf("%d\n", htoi(num));
}