/*
** Alp4ga
*/

#pragma once
#include <stdbool.h>

typedef struct list_s {
	void *data;
	struct list_s *next;
	struct list_s *previous;
} list_t;

/* Initialization */
list_t *constructor();
void destructor(list_t *);

/* Add */
void push_front(list_t **, void *);
void push_back(list_t **, void *);
void push_position(list_t **, size_t, void *);

/* Delete */
void pop_front(list_t **);
void pop_back(list_t **);
void pop_position(list_t **, size_t);
void pop_ptr(list_t **, void *);

/* Get */
void *get_front(list_t *);
void *get_back(list_t *);
void *get_position(list_t *, size_t);

/* Capacity */
bool empty(list_t *);
size_t size(list_t *);