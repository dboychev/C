#include <stdio.h>

int strend(char *s, char *t)
{
	int slen = strlen(s) - 1; 
	int tlen = strlen(t) - 1;
	int *t_ = t; //Save the address of t[0]
	s = &s[slen]; //Change 's' and 't' to point to the last position of the arrays
	t = &t[tlen];

	for (; t + 1 != t_; t--, s--)
	{
		if (*t != *s)
		{
			return 0; //Checking there is a symbol from 't' missing in 's'
		}
	}

	return 1;
}


main()
{
	char s[] = "abcd efg hjkl";
	char t[] = "fg hjkl";

	printf("%d\n", strend(s, t));
}