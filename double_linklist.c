#include "list.h"

struct node {
	element_t elem;
	struct node *prev;
	struct node *next;
};

int main(int argc, char const *argv[])
{
	printf("hello double linklist\n");
	return 0;
}
