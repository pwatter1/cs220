#include <stdio.h>
	

struct Point {
	float x;
	float y;
	float z;
	struct Point *next;
};

int contains_loop(struct Point *y);
struct Point* transform_points(struct Point *points, struct Point *origin);
