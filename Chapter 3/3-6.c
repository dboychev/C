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

void itoa(int n, char s[], int width)
{
	int i; //A variable for saving the number of digits in the number
	if (n < 0)
	{
		n = -n; //Checking if the number is bigger or smaller than 0
	}

	int m = n; //m - an additional variable for saving the value of n
	i = 0;
	int bs = 0; //An additional variable - bs (blank_size)
	do
	{
		i++;
	} while ((n /= 10) > 0); //Finding the number of the digits
	
	if (width % (i - 1)) //Finding the blanks space needed to fill the width
	{
		width -= i;
	}
	
	int blank_size = width / (i - 1); //Finding how many blanks ' ' should be put between every two digits

	for (int j = 1; j <= i; j++)
	{
		int r; //An additional variable for printing the blanks
		do
		{
			s[j - 1] = m % 10 + '0';
			int l = j; 

			if (bs < i - 1) //Checking if all the blank have been saved
			{
				for (r = 0; r < blank_size; r++)
				{
					s[l++] = ' '; //Printing a blank
				}
				bs++;
			}
			j = l + 1;
		} while ((m /= 10) > 0);
	
		
	}
	i = 0;
	while (s[i] >= '0' && s[i] <= '9' || s[i] == ' ') //Finding the last digit in the number
	{
		i++;
	}
	s[i] = '\0';
	reverse(s);
}

main()
{
	int num = 41234;
	char array[50];
	itoa(num, array, 19);
}