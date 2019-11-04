#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	int len_a, len_b;
	
	printf("Length of string a = ");
	scanf("%d", &len_a);
	getc(stdin);
	
	char* a = malloc(len_a * sizeof(char));
	
	printf("String a = ");
	scanf("%s", a);
	getc(stdin);
	
	printf("Length of string b = ");
	scanf("%d", &len_b);
	getc(stdin);
	
	char* b = malloc(len_b * sizeof(char));
	
	printf("String b = ");
	scanf("%s", b);
	getc(stdin);
	
	printf("1. a + b = %s\n", strcat(a, b));
	
	printf("3. Compare a to b: %d\n", strcmp(a, b));
	
	printf("5. Copy b to a: %s\n", strcpy(a, b));
	
	free(a);
	free(b);
	
	printf("Length of string a = ");
	scanf("%d", &len_a);
	getc(stdin);
	
	a = malloc(len_a * sizeof(char));
	
	printf("String a = ");
	scanf("%s", a);
	getc(stdin);
	
	printf("Length of string b = ");
	scanf("%d", &len_b);
	getc(stdin);
	
	b = malloc(len_b * sizeof(char));
	
	printf("String b = ");
	scanf("%s", b);
	getc(stdin);
	
	printf("Searching for elements of b in a\n");
	for (int i = 0; i < len_b; i++) {
		if (strchr(a, b[i]) != NULL) {
			printf("Element %c is in a\n", *strchr(a, b[i]));
		}
	}
	
	printf("Len of the part of a that doen't contain b: %d\n", strcspn(a, b));
	free(a);
	free(b);
	return 0;
}
