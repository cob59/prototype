cmake_minimum_required (VERSION 2.8)
 
project (prototype)

# SFML
set(SFML_ROOT ${CMAKE_SOURCE_DIR}/sfml)
list(APPEND CMAKE_MODULE_PATH ${SFML_ROOT}/cmake/Modules)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 COMPONENTS graphics network audio window system main REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable ( 
	${PROJECT_NAME} 
	${CMAKE_SOURCE_DIR}/main.cpp
)

target_link_libraries (
	${PROJECT_NAME}
	${SFML_LIBRARIES}
	${GLEW_LIBRARY}
	${JPEG_LIBRARY}
	${OPENAL_LIBRARY}
	${FREETYPE_LIBRARY}
	${SNDFILE_LIBRARY}
	${SFML_WINDOW_DEPENDENCIES}
)
