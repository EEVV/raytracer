#pragma once

typedef struct {
	float x, y, z;
} Vec3f;

Vec3f vec3f_from(float x, float y, float z);

Vec3f vec3f_add(Vec3f a, Vec3f b);
Vec3f vec3f_sub(Vec3f a, Vec3f b);

Vec3f vec3f_mulf(Vec3f a, float b);
Vec3f vec3f_divf(Vec3f a, float b);

Vec3f vec3f_norm(Vec3f a);

float vec3f_dot(Vec3f a, Vec3f b);

float vec3f_len(Vec3f a);