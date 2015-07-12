/*
 * stack_test.c
 *
 *  Created on: Jul 12, 2015
 *      Author: domagoj
 */

#include <stdio.h>
#include "stack.h"

int main()
{
	stack_t *s;
	stack_init(&s);
	stack_print(s);

	stack_push(s, S_EMPTY);
	stack_print(s);

	stack_push(s, S_ELSE);
	stack_print(s);

	stack_pop(s);
	stack_print(s);

	stack_pop(s);
	stack_print(s);

	stack_pop(s);
	stack_print(s);

	stack_delete(&s);

	return 0;
}
