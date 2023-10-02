#include "single_linklist.h"

int *pdata = NULL;
int datalen;

int main(int argc, char const *argv[])
{
	int i;
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <datalength>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	datalen = atoi(argv[1]);
	pdata = calloc(datalen, sizeof(int));

	rand_data_1_100(pdata, datalen);

	FOREACH(datalen) {
		printf("%-4d", pdata[i]);
	}

	bubble_sort((void *)pdata, datalen, sizeof(int), compare_integer_desc);

	printf("\n");

	printf("---------------------- test function ----------------------\n");
	test_func();

	free(pdata);
	return 0;
}

void test_func()
{
	list_t la;
	int i;

	creat_list(&la);

	FOREACH(datalen) {
		insert_after(pdata[i], la);
	}

	show_list(la);
	
	delet_list(la);
}

void creat_list(list_t *l)
{
	(*l) = (list_t)NEW_NODE;
	test_null(*l);

	(*l)->next = NULL;
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

	after->next = new_node;
}

void insert_before(element_t x, list_t l)
{
	struct node *new_node = NULL;

	new_node = (struct node *)NEW_NODE;
	test_null(new_node);

	new_node->elem = x;
	new_node->next = l->next;
	l->next = new_node;
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

void insert_node(element_t x, list_t l, position_t p)
{
	struct node *new_node = (struct node*)NEW_NODE;
	test_null(new_node);

	new_node->elem = x;
	new_node->next = p->next;
	p->next = new_node;
}

void insert_byindex(element_t x, list_t l, int i)
{
	position_t p;
	int j = 1;

	if (i < 1) {
		fprintf(stderr, "error index: index start from 1, index %d less than 1\n", i);
		return;
	}

	p = l;
	while(NEXT(p) != NULL && j < i) {
		p = NEXT(p);
		j++;
	}

	if (j < i) {
		fprintf(stderr, "error index: index %d greater or equal than end index %d\n", i, j);
		return;
	}

	insert_node(x, l, p);
}

position_t find_previous(element_t x, list_t l)
{
	position_t p;

	p = l;
	while(NEXT(p) && NEXT(p)->elem != x) {
		p = NEXT(p);
	}

	return p;
}

void delet_after(position_t p, list_t l, element_t *elem)
{
	struct node *after;

	if (p == NULL || NEXT(p) == NULL) {
		fprintf(stderr, "error position: position not found\n");
		return;
	};

	after = p->next;
	p->next = after->next;
	*elem = after->elem;
	free(after);
}

void delet_before(position_t p, list_t l, element_t *elem)
{
	struct node *delete;
	struct node *before_delete;

	if (NEXT(l)->elem == p->elem) {
		fprintf(stderr, "error position: position not found\n");
		return;
	}

	before_delete = l;
	delete = l;
	
	ITER_NODE(delete) {
		if (NEXT(delete) && NEXT(delete)->elem == p->elem) {
			break;
		}
		before_delete = delete;
	}

	delet_after(before_delete, l, elem);
}

void delet_byindex(element_t *elem, list_t l, int i)
{
	struct node *before_delete;
	struct node *delete;
	int j = 1;

	if (i < 1) {
		fprintf(stderr, "error index: index start from 1, index %d less than 1\n", i);
		return;
	}

	before_delete = l;
	delete = l;

	ITER_NODE(delete) {
		if (j == i) {
			break;
		}
		before_delete = delete;
		j++;
	}

	delet_after(before_delete, l, elem);
}

void universal_list(list_t la, list_t lb)
{
	struct node *b_node = lb;

	ITER_NODE(b_node) {
		if (NOT_FOUND(locate_node(b_node->elem, la))) {
			insert_before(b_node->elem, la);
		}
	}
}

void eliminate_duplicate(list_t la)
{
	struct node *node_i = la;
	struct node *node_j;
	struct node *node_prev;
	int elem;

	ITER_NODE(node_i) {
		node_j = node_i;
		node_prev = node_i;
		ITER_NODE(node_j) {
			if (node_i->elem == node_j->elem) {
				delet_after(node_prev, la, &elem);
				printf("- remove duplicate element = %d\n", elem);
				node_j = node_prev;
			}
			node_prev = node_j;
		}
	}
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

position_t find_byindex(list_t la, int index)
{
	struct node *node = la;
	int i = 1;
	if (index < 1) {
		fprintf(stderr, "error index: less than 1\n");
		exit(EXIT_FAILURE);
	}

	ITER_NODE(node) {
		if (i == index) {
			break;
		}
		i++;
	}

	return node;
}

void inverse_element(list_t l)
{
	int size = list_size(l);
	int i = 1;
	int len = size / 2;
	struct node *n1, *n2;
	element_t elem;

	for (i = 1; i <= len; i++, size--) {
		n1 = find_byindex(l, i);
		n2 = find_byindex(l, size);
		if (!n1 || !n2) {
			continue;
		}
		if (n1->elem != n2->elem) {
			elem = n1->elem;
			n1->elem = n2->elem;
			n2->elem = elem;
		}
	}
}

void split_odd_even_index(list_t la, list_t lb)
{
	struct node *a_node;
	element_t elem;

	a_node = la;
	ITER_NODE(a_node) {
		delet_after(a_node, la, &elem);
		insert_after(elem, lb);
	}
}
