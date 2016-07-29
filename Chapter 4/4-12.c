#include <stdio.h>

void reverse(char s[]) //Function reverse from Chapter 1 - 1-19
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}

	for (int j = i - 1; j >= 0; j--)
	{
		printf("%c", s[j]);
	}
	printf("\n");
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
		
		itoa(n / 10, s); //Call 'itoa' again
	}

	else //If all the digits were saved - print
	{
		reverse(s);
	}
}

main()
{
	int arr[10];
	itoa(-1231, arr);
	
}