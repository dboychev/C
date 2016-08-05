#include <stdio.h>

#define MAXSIZE 100

struct word
{
	char word[MAXSIZE];
	int count;
};

struct word* words[1]; //Array of structs

void enterText(char* text);
void separate(char* text, struct word* words);
void sortWords(struct word* words);

void enterText(char* text)
{
	printf("Enter your text here: ");
	char c;
	int i = 0;
	while ((c = getchar()) != EOF) //Saving the input in an char array
	{
		*(text + i) = c;
		i++;
	}

	*(text + i)  = '\0';
	separate(text, words);
}

void separate(char* text, struct word* words)
{
	int i = 0; //Some additional variables
	int j = 0;
	int l = 0;
	int m = 0;

	char wordtmp[MAXSIZE]; //A temporary variable for saving each distinct word

	while (*(text + i) != '\0')
	{
		j = 0;

		while ((*(text + i) >= 'a' && *(text + i) <= 'z') || (*(text + i) >= 'A' && *(text + i) <= 'Z'))
		{
			*(wordtmp + j) = *(text + i); //Saving each word in 'wordtmp' symbol by symbol
			*(wordtmp + j + 1) = '\0';
			i++;
			j++;
		}

		m = 0;

		while (strcmp(words[m].word, wordtmp) != 0 && m < l)
		{
			m++;
		}

		if (strcmp(words[m].word, wordtmp) == 0) //Checking if the word is already in the list
		{
			words[m].count++;
			i++;
		}

		else //If not - save it on the first empty position
		{
			words[l].count = 1;
			strcpy_s(words[l].word, j + 1, wordtmp);
			i++;
			l++;
		}
	}

	sortWords(words);
}

void sortWords(struct word* words)
{
	int size = 0;
	while (words[size].count > 0) //Finding the number of all distinct words
	{
		size++;
	}

	struct word temp;

	for (int i = 0; i < size; i++) //Sorting all distinct words
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
		printf("%d - %s\n", words[i].count, words[i].word); //Printing all the words with the time of frequency of occurence
		i++;
	}
}

main()
{
	char text[MAXSIZE];
	enterText(text);
}