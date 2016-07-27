#include <stdio.h>

void expand(char s1[], char s2[])
{
	int len = strlen(s1); 
	int symbols; //A variable for saving the number of symbols between, that have to saved
	int j = 0; 
	int r = 2; //A variable that helps to find the SYMBOLS
			   //It is 2 on the first '-' in s1 and 1 for each of the following
	for (int i = 0; i < len; i++)
	{
		if (s1[i] == '-' && i != 0)
		{
			if (s1[i - 2] == '-' && s1[i - 3] == '\0') //Checking if there are more than one symbols divided by '-'
			{
				r = 1;
			}
			
			if (s1[i - 1] <= s1[i + 1])
			{
				symbols = s1[i + 1] - s1[i - 1] + r;
			}

			else
			{
				symbols = s1[i - 1] - s1[i + 1] + r;
			}

			while (s2[j] != '\0') //Finds the first empty position at s2
			{
				j++;
			}

			int m = j; //An additional variable helping for the 'for' cycles
			if (s1[i - 1] != '-') //Checking if the char is a correct symbol for copying
			{
				if (s2[j - 1] != s1[i - 1]) //Checking if a symbol we have to save 
											//is the last symbol we already have saved
				{
					s2[j] = s1[i - 1];
					j++;
				}

				
				for (j; j - m < symbols - 1; j++) //Saving all the symbols in the range
				{
					if (s1[i - 1] <= s1[i + 1])
					{
						s2[j] = s2[j - 1] + 1;
					}
					if (s1[i - 1] > s1[i + 1])
					{
						s2[j] = s2[j - 1] - 1;
					}
				}
			}
		}
	}

	for (int i = 0; s2[i] != '\0'; i++) //Printing the new array s2
	{
		printf("%c", s2[i]);
	}
	printf("\n");
}


main()
{
	char s1[] = { "e-w0-9" };
	char s2[50];

	for (int i = 0; i < 50; i++) //Making s2 empty
	{
		s2[i] = '\0';
	}
	expand(s1, s2);
}