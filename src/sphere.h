#pragma once

#include "vec3f.h"


typedef struct {
	// center position
	Vec3f pos;

	// radius
	float r;
} Sphere;

int sphere_hit(Sphere s, Vec3f o, Vec3f d, float* t);