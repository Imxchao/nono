#include "list.h"

struct node {
	element_t elem;
	struct node *next;
};

int main(int argc, char const *argv[])
{
	list_t la;
	int *pdata = NULL;
	int datalen;
	int i;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <datalength>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	datalen = atoi(argv[1]);
	pdata = calloc(datalen, sizeof(int));
	rand_data_1_100(pdata, datalen);

	creat_list(&la);
	FOREACH(datalen) {
		printf("%-4d", pdata[i]);
		insert_after(pdata[i], la);
	}
	printf("\n");

	printf("- show insert_after\n");

	show_list(la);
	delet_list(la);
	return 0;
}

void creat_list(list_t *l)
{
	(*l) = (struct node *)NEW_NODE;
	test_null(*l);

	NEXT(*l) = *l;
}

void delet_list(list_t l)
{
	struct node *node = NEXT(l);
	struct node *del;

	while (node != l) {
		del = node;
		node = NEXT(del);
		free(del);
	}

	free(l);
}

void show_list(list_t l)
{
	struct node *node = NEXT(l);

	while (node != l) {
		printf("%-4d", node->elem);
		node = NEXT(node);
	}
	printf("\n");
}

void insert_after(element_t x, list_t l)
{
	struct node *node = l;

	while (NEXT(node) != l) {
		node = NEXT(node);
	}

	struct node *add = NEW_NODE;
	test_null(add);

	add->elem = x;
	add->next = node->next;
	node->next = add;
}
