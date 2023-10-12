#include "global.h"

uint64_t nono_rdtsc(void)
{
	uint32_t lo_32;
	uint32_t hi_32;

	__asm__ __volatile__ ("rdtsc":"=a"(lo_32),"=b"(hi_32));

	return (lo_32 | (uint64_t)hi_32 << 32);
}

int rand_range(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void test_null(void *arg)
{
	if (arg == NULL) {
		fprintf(stderr, "Out of space!\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief 生成[1, 100]的随机数
 * 
 * @param pdata 
 * @param datalen 
 */
void rand_data_1_100(int *pdata, int datalen)
{
	int i;
	srand(nono_rdtsc());

	FOREACH(datalen) {
		pdata[i] = rand_range(1, 100);
	}
}

void bubble_sort(void *base, int nmemb, int msize, 
	int (*compare)(const void *p1, const void *p2))
{
	int sorted = 1;
	int i;
	char *ptmp = (char *)malloc(msize);
	char *data = NULL;

	do {
		sorted = 1;
		nmemb--;
		data = (char *)base;
		for (i = 0; i < nmemb; i++) {
			if (compare(data, data + msize)) {
				sorted = 0;
				memcpy(ptmp, data, msize);
				memcpy(data, data + msize, msize);
				memcpy(data + msize, ptmp, msize);
			}
			data += msize;
		}
	} while(!sorted);
}

int compare_integer_desc(const void *p1, const void *p2)
{
	return *(int *)p1 - *(int *)p2 < 0;	
}

int compare_integer_asc(const void *p1, const void *p2)
{
	return *(int *)p1 - *(int *)p2 > 0;
}

char hexmap(int hex)
{
	switch(hex) {
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	default: return (char)hex;
	}
}

