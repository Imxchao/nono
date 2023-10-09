#include "link_stack.h"

struct stack_t {
	element_t elem;
	stack_t next;
};

int main(int argc, char const *argv[])
{
	element_t ch;
	stack_t top;

	while ( (ch = getchar()) != '\n' ) {
		top = push_stack(ch, top);
	}
	
	do
	{
		top = pop_stack(&ch, top);
		printf("%-3c", ch);
	} while (top != NULL);
	
	printf("\n");
				
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
		fprintf(stderr, "error: empty stack!\n");
		exit(EXIT_FAILURE);
	}

	*elem = top->elem;
	new_pop = top->next;
	free(top);
	top = new_pop;

	return top;
}
