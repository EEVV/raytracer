#include <stdio.h>
#include <stdint.h>

#include "camera.h"
#include "aap.h"
#include "vec3f.h"

const int width = 256;
const int height = 256;

const int width_half = width / 2;
const int height_half = height / 2;

int main() {
	float buffer[width][height][4];

	/*
	Sphere s;
	s.r = 1;
	s.pos = vec3f_from(0, 0, 2);
	*/

	AAP obj;
	obj.r = 1;
	obj.pos = vec3f_from(0, 0, 0);

	Camera c;
	c.pos = vec3f_from(0, 3, -5);
	camera_point(&c, vec3f_sub(vec3f_from(0, 0, 0), c.pos));

	Vec3f inc_y = vec3f_divf(c.local_y, width_half);
	Vec3f inc_x = vec3f_divf(c.local_x, height_half);

	Vec3f light_dir = vec3f_from(1, 0, -1);
	light_dir = vec3f_norm(light_dir);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			Vec3f dir = c.local_z;
			dir = vec3f_add(dir, vec3f_mulf(inc_x, x - width_half));
			dir = vec3f_add(dir, vec3f_mulf(inc_y, height_half - y));
			dir = vec3f_norm(dir);

			float t;

			int hit = aap_hit(obj, c.pos, dir, &t);//sphere_hit(s, c.pos, dir, &t);

			if (hit && (t >= 0)) {
				buffer[x][y][0] = 1;
				buffer[x][y][1] = 1;
				buffer[x][y][2] = 1;
				buffer[x][y][3] = 1;
			} else {
				buffer[x][y][0] = 0;
				buffer[x][y][1] = 0;
				buffer[x][y][2] = 0;
				buffer[x][y][3] = 0;
			}
		}
	}

	FILE* file = fopen("out.ff", "wb");
	fputs("farbfeld", file);
	
	fputc(width >> 24, file);
	fputc((width >> 16) & 0xff, file);
	fputc((width >> 8) & 0xff, file);
	fputc(width & 0xff, file);
	
	fputc(height >> 24, file);
	fputc((height >> 16) & 0xff, file);
	fputc((height >> 8) & 0xff, file);
	fputc(height & 0xff, file);

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			uint16_t r = (uint16_t) (buffer[x][y][0] * ((float) 0xffff));
			uint16_t g = (uint16_t) (buffer[x][y][1] * ((float) 0xffff));
			uint16_t b = (uint16_t) (buffer[x][y][2] * ((float) 0xffff));
			uint16_t a = (uint16_t) (buffer[x][y][3] * ((float) 0xffff));

			fputc(r >> 8, file);
			fputc(r & 0xff, file);
			fputc(g >> 8, file);
			fputc(g & 0xff, file);
			fputc(b >> 8, file);
			fputc(b & 0xff, file);
			fputc(a >> 8, file);
			fputc(a & 0xff, file);
		}
	}

	fclose(file);

	return 0;
}