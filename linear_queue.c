#include "linear_queue.h"

int main(int argc, char **argv)
{
	queue_t Q;
	char *buf = NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	buf = argv[1];

	init_queue(&Q);

	while(*buf != '\0') {
		enqueue(&Q, *buf++);
	}

	while (!queue_empty(&Q)) {
		printf("%c", dequeue(&Q));
	}
	printf("\n");
	return 0;
}

void init_queue(queue_t *Q)
{
	Q->rear = Q->front = 0;
}

int queue_empty(queue_t *Q)
{
	return Q->rear == Q->front;
}

int queue_full(queue_t *Q)
{
	return (Q->rear+ 1) % QSIZE == Q->front;
}

void enqueue(queue_t *Q, element_t X)
{
	if (queue_full(Q)) {
		fprintf(stderr, "FULL!\n");
		exit(EXIT_FAILURE);
	}

	Q->elem[Q->rear] = X;
	Q->rear = (Q->rear + 1) % QSIZE;
}

element_t getfront(queue_t *Q)
{
	if (queue_empty(Q)) {
		fprintf(stderr, "EMPTY!\n");
		exit(EXIT_FAILURE);
	}

	return Q->elem[Q->front];
}

element_t dequeue(queue_t *Q)
{
	element_t ret;
	
	if (queue_empty(Q)) {
		fprintf(stderr, "EMPTY!\n");
		exit(EXIT_FAILURE);
	}

	ret = Q->elem[Q->front];
	Q->front = (Q->front + 1) % QSIZE;
	
	return ret;
}



