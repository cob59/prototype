cmake_minimum_required (VERSION 3.4)

include(CMakeParseArguments)

macro(ScanForSources)
	set(options "")
	set(oneValueArgs DESTINATION)
	set(multipleValueArgs DIRS)
	cmake_parse_arguments(SRC "${options}" "${oneValueArgs}" "${multipleValueArgs}" ${ARGN})
	
	foreach(dir IN LISTS SRC_DIRS)
		file(GLOB_RECURSE files
			${dir}/*.hpp
			${dir}/*.cpp
			${dir}/*.h
			${dir}/*.c
		)
		list(APPEND ${SRC_DESTINATION} ${files})
	endforeach()
endmacro(ScanForSources)

project (prototype)

# SFML
set(SFML_ROOT ${CMAKE_SOURCE_DIR}/sfml)
list(APPEND CMAKE_MODULE_PATH ${SFML_ROOT}/cmake/Modules)
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML 2 COMPONENTS graphics network audio window system main REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

ScanForSources(
	DESTINATION AllSources 
	DIRS 
	${CMAKE_SOURCE_DIR}/core
	${CMAKE_SOURCE_DIR}/pugixml
	${CMAKE_SOURCE_DIR}/sqlite
)

add_executable ( 
	${PROJECT_NAME} 
	${CMAKE_SOURCE_DIR}/main.cpp
	${AllSources}
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
