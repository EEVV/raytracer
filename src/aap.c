#include <math.h>

#include "aap.h"


int aap_hit(AAP aap, Vec3f o, Vec3f d, float* t) {
	// intersection to "infinite plane"
	// the reason in doing so is because
	// less division required, since
	// the range verification step uses
	// multiplication
	float t0;
	if (d.y == 0) {
		t0 = 0;
	} else {
		t0 = (aap.pos.y - o.y) / d.y;
	}

	// intersection on a plane behind
	// is not possible
	if (t0 < 0) {
		return 0;
	}

	float x = o.x + t0*d.x;
	float z = o.z + t0*d.z;

	// the plane distance is too big
	// invalid range, no intersection
	if (fmaxf(fabsf(x), fabsf(z)) > aap.r) {
		return 0;
	}

	*t = t0;
	return 1;
}