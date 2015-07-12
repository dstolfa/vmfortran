/*
 * stack.c
 *
 *  Created on: Jul 12, 2015
 *      Author: domagoj
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

struct node
{
	state_t value;
	struct node *next;
};

typedef struct node node_t;

void stack_push(stack_t *s, state_t state)
{
	node_t *new = malloc(sizeof(node_t));
	new->next = s->top;
	new->value = state;
	s->top = new;
	if (s->bottom == NULL)
	{
		s->bottom = new;
	}
	s->size++;
}

void stack_pop(stack_t *s)
{
	if (s->top == NULL)
	{
		return;
	}
	node_t *n = s->top;
	s->top = n->next;
	if (s->bottom == n)
	{
		s->bottom = NULL;
	}
	free(n);
	s->size--;
}

void stack_init(stack_t **s)
{
	*s = malloc(sizeof(stack_t));
	(*s)->top = NULL;
	(*s)->bottom = NULL;
	(*s)->size = 0;
}

void stack_delete(stack_t **s)
{
	while ((*s)->bottom != NULL)
	{
		stack_pop(*s);
	}

	free(*s);
}

state_t stack_first(stack_t *s)
{
	return (s->bottom) ? s->bottom->value : S_EMPTY;
}

state_t stack_top(stack_t *s)
{
	return (s->top) ? s->top->value : S_EMPTY;
}

void stack_print(stack_t *s)
{
	node_t *tmp = s->top;
	while (tmp)
	{
		switch (tmp->value)
		{
		case S_IF:
			fprintf(stderr, "S_IF ");
			break;
		case S_ELSEIF:
			fprintf(stderr, "S_ELSEIF ");
			break;
		case S_ELSE:
			fprintf(stderr, "S_ELSE ");
			break;
		case S_EMPTY:
			fprintf(stderr, "S_EMPTY ");
			break;
		}
		tmp = tmp->next;
	}
	fprintf(stderr, "\n");
}

int stack_size(stack_t *s)
{
	return s->size;
}
