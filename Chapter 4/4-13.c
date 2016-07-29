#include <stdio.h>

void reverse(char s[]) //Function reverse from Chapter 1 - 1-19
{
	int i = 1;
	while (s[i] != '\0') //Counting till the last symbol of 's'
	{
		i++;
	}

	printf("%c", s[i - 1]); //Printing the last symbol of 's'
	if (i > 1)
	{
		s[i - 1] = '\0'; //Clearing the last symbol of 's' after printing it
		reverse(s); //Calling 'reverse' again
	}
}

void itoa(int n, char s[])
{
	int i = 0;

	if (n /= 10 > 0)
	{
		while (s[i] >= '0' && s[i] <= '9') //Checking if any digits were already saved in 's'
		{
			i++;
		}

		s[i] = abs(n) % 10 + '0'; //Saving a digit into 's'
		if (n < 0)
		{
			s[++i] = '-'; //Saving '-' on last position, if the number is < 0
		}
		s[i + 1] = '\0'; //Clearing all the unnecessary positions in 's'

		itoa(n / 10, s); //Calling 'itoa' again
	}

	else //If all the digits were saved - print
	{
		reverse(s);
	}
}

main()
{
	char arr[10];
	itoa(345345, arr);
	printf("\n");

}