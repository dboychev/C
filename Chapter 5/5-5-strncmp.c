#include <stdio.h>

int strncmp(char *s1, char *s2, int len)
{
	int i = 0;
	
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0' && i < len)
	{
		i++; //Checking if the elements on same position at 's1' and 's2' are the same
	}

	if (*(s1 + i) > *(s2 + i)) //If 's1' is bigger than 's2'
	{
		return 1;
	}

	if (*(s2 + i) > *(s1 + i)) //If 's2' is bigger than 's1'
	{
		return -1;
	}

	else //If they are equal
	{
		return 0;
	}
}

main()
{
	char s1[] = "ABCDE";
	char s2[] = "ABCDEFG";
	printf("%d\n", strncmp(s1, s2, 5));
}