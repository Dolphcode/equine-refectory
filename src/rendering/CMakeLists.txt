# Define the rendering library
add_library(rendering 
	shader.cpp
)
target_include_directories(rendering PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(rendering
	PUBLIC
		glad_gl_core_46
	)

