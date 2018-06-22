/*
** Alp4ga
*/

/* Null value and EXIT_FAILURE */
#include <stdlib.h>

#include "linked_list.h"

/*
** Alloc root ptr and set data value
*/
list_t *constructor()
{
	list_t *root = malloc(sizeof(list_t));

	if (!root)
		exit(EXIT_FAILURE);
	root->next = root;
	root->previous = root;
	root->data = NULL;
	root->n_element = 0;
	return (root);
}

/*
** Destroy all ptr of the list
*/
void destructor(list_t *root)
{
	list_t *tmp = root->next;
	list_t *save;

	while (tmp != root) {
		save = tmp;
		tmp = tmp->next;
		free(save);
	}
	free(root);
}

/*
** Add element in front
*/
void push_front(list_t **root, void *data)
{
	list_t *new = malloc(sizeof(list_t));

	if (!new)
		exit(EXIT_FAILURE);
	new->data = data;
	new->next = (*root)->next;
	new->previous = *root;
	(*root)->next->previous = new;
	(*root)->next = new;
	++(*root)->n_element;
}

/*
** Add element in back
*/
void push_back(list_t **root, void *data)
{
	list_t *new = malloc(sizeof(list_t));

	if (!new)
		exit(EXIT_FAILURE);
	new->data = data;
	new->next = *root;
	new->previous = (*root)->previous;
	(*root)->previous->next = new;
	(*root)->previous = new;
	++(*root)->n_element;
}

/*
** Add element in position gives in parameters
** If position == 0 -> push_front default
** Position 1 is first element
** Position > nbr_element -> push_back default
*/
void push_position(list_t **root, size_t position, void *data)
{
	list_t *new;
	list_t *tmp = (*root)->next;

	if (position == 0) {
		push_front(root, data);
		return;
	}
	for (size_t i = 1; i < position && tmp != *root; ++i, tmp = tmp->next);
	if (tmp == *root) {
		push_back(root, data);
		return;
	}
	new = malloc(sizeof(list_t));
	if (!new)
		exit(EXIT_FAILURE);
	new->data = data;
	new->data = data;
	new->next = tmp;
	new->previous = tmp->previous;
	tmp->previous->next = new;
	tmp->previous = new;
	++(*root)->n_element;
}

/*
** Delete element in front
*/
void pop_front(list_t **root)
{
	list_t *save = (*root)->next;

	if (save == *root)
		return;
	(*root)->next = save->next;
	save->next->previous = *root;
	free(save);
	--(*root)->n_element;
}

/*
** Delete element in back
*/
void pop_back(list_t **root)
{
	list_t *save = (*root)->previous;

	if (save == *root)
		return;
	(*root)->previous = save->previous;
	save->previous->next = (*root);
	free(save);
	--(*root)->n_element;
}

/*
** Delete element in position gives in parameters
** If position == 0 -> pop_front default
** Position 1 is first element
** Position > nbr_element -> pop_back default
*/
void pop_position(list_t **root, size_t position)
{
	list_t *tmp = (*root)->next;

	if (tmp == *root)
		return;
	if (position == 0) {
		pop_front(root);
		return;
	}
	for (size_t i = 1; i < position && tmp != *root; ++i, tmp = tmp->next);
	if (tmp == *root) {
		pop_back(root);
		return;
	}
	tmp->previous->next = tmp->next;
	tmp->next->previous = tmp->previous;
	free(tmp);
	--(*root)->n_element;
}

/*
** Delete element witch void *data corresponding
*/
void pop_ptr(list_t **root, void *data)
{
	list_t *tmp = (*root)->next;

	if (tmp == *root)
		return;
	if (!data)
		return;
	while (tmp->data != data && tmp != *root)
		tmp = tmp->next;
	if (tmp == *root)
		return;
	tmp->previous->next = tmp->next;
	tmp->next->previous = tmp->previous;
	free(tmp);
	--(*root)->n_element;
}

/*
** Get first data
*/
void *get_front(list_t *root)
{
	return (root->next->data);
}

/*
** Get last data
*/
void *get_back(list_t *root)
{
	return (root->previous->data);
}

/*
** Get data in position gives in parameters
** If position == 0 -> get_front default
** Position 1 is first element
** Position > nbr_element -> get_back default
*/
void *get_position(list_t *root, size_t position)
{
	list_t *tmp = root->next;

	if (position == 0)
		return (get_front(root));
	for (size_t i = 1; i < position && tmp != root; tmp = tmp->next, i++);
	if (tmp == root)
		return (get_back);
	return (tmp->data);
}

/*
** Return true if list is empty return false if is not
*/
bool empty(list_t *root)
{
	return root->next == root ? true : false;

}

size_t size(list_t *root)
{
	return root->n_element;
}