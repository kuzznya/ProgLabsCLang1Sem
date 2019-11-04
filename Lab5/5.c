#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int a[6] = {0, 3, 5, 7, 11, 13};
	for (int i = 0; i < 6; i++) {
		printf("%d\n", a[i]);
	}
	int m1[2][2] = {{1, 0},
				{1, 4}};
	int m2[2][2] = {{1, 2},
					{0, 1}};
	int res[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			res[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	printf("\n");
	printf("%d   %d\n", res[0][0], res[0][1]);
	printf("%d   %d\n", res[1][0], res[1][1]);
	return 0;
}
