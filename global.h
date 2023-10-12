#ifndef _NONO_GLOBAL_H
#define _NONO_GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief specific length
 * 
 */
#define FOREACH(len) \
	for (i = 0; i < (len); i++)


uint64_t nono_rdtsc(void);
int rand_range(int min, int max);
void test_null(void *arg);
void test_func(int argc, char const **argv);

void rand_data_1_100(int *pdata, int datalen);

void bubble_sort(void *base, int nmemb, int msize, 
	int (*compare)(const void *p1, const void *p2));

int compare_integer_desc(const void *p1, const void *p2);
int compare_integer_asc(const void *p1, const void *p2);

char hexmap(int hex);

#endif	/* _NONO_UTILS_H */

