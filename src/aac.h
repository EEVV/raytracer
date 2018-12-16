#pragma once

#include "vec3f.h"

// axis-aligned cube
typedef struct {
	// center position
	Vec3f pos;

	// radius (to face)
	float r;
} AAC;

int aac_hit(AAC aac, Vec3f o, Vec3f d, float* t);