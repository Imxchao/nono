#ifndef __STACK_H
#define __STACK_H

#include "global.h"

#define STACK_SIZE 100
typedef char element_t;

struct nono_stack;
typedef struct nono_stack * nono_stack_t;

#define NEW_STACK malloc(sizeof(struct nono_stack))

#endif	/* __STACK_H */

