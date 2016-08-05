#include <stdio.h>

struct word
{
	char word[100];
	int count;
};

struct word* words[1];

void separate(char* text, struct word* words)
{
	int i = 0;
	int j = 0;
	int l = 0;
	int m = 0;

	char wordtmp[100];

	while (*(text + i) != '\0')
	{
		j = 0;

		while ((*(text + i) >= 'a' && *(text + i) <= 'z') || (*(text + i) >= 'A' && *(text + i) <= 'Z'))
		{
			*(wordtmp + j) = *(text + i);
			*(wordtmp + j + 1) = '\0';
			i++;
			j++;
		}

		m = 0;
 		
 			while (strcmp(words[m].word, wordtmp) != 0 && m < l)
			{
				m++;
			}

  			if (strcmp(words[m].word, wordtmp) == 0)
			{
				words[m].count++;
				i++;
			}

		else
		{
			words[l].count = 1;
			strcpy_s(words[l].word, j + 1, wordtmp);
			i++;
			l++;
		}
	}
}

void enterText(char* text)
{
	printf("Enter your text: ");
	char c;
	int i = 0;
	while ((c = getchar()) != EOF)
	{
		*(text + i) = c;
		i++;
	}
	*(text + i)  = '\0';
}

void sortWords(struct word* words)
{
	int size = 0;
	while (words[size].count > 0)
	{
		size++;
	}

	struct word temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (words[i].count < words[j].count)
			{
				temp = words[i];
				words[i] = words[j];
				words[j] = temp;
			}
		}
	}

	int i = 0;
	while (words[i].count > 0)
	{
		printf("%d - %s\n", words[i].count, words[i].word);
		i++;
	}
}

main()
{
	char text[200];

	enterText(text);
	separate(text, words);
	sortWords(words);
}