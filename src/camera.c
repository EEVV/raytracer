#include "camera.h"

void camera_point(Camera* c, Vec3f local_z) {
	c->local_z = local_z;
	// normalize to prevent stretching of output
	c->local_z = vec3f_norm(local_z);

	c->local_x.x = c->local_z.z;
	c->local_x.y = 0;
	c->local_x.z = -c->local_z.x;
	c->local_x = vec3f_norm(c->local_x);

	c->local_y.x = 0;
	c->local_y.y = c->local_z.z;
	c->local_y.z = -c->local_z.y;
	c->local_y = vec3f_norm(c->local_y);
}


void camera_fov(Camera c, float f) {
	
}