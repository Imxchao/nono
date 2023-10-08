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

