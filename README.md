#linkedList

Linked list generique

Use case:
#######START#######

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
########END########

#######START#######
All Functions:

#Initialization
list_t *constructor(); #Init list ! Mandatory !!!
void destructor(list_t *); #Clean the list

#Add
void push_front(list_t **, void *); #Add at the begenning
void push_back(list_t **, void *); #Add at the end
void push_position(list_t **, size_t, void *); #Add at the position (1 is the first element)

#Delete
void pop_front(list_t **); #Remove first element
void pop_back(list_t **); #Remove last element
void pop_position(list_t **, size_t); #Remove element at postion (1 is the first element)
void pop_ptr(list_t **, void *); #Remove element if the void *ptr is in the list

#Get
void *get_front(list_t *); #Get the first element
void *get_back(list_t *); #Get the last element
void *get_position(list_t *, size_t); #Get element at position (1 is the first element)

#Capacity
bool empty(list_t *); #If list is empty return true
size_t size(list_t *); #Return number element in the list
########END########

#######START#######
use:

With gcc:
	gcc *.c -L{PATH_LIB_DIR} -llinked -I{PATH_INCLUDE_DIR}
########END########