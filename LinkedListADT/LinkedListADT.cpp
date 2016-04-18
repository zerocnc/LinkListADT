// LinkedListADT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "UnsortedType.h"

int main()
{
	int x = 0;

	UnsortedType<int> myList;

	x = myList.LengthIs();

	printf("Length is: %d", x);

	myList.MakeEmpty();

	std::cin.get();

    return 0;
}

