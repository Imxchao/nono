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
	element_t elem;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <datalength>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	datalen = atoi(argv[1]);
	pdata = calloc(datalen, sizeof(int));
	rand_data_1_100(pdata, datalen);

	bubble_sort(pdata, datalen, sizeof(int), compare_integer_desc);
	creat_list(&la);
	FOREACH(datalen) {
		insert_after(pdata[i], la);
	}

	printf("- show insert_before\n");
	show_list(la);

	printf("Insert data: ");
	scanf("%d", &elem);
	insert_keep_order_desc(elem, la);
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

	if (node == l) {
		printf("empty list\n");
	}
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

void insert_before(element_t x, list_t l)
{
	struct node *add;

	add = (struct node*)NEW_NODE;
	test_null(add);
	add->elem = x;
	NEXT(add) = NEXT(l);
	NEXT(l) = add;
}

void insert_keep_order_desc(element_t elem, list_t la)
{
	struct node *node;
	struct node *next = la;
	struct node *prev = la;

	node = (struct node *)NEW_NODE;
	node->elem = elem;

	ITER_NODE(next) {
		if (next->elem < node->elem) {
			break;
		}
		prev = next;
	}

	node->next = prev->next;
	prev->next = node;
}

