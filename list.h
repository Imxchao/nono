#ifndef __LIST_H
#define __LIST_H

#include "global.h"

struct node;
typedef int element_t;

#define NEW_NODE malloc(sizeof(struct node))
#define EMPTY(p) (p)->next == NULL
#define NOT_FOUND(p) (p) == NULL
#define NOT_NULL(p) (p) != NULL

#define ITER_NODE(p) \
	for ((p) = (p)->next; (p); (p) = (p)->next)

#define NEXT(p) (p)->next
#define PREV(p) (p)->prev

typedef struct node * list_t;
typedef struct node * position_t;

void creat_list(list_t *l);
void delet_list(list_t l);
void show_list(list_t l);
int list_size(list_t l);

/**
 * @brief locate which node has element x
 * 
 * @param x element
 * @param l list 
 * @return position_t 
 */
position_t locate_node(element_t x, list_t l);

/**
 * @brief insert new node with element x
 * 
 * @param x element
 * @param l list
 * @param p position
 */
void insert_node(element_t x, list_t l, position_t p);

/**
 * @brief insert new node with element x after the lastest node of list l
 * 
 * @param x - element
 * @param l - list
 */
void insert_after(element_t x, list_t l);

/**
 * @brief insert new node with element x before the frontest node of list l
 * 
 * @param x 
 * @param l 
 */
void insert_before(element_t x, list_t l);

/**
 * @brief insert node by index, index start from 1
 * 
 * @param x element
 * @param l list
 * @param i index
 */
void insert_byindex(element_t x, list_t l, int i);

/**
 * @brief find node before element x, if has more return first occur
 * 
 * @param x element
 * @param l list
 * @return position_t 
 */
position_t find_previous(element_t x, list_t l);

/**
 * @brief delete node after position p, and return element deleted
 * 
 * @param p position
 * @param l list 
 * @param elem return element
 */
void delet_after(position_t p, list_t l, element_t *elem);

/**
 * @brief delete node before position p, and return element deleted
 * 
 * @param p position
 * @param l list
 * @param elem return element
 */
void delet_before(position_t p, list_t l, element_t *elem);

/**
 * @brief delete node by index, return element deleted, index start from 1
 * 
 * @param elem 
 * @param l 
 * @param i 
 */
void delet_byindex(element_t *elem, list_t l, int i);

/**
 * @brief la = la U lb, do not allow duplicated element
 * 
 * @param la set A
 * @param lb set B
 */
void universal_list(list_t la, list_t lb);

/**
 * @brief eliminate duplicate element from la
 *
 * @param la list
 */
void eliminate_duplicate(list_t la);

/**
 * @brief find node by index, index start from 1.
 * return NULL, if not found
 * 
 * @param la list
 * @param index 
 * @return position_t
 */
position_t find_byindex(list_t la, int index);

/**
 * @brief inverse element in the list l
 * 
 * @param l list
 */
void inverse_element(list_t l);

/**
 * @brief split list by odd-even index, odd index for la, 
 * even index for lb.
 * 
 * @param la list 
 * @param lb list
 */
void split_odd_even_index(list_t la, list_t lb);

/**
 * @brief merge two ordered list, MUST free after invoked
 * 
 * @param la 
 * @param lb 
 * @return list_t 
 */
list_t merge_list_keep_order(list_t la, list_t lb);

/**
 * @brief delet_node for double-link list
 * 
 * @param p position
 * @param l list
 * @param elem element
 */
void delet_node(position_t p, list_t l, element_t *elem);

/**
 * @brief insert element and keep proper order for cycle list
 * 
 * @param elem element_t
 * @param la list_t
 */
void insert_keep_order_desc(element_t elem, list_t la);

/**
 * @brief transfer double link list to cycle double link list
 * 
 * @param la list_t
 */
void trans_dblist_2_cycle_dblist(list_t la);

/**
 * @brief show cycle double link list from left to right
 * 
 * @param la list_t
 */
void show_cycle_dblist_l2r(list_t la);

/**
 * @brief show cycle double link list from right to left
 * 
 * @param la list_t
 */
void show_cycle_dblist_r2l(list_t la);

/**
 * @brief delete cycle double link list from left to right
 * 
 * @param la list_t
 */
void delet_cycle_dblist(list_t la);

#endif /* __LIST_H */

