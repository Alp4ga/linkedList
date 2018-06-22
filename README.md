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
<p>list_t *constructor();
<p>void destructor(list_t *);

<h3>Add</h3>
<p>void push_front(list_t **, void *);
<p>void push_back(list_t **, void *);
<p>void push_position(list_t **, size_t, void *);

<h3>Delete</h3>
<p>void pop_front(list_t **);</p>
<p>void pop_back(list_t **);</p>
<p>void pop_position(list_t **, size_t);</p>
<p>void pop_ptr(list_t **, void *);</p>

<h3>Get</h3>
<p>void *get_front(list_t *);</p>
<p>void *get_back(list_t *);</p>
<p>void *get_position(list_t *, size_t);</p>

<h3>Capacity</h3>
<p>bool empty(list_t *);</p>
<p>size_t size(list_t *);</p>

<h2>use:</h2>

<p>With gcc:</p>
	<p>gcc *.c -L{PATH_LIB_DIR} -llinked -I{PATH_INCLUDE_DIR}</p>