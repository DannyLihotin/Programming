// Первое задание:

#include <stdlib.h>
#include <iostream>

int first_main()
{
	int i = 69;
	int number = 72;
	i = 69 + 72;
	int arr[3] = { };
	int *iPointer = &i;
	number = *iPointer;
	*iPointer = 15;
	iPointer = &arr[0];
	iPointer = iPointer + 2;
	arr[0] = 5;
	*iPointer = 6;

	std::cout << iPointer << std::endl;

	return 0;
}