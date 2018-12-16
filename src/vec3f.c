#include "vec3f.h"
#include <math.h>


Vec3f vec3f_from(float x, float y, float z) {
	Vec3f v;
	v.x = x;
	v.y = y;
	v.z = z;

	return v;
}

Vec3f vec3f_add(Vec3f a, Vec3f b) {
	Vec3f r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;

	return r;
}
Vec3f vec3f_sub(Vec3f a, Vec3f b) {
	Vec3f r;
	r.x = a.x - b.x;
	r.y = a.y - b.y;
	r.z = a.z - b.z;

	return r;
}

Vec3f vec3f_mulf(Vec3f a, float b) {
	Vec3f r;
	r.x = a.x * b;
	r.y = a.y * b;
	r.z = a.z * b;

	return r;
}

Vec3f vec3f_divf(Vec3f a, float b) {
	Vec3f r;
	r.x = a.x / b;
	r.y = a.y / b;
	r.z = a.z / b;

	return r;
}

Vec3f vec3f_norm(Vec3f a) {
	return vec3f_divf(a, vec3f_len(a));
}

float vec3f_dot(Vec3f a, Vec3f b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

float vec3f_len(Vec3f a) {
	return sqrtf(vec3f_dot(a, a));
}