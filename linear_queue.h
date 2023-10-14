#ifndef __NONO_LINEAR_QUEUE_H
#define __NONO_LINEAR_QUEUE_H

#include "global.h"


#define QSIZE 100

typedef char element_t;
typedef struct {
	element_t elem[QSIZE];
	int rear, front;
} queue_t;

void init_queue(queue_t *Q);
int queue_empty(queue_t *Q);
int queue_full(queue_t *Q);
void enqueue(queue_t *Q, element_t X);
element_t getfront(queue_t *Q);
element_t dequeue(queue_t *Q);

#endif	/* __NONO_LINEAR_QUEUQ_H */

