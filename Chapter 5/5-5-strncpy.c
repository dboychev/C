#include <stdio.h>

void strncpy(char *s1, char *s2, int len)
{
	int i = 0;

	while (i < len) 
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}

	*(s1 + i) = '\0'; //Clearing all the elements of 's1' after 'len' position

	while (*s1 != '\0')
	{
		printf("%c", *s1);
		s1++;
	}

	printf("%\n");
}


main()
{
	char s1[] = "DATECS ltd";
	char s2[] = "Software";
	strncpy(s1, s2, 5);
}