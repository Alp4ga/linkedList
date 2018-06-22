<h1>Linked list</h1>

<h2>Linked list generique</h2>

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

<h2>All Functions:</h2>

<h3>Initialization</h3>
list_t *constructor();
void destructor(list_t *);

<h3>Add</h3>
void push_front(list_t **, void *);
void push_back(list_t **, void *);
void push_position(list_t **, size_t, void *);

<h3>Delete</h3>
void pop_front(list_t **);
void pop_back(list_t **);
void pop_position(list_t **, size_t);
void pop_ptr(list_t **, void *);

<h3>Get</h3>
void *get_front(list_t *);
void *get_back(list_t *);
void *get_position(list_t *, size_t);

<h3>Capacity</h3>
bool empty(list_t *);
size_t size(list_t *);

<h2>use:</h2>

With gcc:
	gcc *.c -L{PATH_LIB_DIR} -llinked -I{PATH_INCLUDE_DIR}