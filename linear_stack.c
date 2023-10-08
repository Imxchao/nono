#include "linear_stack.h"

struct nono_stack
{
	element_t data[STACK_SIZE]; /* start with 0 */
	int top;
};

int main(int argc, char const *argv[])
{
	nono_stack_t sp;
	element_t elem;

	init_stack(&sp);

	while( (elem = getchar()) != '\n' ) {
		push_stack(elem, sp);
	}

	while (!empty_stack(sp)) {
		elem = pop_stack(sp);
		printf("%-3c", elem);
	}
	printf("\n");
	
	delet_stack(sp);
	return 0;
}


/**
 * @brief initialize
 * 
 * @param spp nono_stack_t *
 */
void init_stack(nono_stack_t *spp)
{
	*spp = NEW_STACK;

	test_null(*spp);
	(*spp)->top = -1;	/* set empty */
}

/**
 * @brief free sp
 * 
 * @param sp nono_stack_t
 */
void delet_stack(nono_stack_t sp)
{
	free(sp);
}

/**
 * @brief check stack is empty
 * 
 * @param sp 
 * @return int 
 */
int empty_stack(nono_stack_t sp)
{
	return sp->top == -1;
}

/**
 * @brief check stack is full
 * 
 * @param sp 
 * @return int 
 */
int full_stack(nono_stack_t sp)
{
	return sp->top == STACK_SIZE - 1;
}

/**
 * @brief push an element in to stack
 * 
 * @param elem 
 * @param sp 
 */
void push_stack(element_t elem, nono_stack_t sp)
{
	if (full_stack(sp)) {
		fprintf(stderr, "[error] full statck\n");
		exit(EXIT_FAILURE);
	}

	sp->data[++(sp->top)] = elem;
}

/**
 * @brief pop an element out of stack
 * 
 * @param sp 
 * @return element_t 
 */
element_t pop_stack(nono_stack_t sp)
{
	if (empty_stack(sp)) {
		fprintf(stderr, "[error] empty stack!\n");
		exit(EXIT_FAILURE);
	}

	return sp->data[sp->top--];
}

/**
 * @brief get element of top of stack
 * 
 * @param sp 
 * @return element_t 
 */
element_t top_stack(nono_stack_t sp)
{
	if (empty_stack(sp)) {
		fprintf(stderr, "[error] empty stack!\n");
		exit(EXIT_FAILURE);
	}

	return sp->data[sp->top];
}

