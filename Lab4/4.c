
#include <stdio.h>


int main() {
	int x;
	scanf("%d", &x);
	printf("is in (88-99): %d\n", (88 < x) && (x < 99));
	scanf("%d", &x);
	printf("bit #10 = %d", (x >> 10) % 2);
	int i;
	for ( i = 0; i < 10; i++) {
		x = x / 2;
	}
	printf("bit #10 = %d", x);
	return 0;
}
