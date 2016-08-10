#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

main()
{
	//Test 'Build123' and 'Push'
	struct node* p = BuildOneTwoThree();
	Push(&p, 0);

	//Test 'BuildWithSpecialCase' and 'Length'
	Length(BuildWithSpecialCase());
	
	//Test 'DestroyNodeV' and 'BuildWithDummyNode'
	DestroyNodeV(3, BuildWithDummyNode());


}