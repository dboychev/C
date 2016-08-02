#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	if (year >= 0 && month < 13) //Checking if YEAR and MONTH values are correct
	{
		int i = 1, leap;

		leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

		if (day <= daytab[leap][month]) //Checking if DAY value is correct
		{
			for (i; i < month; i++)
			{
				day += daytab[leap][i];
			}
			return day;
		}

		else
		{
			printf("Incorrect input!!!\n");
			return 0;
		}
	}

	else
	{
		printf("Incorrect input!!!\n");
		return 0;
	}

}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (yearday <= 365 + leap) //Checking if YEARDAY is in the range [1 <-> 365] (366 for a leap year)
	{
		for (i = 1; yearday > daytab[leap][i]; i++)
		{
			yearday -= daytab[leap][i];
		}

		*pmonth = i;
		*pday = yearday;
	}

	else
	{
		printf("Incorrect input!!!\n");
	}
}

main()
{
	int *m, *d;
	day_of_year(1995, 2, 28);
	month_day(2015, 366, &m, &d);
}