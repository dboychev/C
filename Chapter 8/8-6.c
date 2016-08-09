#include <stdio.h>
#include <ctype.h>

struct box
{
	int data;
	int num;
};

void *calloc(size_t n, size_t size)
{
	size_t total = n * size;
	int *p = malloc(total);

	if (p == 0)
	{
		printf("ERROR: Out of memory!\n");
		return NULL;
	}

	return memset(p, 0, total);
}

main()
{
	struct box first;
	first.data = 5;
	first.num = 1;
	calloc(1, sizeof(struct box));

}