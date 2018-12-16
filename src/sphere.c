#include "sphere.h"
#include "vec3f.h"
#include <math.h>
#include <stdio.h>

// return 1 if hit
// return 0 if no hit
int sphere_hit(Sphere s, Vec3f o, Vec3f d, float* t) {
	// `d` is assumed to be a unit vector
	// for simplification in the formula

	Vec3f op = vec3f_sub(o, s.pos);

	float b = vec3f_dot(d, op);
	float c = vec3f_dot(op, op) - s.r*s.r;

	float di = b*b - c;

	if (di > 0) {
		*t = -b - sqrtf(di);

		return 1;
	} else {
		return 0;
	}
}