#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

int main(int argc, char *argv[]) {
	printf("int/word size %zu\n", sizeof(int));
	printf("pointer size %zu\n", sizeof(void *));
	printf("sizeof(Busy_Header) == %zu\n", sizeof(Busy_Header));
	printf("sizeof(Free_Header) == %zu\n", sizeof(Free_Header));
	printf("BUSY_BIT == %x\n", BUSY_BIT);
	printf("SIZEMASK == %x\n", SIZEMASK);

	printf("| n | n&0x7 | n+8| (n+8) & ~0x7 | (n&0x7)==0 ? n : (n+8) & ~0x7|\n");
	printf("|---|-------|----|--------------|----------------------------|\n");
	for (size_t n=0; n<=32; n++) {
		printf("| %zd | %zd | %zd | %zd | %zd |\n", n, n&0x7, n+8, (n+8) & ~0x7, (n&0x7)==0 ? n : (n+8) & ~0x7);
	}

	printf("| n | size with header | aligned to word boundary |\n");
	printf("|---|------------------|---------------|\n");
	for (size_t n=0; n<=32; n++) {
		printf("| %zd | %zd | %zd |\n", n, size_with_header(n), request2size(n));
	}
}
