#ifndef __LINK_STACK_H
#define __LINK_STACK_H

#include "global.h"

typedef char element_t;

struct stack_t;
typedef struct stack_t * stack_t;

int empty_stack(stack_t top);

stack_t push_stack(element_t elem, stack_t top);
stack_t pop_stack(element_t *elem, stack_t top);

/**
 * @brief match round bracket pair ()
 * 
 * @return int 
 */
int round_bracket_match();

/**
 * @brief characters run back again like "radar", "madam", "civic"
 * 
 * @return int 
 */
int palindromo_check();

#endif /* __LINK_STACK_H */

