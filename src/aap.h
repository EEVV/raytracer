#pragma once

#include "vec3f.h"


typedef struct {
	Vec3f pos;

	float r;
} AAP;

int aap_hit(AAP a, Vec3f o, Vec3f d, float* t);