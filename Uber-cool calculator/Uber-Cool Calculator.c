#include <stdio.h>

void call_menu();

//A function for setting and getting X
float get_x()
{
	float x = 0;
	printf("X = ");
	scanf("%fl", &x);
	return x;
}

//A function for setting and getting Y
float get_y()
{
	float y = 0;
	printf("Y = ");
	scanf("%fl", &y);
	return y;
}

void add()
{
	float result = get_x() + get_y();
	printf("%g\n\n", result);
}

void subtract()
{
	float result = get_x() - get_y();
	printf("%g\n\n", result);
}

void multiply()
{
	float result = get_x() * get_y();
	printf("%g\n\n", result);
}

void divide()
{
	float result = get_x() / get_y();
	printf("%g\n\n", result);
}

void power()
{
	float x = get_x();
	float y = get_y();

	float result = x;
	
	//Calculating X^Y
	while (y > 1) 
	{
		result *= x;
		y--;
	}

	//If Y = 0, X^Y = 1
	if (y == 0)
	{
		result = 1;
	}
	
	printf("%g\n\n", result);
}

void menu()
{
	//Printing the menu
	printf("1. add\n2. subtract\n3. multiply\n4. divide\n5. power\n\n");

	char c = getchar();
	switch (c)
	{
	case '1':
		add();
		break;
	case '2':
		subtract();
		break;
	case '3':
		multiply();
		break;
	case '4':
		divide();
		break;
	case '5':
		power();
		break;

		//If input is not between 1 nad 5
	default:
		printf("Invalid operation!\n\n");
		menu();
		break;
	}
	
	call_menu();
}

void call_menu()
{
	printf("Press any key to go back to the main menu...\n");
	_getch(); 
	scanf("%c"); //Ignoring the last ENTER used for submitting value of Y
	menu();
}

main()
{
	printf("Hello, this is an uber-cool calculator!\n\n");
	menu();
}