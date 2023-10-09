#include "link_stack.h"

struct nono_stack {
	element_t elem;
	struct nono_stack *next;
};

int main(int argc, char const *argv[])
{
	printf("hello, link stack!\n");

	return 0;
}


int empty_stack(nono_stack_t top)
{
	return top == NULL;
}

void delet_stack(nono_stact_t top)
{
	struct nono_stack *del;

	while(top) {

	}
}

