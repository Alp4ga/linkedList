#LINKED LIST

Linked list generique

Use case:

<pre><code>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(int ac, const char *av[])
{
	list_t *root = constructor; #Init linked List ! It's mandatory

	for (size_t i = 0; i < ac; i++) {
		push_back(&root, av[i]); #Add to the end of the list
	}

	for (size_t i = 0; i < size(list); i++) {
		char *str = get_position(root, i);
		printf("argument: %s\n", str);
	}

	destructor(root); #Clean your list
}
</code></pre>

##All Functions:

###Initialization
list_t *constructor();
void destructor(list_t *);

###Add
void push_front(list_t **, void *);
void push_back(list_t **, void *);
void push_position(list_t **, size_t, void *);

###Delete
void pop_front(list_t **);
void pop_back(list_t **);
void pop_position(list_t **, size_t);
void pop_ptr(list_t **, void *);

###Get
void *get_front(list_t *);
void *get_back(list_t *);
void *get_position(list_t *, size_t);

###Capacity
bool empty(list_t *);
size_t size(list_t *);

##use:

With gcc:
	gcc *.c -L{PATH_LIB_DIR} -llinked -I{PATH_INCLUDE_DIR}