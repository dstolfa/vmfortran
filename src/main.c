#include <stdio.h>
#include <string.h>

#include "stack.h"

typedef void (*action_t)(stack_t*);

void noop(stack_t *s)
{
	/**
	 * So much noop, LOL
	 */
}

void push_if(stack_t *s)
{
	stack_push(s, S_IF);
}

void replace_elseif(stack_t *s)
{
	stack_pop(s);
	stack_push(s, S_ELSEIF);
}

void replace_else(stack_t *s)
{
	stack_pop(s);
	stack_push(s, S_ELSE);
}

/* Dragons be here! */
char *mercedes(char *asterisk, char *search)
{
	if (asterisk == NULL) return search;

	return asterisk < search ? NULL : search;
}

line_t deduce_line_type(const char const *line)
{
	char *ast = strchr(line, '!');

	if (mercedes(ast, strstr(line, " ELSE IF")))
	{
		return L_ELSEIF;
	}
	else if (mercedes(ast, strstr(line, " ENDIF")))
	{
		return L_ENDIF;
	}
	else if (mercedes(ast, strstr(line, " END IF")))
	{
		return L_ENDIF;
	}
	else if (mercedes(ast, strstr(line, " IF")))
	{
		return L_IF;
	}
	else if (mercedes(ast, strstr(line, " ELSE")))
	{
		return L_ELSE;
	}

	return L_OTHER;
}

/**
 * table[ulaz][stack] -> akcija
 */
const action_t table[5][4] =
{
		[L_IF] = {
				[S_IF] = &push_if,
				[S_ELSEIF] = &push_if,
				[S_ELSE] = &push_if,
				[S_EMPTY] = &push_if
		},

		[L_ELSEIF] = {
				[S_IF] = &replace_elseif,
				[S_ELSEIF] = &noop,
				[S_ELSE] = &replace_else,
				[S_EMPTY] = &noop /* ERR */
		},

		[L_ELSE] = {
				[S_IF] = &replace_else,
				[S_ELSEIF] = &replace_else,
				[S_ELSE] = &noop, /* ERR */
				[S_EMPTY] = &noop /* ERR */
		},

		[L_ENDIF] = {
				[S_IF] = &stack_pop,
				[S_ELSEIF] = &stack_pop,
				[S_ELSE] = &stack_pop,
				[S_EMPTY] = &stack_pop
		},

		[L_OTHER] =	{
				[S_IF] = &noop,
				[S_ELSEIF] = &noop,
				[S_ELSE] = &noop,
				[S_EMPTY] = &noop
		}
};

action_t lookup(line_t current, state_t top)
{
	return table[current][top];
}

int main(int argc, char **argv)
{
	stack_t *s;
	line_t current_line_type;
	state_t stack_line_type;
	state_t stack_bottom;
	action_t next_action;

	stack_init(&s);
	char line[1024];



	while(fgets(line, 1024, stdin))
	{

		current_line_type = deduce_line_type(line);
		stack_line_type = stack_top(s);

		next_action = lookup(current_line_type, stack_line_type);
		next_action(s);


		if (current_line_type != L_OTHER)
		{
			stack_print(s);
		}


		stack_bottom = stack_first(s);
		if ((stack_bottom == S_IF || stack_bottom == S_EMPTY)
				&& !(stack_size(s) == 1 && current_line_type == L_IF)
				&& !(stack_size(s) == 0 && current_line_type == L_ENDIF))
		{
			fprintf(stdout, "%s", line);
		}
	}

	stack_delete(&s);
	return 0;
}
