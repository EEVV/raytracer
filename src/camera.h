#pragma once

#include "vec3f.h"


typedef struct {
	Vec3f pos;

	// right of camera
	Vec3f local_x;
	// top of the camera
	// by default, with `.spin = 0` this axis
	// will be parallel with the global y axis
	Vec3f local_y;
	// front of camera (used for tracking)
	Vec3f local_z;

	// spin of the camera
	float spin;

	// tba
	float fov;
} Camera;

/*
	Set the camera view direction to
	align with `p`
*/
void camera_point(Camera* c, Vec3f p);

void camera_fov(Camera c, float f);