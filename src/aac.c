#include <math.h>

#include "aac.h"
#include "vec3f.h"


int AAC_hit(AAC aac, Vec3f o, Vec3f d, float* t) {
	float x0;
	float x1;
	if (d.x == 0) {
		x0 = -INFINITY;
		x1 = INFINITY;
	} else {
		x0 = (aac.pos.x - aac.r - o.x) / d.x;
		x1 = (aac.pos.x + aac.r - o.x) / d.x;
	}

	float y0;
	float y1;
	if (d.y == 0) {
		y0 = -INFINITY;
		y1 = INFINITY;
	} else {
		y0 = (aac.pos.y - aac.r - o.y) / d.y;
		y1 = (aac.pos.y + aac.r - o.y) / d.y;
	}

	float z0;
	float z1;
	if (d.z == 0) {
		z0 = -INFINITY;
		z1 = INFINITY;
	} else {
		z0 = (aac.pos.z - aac.r - o.z) / d.z;
		z1 = (aac.pos.z + aac.r - o.z) / d.z;
	}

	float min = fmaxf(fmaxf(fminf(x0, x1), fminf(y0, y1)), fminf(z0, z1));
	float max = fminf(fminf(fmaxf(x0, x1), fmaxf(y0, y1)), fmaxf(z0, z1));

	if (max < 0) {
		return 0;
	}

	if (min <= max) {
		*t = min;

		return 1;
	} else {
		return 0;
	}
}