#include <stdio.h>

void strncat(char *s1, char *s2, int len)
{
	int i = 0; //Counters
	int j = 0;

	while (i < len)
	{
		if (*(s1 + j) != '\0')
		{
			j++;
		}

		else
		{
			*(s1 + j) = *(s2 + i); //Add an element of 's2' to the end of 's1'
			i++;
			j++;
			*(s1 + j) = '\0'; //Clearing all the elements of 's1' after 'len' position
		}
	}

	while (*s1 != '\0')
	{
		printf("%c", *s1);
		s1++;
	}
}

main()
{
	char s1[30] = "Hello ";
	char s2[30] = "World";

	strncat(s1, s2, 4);
	printf("\n");

}