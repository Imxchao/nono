#include "list.h"

struct node {
	element_t elem;
	struct node *prev;
	struct node *next;
};

int main(int argc, char const *argv[])
{
	list_t la;
	int *pdata = NULL;
	int datalen;
	int i;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <datalength>", argv[0]);
		exit(EXIT_FAILURE);
	}

	datalen = atoi(argv[1]);
	pdata = calloc(datalen, sizeof(int));
	rand_data_1_100(pdata, datalen);

	creat_list(&la);
	FOREACH(datalen) {
		insert_before(pdata[i], la);
	}
	show_list(la);		/* before transfer */

	trans_dblist_2_cycle_dblist(la);
	show_cycle_dblist_l2r(la);
	show_cycle_dblist_r2l(la);
	delet_cycle_dblist(la);	/* transfered */
	return 0;
}

void creat_list(list_t *l)
{
	(*l) = (list_t)NEW_NODE;
	test_null(*l);

	NEXT(*l) = NULL;
	PREV(*l) = NULL;
}

void delet_list(list_t l)
{
	struct node *next_node = NEXT(l);
	struct node *delet_node = NULL;

	while(next_node != NULL) {
		delet_node = next_node;
		next_node = NEXT(delet_node);
		free(delet_node);
	}

	free(l);
}

void show_list(list_t l)
{
	struct node *node = l;

	if (EMPTY(l)) {
		printf("Empty List\n");
		return;
	}

	ITER_NODE(node) {
		printf("%-4d", node->elem);
	}
	printf("\n");
}

int list_size(list_t l)
{
	int size = 0;
	struct node *node = l;
	ITER_NODE(node) {
		size++;
	}
	return size;
}

void insert_after(element_t x, list_t l)
{
	struct node *after = l;
	struct node *new_node = NULL;

	while(NEXT(after) != NULL) {
		after = NEXT(after);
	}

	new_node = (struct node *)NEW_NODE;
	test_null(new_node);

	new_node->elem = x;
	new_node->next = NULL;
	new_node->prev = after;

	after->next = new_node;
}

void insert_before(element_t x, list_t l)
{
	struct node *new_node = NULL;

	new_node = (struct node *)NEW_NODE;
	test_null(new_node);

	new_node->elem = x;
	new_node->next = l->next;
	if (l->next) {
		l->next->prev = new_node;
	}
	l->next = new_node;
	new_node->prev = l;
}

position_t locate_node(element_t x, list_t l)
{
	position_t p;

	p = l;
	ITER_NODE(p) {
		if (p->elem == x) {
			break;
		}
	}

	return p;
}

void delet_node(position_t p, list_t l, element_t *elem)
{
	if (p == NULL) {
		fprintf(stderr, "error position\n");
		exit(EXIT_FAILURE);
	}

	p->prev->next = p->next;

	if (p->next != NULL) {
		p->next->prev = p->prev;
	}

	*elem = p->elem;
	printf("%s %s element = %d\n", __TIME__, __func__, p->elem);
	free(p);
}

void delet_after(position_t p, list_t l, element_t *elem)
{
	struct node *del;
	if (p == NULL || NEXT(p) == NULL) {
		fprintf(stderr, "error position or not after node\n");
		exit(EXIT_FAILURE);
	}

	del = NEXT(p);
	NEXT(p) = NEXT(del);
	if (NEXT(del)) {
		PREV(NEXT(del)) = p;
	}

	*elem = del->elem;
	printf("%s %s after node(%d) element = %d\n",
	       __TIME__, __func__, p->elem, del->elem);
	free(del);
}

void delet_before(position_t p, list_t l, element_t *elem)
{
	struct node *del;

	if (p == NULL || PREV(p) == l) {
		fprintf(stderr, "error position or not before node\n");
		exit(EXIT_FAILURE);
	}

	del = PREV(p);
	NEXT(PREV(del)) = p;
	*elem = del->elem;
	printf("%s %s before node(%d) element = %d\n",
	       __TIME__, __func__, p->elem, del->elem);
	free(del);
}

void trans_dblist_2_cycle_dblist(list_t la)
{
	struct node *node = la;

	while(node->next != NULL) {
		node->next->prev = node;
		node = node->next;
	}

	node->next = la;
	la->prev = node;	/* end to end */
}

void show_cycle_dblist_l2r(list_t la)
{
	printf("%s %s - ", __TIME__, __func__);
	struct node *node = NEXT(la);

	while(node != la) {
		printf("%-4d", node->elem);
		node = NEXT(node);
	}
	printf("\n");
}

void show_cycle_dblist_r2l(list_t la)
{
	printf("%s %s - ", __TIME__, __func__);
	struct node *node = PREV(la);

	while(node != la) {
		printf("%-4d", node->elem);
		node = PREV(node);
	}
	printf("\n");
}

void delet_cycle_dblist(list_t la)
{
	struct node *node = NEXT(la);
	struct node *del;

	while(node != la) {
		del = node;
		node = NEXT(del);
		free(del);
	}

	free(la);
}

