#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
	float x;
	float y;
};

struct LineSeg {
	struct Point p1;
	struct Point p2;
};

float len(struct LineSeg seg) {
	float pow1 = pow((seg.p2.x - seg.p1.x), 2);
	float pow2 = pow((seg.p2.y - seg.p1.y), 2);
	return(sqrt(pow1 + pow2));
}

struct PlayerState {
	unsigned play: 1;
	unsigned pause: 1;
	unsigned rec: 1;
};

int main(int argc, char *argv[]) {
	
	enum paints {emulsive, acrylic, latex, pva, silycon} currentPaint = acrylic;
	printf("1. The value of current paint = %d\n", currentPaint);
	
	struct LineSeg seg;
	
	float x1, y1, x2, y2;
	printf("x1 = ");
	scanf("%f", &x1);
	getc(stdin);
	printf("y1 = ");
	scanf("%f", &y1);
	getc(stdin);
	printf("x2 = ");
	scanf("%f", &x2);
	getc(stdin);
	printf("y2 = ");
	scanf("%f", &y2);
	getc(stdin);
	
	struct Point p1;
	p1.x = x1;
	p1.y = y1;
	struct Point p2;
	p2.x = x2;
	p2.y = y2;
	
	seg.p1 = p1;
	seg.p2 = p2;
	
	printf("2. The length of this line segment is %f\n", len(seg));
	
	struct PlayerState currentState;
	int enteredNum;
	
	printf("3. Enter player state (hex): ");
	scanf("%x", &enteredNum);
	getc(stdin);
	
	union hex2state {
		unsigned int num;
		struct PlayerState state;
	} h2s;
	h2s.num = enteredNum;
	
	currentState = h2s.state;
	
	printf("Current state: Play: %d, Pause: %d, Rec: %d\n", currentState.play, currentState.pause, currentState.rec);
	
	return 0;
}
