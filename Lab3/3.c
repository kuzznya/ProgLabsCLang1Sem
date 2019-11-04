
#include <stdio.h>


int main()
{
	int a;
	printf("1. a = ");
	scanf("%o", &a);

	printf("2. a_dec = %d\n", a);

	printf("3. a_hex = %x\n", a);
	printf("   a_hex<<2 = %x\n", a << 2);

	printf("4. a_hex = %x\n", a);
	printf("   NOT a_hex = %x\n", ~a);

	int b;
	printf("5. b = ");
	scanf("%x", &b);
	printf("   b XOR a = %x\n", b ^ a);
	
	return 0;
}


