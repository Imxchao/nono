#ifndef _NONO_GLOBAL_H
#define _NONO_GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


struct node;
typedef int element_t;

#define NEW_NODE malloc(sizeof(struct node))
#define EMPTY(p) (p)->next == NULL
#define NOT_FOUND(p) (p) == NULL
#define NOT_NULL(p) (p) != NULL

/**
 * @brief specific length
 * 
 */
#define FOREACH(len) \
	for (i = 0; i < (len); i++)

#define ITER_NODE(p) \
	for ((p) = (p)->next; (p); (p) = (p)->next)

#define NEXT(p) (p)->next

uint64_t nono_rdtsc(void);
int rand_range(int min, int max);
void test_null(void *arg);
void test_func();

void rand_data_1_100(int *pdata, int datalen);

void bubble_sort(void *base, int nmemb, int msize, 
	int (*compare)(const void *p1, const void *p2));

int compare_integer_desc(const void *p1, const void *p2);
int compare_integer_asc(const void *p1, const void *p2);

#endif	/* _NONO_UTILS_H */
