#ifndef __DOUBLE_LINK_LIST_H
#define __DOUBLE_LINK_LIST_H

#include "global.h"

struct node {
	element_t elem;
	struct node *prev;
	struct node *next;
};

#endif /* __DOUBLE_LINK_LIST_H */
