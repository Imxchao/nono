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

int palindromo_check_2();

/**
 * @brief parse unsigned int to the specific based number
 * 
 * @param decimal based on the number ten
 * @param based the specific number based on
 * @return
 */
void parse_uint(int decimal, int based);

uint64_t fac(uint64_t n);

uint64_t fib(uint64_t n);

float fu(int n);
#endif /* __LINK_STACK_H */

