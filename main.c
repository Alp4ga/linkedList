#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

int main()
{
	list_t *list = constructor();

	printf("\nAdd\n");

/* 	int a = 10;
	push_back(&list, &a);
	int b = 9;
	push_back(&list, &b);
	int c = 8;
	push_position(&list, 4, &c);
	int d = 7;
	push_back(&list, &d);
	print(list);
 */
	printf("\nDelete\n");

	pop_front(&list);
	print(list);

	printf("\nGet\n");
	int *e = (int *)get_front(list);
	//printf("%d\n", *e);
	e = (int *)get_back(list);
	//printf("%d\n", *e);
	e = (int *)get_position(list, 1);
	//printf("%d\n", *e);

	destructor(list);
	return (EXIT_FAILURE);
}