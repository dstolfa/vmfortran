/*
 * stack.h
 *
 *  Created on: Jul 12, 2015
 *      Author: domagoj
 */

#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#include "type.h"

struct node;

struct stack
{
	struct node *top;
	struct node *bottom;
	int size;
};

typedef struct stack stack_t;

void stack_push(stack_t *s, state_t state);
void stack_pop(stack_t *s);
state_t stack_top(stack_t *s);
void stack_init(stack_t **s);
void stack_delete(stack_t **s);
state_t stack_first(stack_t *s);
void stack_print(stack_t *s);
int stack_size(stack_t *s);

#endif /* SRC_STACK_H_ */
