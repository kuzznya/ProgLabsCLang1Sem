#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int t[4];
	int* a = t;
	for (int i = 0; i < 4; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
		getc(stdin);
	}
	
	for (int i = 0; i < 4; i++) {
		printf("a[%d] = %d\n", i, *(a + i));
	}
	
	int* b = (int*)malloc(4 * sizeof(int));
	for (int i = 0; i < 4; i++) {
		printf("b[%d] = ", i);
		scanf("%d", &b[i]);
		getc(stdin);
	}
	for (int i = 0; i < 4; i++) {
		printf("b[%d] = %d\n", i, b[i]);
	}
	free(b);
	getc(stdin);
	return 0;
}
