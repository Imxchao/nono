#ifndef __LINEAR_STACK_H
#define __LINEAR_STACK_H

#include "stack.h"

/**
 * @brief initialize
 * 
 * @param spp stack_t *
 */
void init_stack(nono_stack_t *spp);

/**
 * @brief free sp
 * 
 * @param sp stack_t
 */
void delet_stack(nono_stack_t sp);

/**
 * @brief check stack is empty
 * 
 * @param sp 
 * @return int 
 */
int empty_stack(nono_stack_t sp);

/**
 * @brief check stack is full
 * 
 * @param sp 
 * @return int 
 */
int full_stack(nono_stack_t sp);

/**
 * @brief push an element in to stack
 * 
 * @param elem 
 * @param sp 
 */
void push_stack(element_t elem, nono_stack_t sp);

/**
 * @brief pop an element out of stack
 * 
 * @param sp 
 * @return element_t 
 */
element_t pop_stack(nono_stack_t sp);

/**
 * @brief get element of top of stack
 * 
 * @param sp 
 * @return element_t 
 */
element_t top_stack(nono_stack_t sp);

#endif /* __LINEAR_STACK_H */
