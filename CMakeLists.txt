cmake_minimum_required(VERSION 3.11)

project(raytracer)

add_executable(
	raytracer

	${PROJECT_BINARY_DIR}/src/main.c
	${PROJECT_BINARY_DIR}/src/vec3f.c
	${PROJECT_BINARY_DIR}/src/sphere.c
	${PROJECT_BINARY_DIR}/src/camera.c
	${PROJECT_BINARY_DIR}/src/aac.c
	${PROJECT_BINARY_DIR}/src/aap.c
)

target_link_libraries(raytracer m)

set_target_properties(raytracer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)