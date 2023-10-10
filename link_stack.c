#define _GNU_SOURCE
#include "link_stack.h"

struct stack_t {
	element_t elem;
	stack_t next;
};

int main(int argc, char const *argv[])
{
	round_bracket_match();
				
	return 0;
}

int empty_stack(stack_t top)
{
	return top == NULL;
}

/**
 * @brief push operation return new top
 * 
 * @param elem element_t
 * @param top stack_t
 * @return stack_t 
 */
stack_t push_stack(element_t elem, stack_t top)
{
	stack_t new_top = (stack_t)malloc(sizeof(struct stack_t));
	test_null(new_top);

	new_top->elem = elem;
	new_top->next = top;

	top = new_top;

	return top;
}

/**
 * @brief pop operation return new top
 * 
 * @param elem element_t* set poped param
 * @param top stack_t
 * @return stack_t 
 */
stack_t pop_stack(element_t *elem, stack_t top)
{
	stack_t new_pop = NULL;
	if (empty_stack(top)) {
		return top;
	}

	*elem = top->elem;
	new_pop = top->next;
	free(top);
	top = new_pop;

	return top;
}

int round_bracket_match()
{
	int i;
	stack_t top;
	element_t elem;
	char *str = NULL; /* arithmetic expression */
	size_t nsize;
	ssize_t nmemb;

	nmemb = getline(&str, &nsize, stdin);

	FOREACH(nmemb) {
		if (str[i] == '(') {
			top = push_stack(str[i], top);
			continue;
		}

		if (str[i] == ')') {
			if (empty_stack(top)) {
				fprintf(stderr, "[Error] round bracket not match!\n");
				return 1;
			}
			top = pop_stack(&elem, top);
		}
	}

	if (top != NULL) {
		fprintf(stderr, "[Error] round bracket not match!\n");
		while (NULL != (top = pop_stack(&elem, top))) {}; /* pop all */
	} else {
		printf("match!\n");
	}

	free(str);

	return 0;
}
