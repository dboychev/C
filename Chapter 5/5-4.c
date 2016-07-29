#include <stdio.h>

int strend(char *s, char *t)
{
	int slen = strlen(s) - 1;
	int tlen = strlen(t) - 1;
	int *t_ = t;
	s = &s[slen];
	t = &t[tlen];

	for (; t + 1 != t_; t--, s--)
	{
		if (*t != *s)
		{
			return 0;
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