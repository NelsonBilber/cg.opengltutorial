# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (Tutorials)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/GLFW/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	external/bullet-2.81-rev2613/src/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Tutorial 1
add_executable(01-CreateWindow 
	01-CreateWindow/main.cpp
)
target_link_libraries(01-CreateWindow
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(01-CreateWindow PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/01-CreateWindow/")
create_target_launcher(01-CreateWindow WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/01-CreateWindow/")

# Tutorial 2
add_executable(02-Triangle 
	02-Triangle/main.cpp
	common/shader.cpp
	common/shader.hpp
	
	02-Triangle/SimpleFragmentShader.fragmentshader
	02-Triangle/SimpleVertexShader.vertexshader
)
target_link_libraries(02-Triangle
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(02-Triangle PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/02-Triangle/")
create_target_launcher(02-Triangle WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/02-Triangle/")
create_default_target_launcher(02-Triangle WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/02-Triangle/") 

# Tutorial 3
add_executable(03-Matrices 
	03-Matrices/main.cpp
	common/shader.cpp
	common/shader.hpp
	
	03-Matrices/SimpleFragmentShader.fragmentshader
	03-Matrices/SimpleVertexShader.vertexshader
)
target_link_libraries(03-Matrices
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(03-Matrices PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/03-Matrices/")
create_target_launcher(03-Matrices WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/03-Matrices/")
create_default_target_launcher(03-Matrices WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/03-Matrices/") 



SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )


if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
add_custom_command(
   TARGET 01-CreateWindow POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/01-CreateWindow${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tutorial01_first_window/"
)
add_custom_command(
   TARGET 02-Triangle POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/02-Triangle${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/02-Triangle/"
)
add_custom_command(
   TARGET 03-Matrices POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/03-Matrices${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/03-Matrices/"
)


elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

