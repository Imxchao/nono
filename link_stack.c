#define _GNU_SOURCE
#include "link_stack.h"

struct stack_t {
	element_t elem;
	stack_t next;
};

int main(int argc, char const *argv[])
{
	int decimal, based;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <decmial> <based>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	decimal = atoi(argv[1]);
	based = atoi(argv[2]);

	parse_uint(decimal, based);
	return 0;
}

int empty_stack(stack_t top)
{
	return top == NULL;
}

/**
 * @brief push operation return new top
 * 
 * @param elem element_t
 * @param top stack_t
 * @return stack_t 
 */
stack_t push_stack(element_t elem, stack_t top)
{
	stack_t new_top = (stack_t)malloc(sizeof(struct stack_t));
	test_null(new_top);

	new_top->elem = elem;
	new_top->next = top;

	top = new_top;

	return top;
}

/**
 * @brief pop operation return new top
 * 
 * @param elem element_t* set poped param
 * @param top stack_t
 * @return stack_t 
 */
stack_t pop_stack(element_t *elem, stack_t top)
{
	stack_t new_pop = NULL;
	if (empty_stack(top)) {
		return top;
	}

	*elem = top->elem;
	new_pop = top->next;
	free(top);
	top = new_pop;

	return top;
}

int round_bracket_match()
{
	int i;
	stack_t top;
	element_t elem;
	char *str = NULL; /* arithmetic expression */
	size_t nsize;
	ssize_t nmemb;

	nmemb = getline(&str, &nsize, stdin);

	FOREACH(nmemb) {
		if (str[i] == '(') {
			top = push_stack(str[i], top);
			continue;
		}

		if (str[i] == ')') {
			if (empty_stack(top)) {
				fprintf(stderr, "[Error] round bracket not"
					"match!\n");
				return 1;
			}
			top = pop_stack(&elem, top);
		}
	}

	if (top != NULL) {
		fprintf(stderr, "[Error] round bracket not match!\n");
		while (NULL != (top = pop_stack(&elem, top))) {};
	} else {
		printf("match!\n");
	}

	free(str);

	return 0;
}

int palindromo_check()
{
	/* radar, madam, civic, level */
	int i;
	element_t *word = NULL;
	size_t wordsize;
	ssize_t wordlength;

	stack_t top;
	element_t elem;
	int check_length = 0;

	wordlength = getline(&word, &wordsize, stdin);
	if (wordlength - 1 < 2) {
		fprintf(stderr, "NOT palindromo!\n");
		free(word);
		return 1;
	}

	wordlength--;
	FOREACH(wordlength) {
		top = push_stack(word[i], top);
	}

	FOREACH(wordlength) {
		top = pop_stack(&elem, top);
		if (elem != word[i]) {
			break;
		}
		check_length++;
	}

	if (check_length == wordlength) {
		printf("PALINDROMO\n");
	} else {
		fprintf(stderr, "NOT palindromo!\n");
	}
	free(word);

	return 0;
}


int palindromo_check_2()
{
	element_t *str = NULL;
	element_t elem;
	stack_t top;
	size_t size;
	ssize_t length;
	ssize_t prev_length;
	ssize_t left_start;
	int i;

	length = getline(&str, &size, stdin);

	printf("[%ld] %s", length, str);

	length = length - 1;
	prev_length = length / 2;
	FOREACH(prev_length) {
		top = push_stack(str[i], top);
	}

	left_start = (length + 1) / 2;
	for (i = left_start; i < length; i++) {
		top = pop_stack(&elem, top);
		if (str[i] != elem) {
			fprintf(stderr, "NOT parlindromo\n");
			free(str);
			return 1;
		}
	}
	printf("PARLINDROMO\n");
	free(str);
	return 0;
}

void parse_uint(int decimal, int based)
{
	stack_t top = NULL;
	element_t elem;
	
	do {
		top = push_stack(hexmap(decimal % based), top);
	} while ((decimal /= based) != 0);

	while(top) {
		top = pop_stack(&elem, top);
		printf("%c", elem);
	}
	printf("\n");
}

