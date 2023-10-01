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
