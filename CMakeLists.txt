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
	
	03-Matrices/SingleColor.fragmentshader
	03-Matrices/SimpleTransform.vertexshader
)
target_link_libraries(03-Matrices
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(03-Matrices PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/03-Matrices/")
create_target_launcher(03-Matrices WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/03-Matrices/")
create_default_target_launcher(03-Matrices WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/03-Matrices/") 

# Tutorial 4
add_executable(04-ColoredCube 
	04-ColoredCube/main.cpp
	common/shader.cpp
	common/shader.hpp
	
	04-ColoredCube/ColorFragmentShader.fragmentshader
	04-ColoredCube/TransformVertexShader.vertexshader
)
target_link_libraries(04-ColoredCube
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(04-ColoredCube PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/04-ColoredCube/")
create_target_launcher(04-ColoredCube WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/04-ColoredCube/")
create_default_target_launcher(04-ColoredCube WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/04-ColoredCube/") 


# Tutorial 5
add_executable(05-TextureCube
	05-TextureCube/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/texture.cpp
	common/texture.hpp
	
	05-TextureCube/TransformVertexShader.vertexshader
	05-TextureCube/TextureFragmentShader.fragmentshader
)
target_link_libraries(05-TextureCube
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(05-TextureCube PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/05-TextureCube/")
create_target_launcher(05-TextureCube WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/05-TextureCube/")

# Tutorial 6
add_executable(06-KeyboardMouse
	06-KeyboardMouse/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	
	06-KeyboardMouse/TransformVertexShader.vertexshader
	06-KeyboardMouse/TextureFragmentShader.fragmentshader
)
target_link_libraries(06-KeyboardMouse
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(06-KeyboardMouse PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/06-KeyboardMouse/")
create_target_launcher(06-KeyboardMouse WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/06-KeyboardMouse/")


# Tutorial 7
add_executable(07-ModelLoading
	07-ModelLoading/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp

	07-ModelLoading/TransformVertexShader.vertexshader
	07-ModelLoading/TextureFragmentShader.fragmentshader
)
target_link_libraries(07-ModelLoading
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(07-ModelLoading PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/07-ModelLoading/")
create_target_launcher(07-ModelLoading WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/07-ModelLoading/")

# Tutorial 8
add_executable(08-BasicShading
	08-BasicShading/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	
	08-BasicShading/StandardShading.vertexshader
	08-BasicShading/StandardShading.fragmentshader
)
target_link_libraries(08-BasicShading
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(08-BasicShading PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/08-BasicShading/")
create_target_launcher(08-BasicShading WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/08-BasicShading/")

# Tutorial 9

add_executable(09-VertexBufferObject
	09-VertexBufferObject/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp
	
	09-VertexBufferObject/StandardShading.vertexshader
	09-VertexBufferObject/StandardShading.fragmentshader
)
target_link_libraries(09-VertexBufferObject
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(09-VertexBufferObject PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/09-VertexBufferObject/")
create_target_launcher(09-VertexBufferObject WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/09-VertexBufferObject/")


# Tutorial 10
add_executable(10-Transparency
	10-Transparency/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp
	
	10-Transparency/StandardShading.vertexshader
	10-Transparency/StandardTransparentShading.fragmentshader
)
target_link_libraries(10-Transparency
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(10-Transparency PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/10-Transparency/")
create_target_launcher(10-Transparency WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/10-Transparency/")

# Tutorial 11
add_executable(11-Text
	11-Text/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp
	common/text2D.hpp
	common/text2D.cpp

	11-Text/StandardShading.vertexshader
	11-Text/StandardShading.fragmentshader
	11-Text/TextVertexShader.vertexshader
	11-Text/TextVertexShader.fragmentshader

)
target_link_libraries(11-Text
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(11-Text PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/11-Text/")
create_target_launcher(11-Text WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/11-Text/")


# Tutorial 13
add_executable(13-NormalMapping
	13-NormalMapping/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp
	common/text2D.hpp
	common/text2D.cpp
	common/tangentspace.hpp
	common/tangentspace.cpp
	
	13-NormalMapping/NormalMapping.vertexshader
	13-NormalMapping/NormalMapping.fragmentshader
)
target_link_libraries(13-NormalMapping
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(13-NormalMapping PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/13-NormalMapping/")
create_target_launcher(13-NormalMapping WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/13-NormalMapping/")

# Tutorial 14
add_executable(14-RenderToTexture
	14-RenderToTexture/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp
	common/text2D.hpp
	common/text2D.cpp
	
	14-RenderToTexture/StandardShadingRTT.vertexshader
	14-RenderToTexture/StandardShadingRTT.fragmentshader
	14-RenderToTexture/Passthrough.vertexshader
	14-RenderToTexture/WobblyTexture.fragmentshader
)
target_link_libraries(14-RenderToTexture
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(14-RenderToTexture PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/14-RenderToTexture/")
create_target_launcher(14-RenderToTexture WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/14-RenderToTexture/")


# Tutorial 15
add_executable(15-Lightmaps
	15-Lightmaps/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp
	
	15-Lightmaps/TransformVertexShader.vertexshader
	15-Lightmaps/TextureFragmentShaderLOD.fragmentshader
)
target_link_libraries(15-Lightmaps
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(15-Lightmaps PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/15-Lightmaps/")
create_target_launcher(15-Lightmaps WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/15-Lightmaps/")


# Tutorial 16
add_executable(16-ShadowMapping
	16-ShadowMapping/main.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp
	common/texture.cpp
	common/texture.hpp
	common/objloader.cpp
	common/objloader.hpp
	common/vboindexer.cpp
	common/vboindexer.hpp
	
	16-ShadowMapping/ShadowMapping_SimpleVersion.vertexshader
	16-ShadowMapping/ShadowMapping_SimpleVersion.fragmentshader
	16-ShadowMapping/DepthRTT.vertexshader
	16-ShadowMapping/DepthRTT.fragmentshader
)
target_link_libraries(16-ShadowMapping
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(16-ShadowMapping PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/16-ShadowMapping/")
create_target_launcher(16-ShadowMapping WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/16-ShadowMapping/")



#####################################################################

SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

#####################################################################


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
add_custom_command(
   TARGET 04-ColoredCube POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/04-ColoredCube${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/04-ColoredCube/"
)
add_custom_command(
   TARGET 05-TextureCube POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/05-TextureCube${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/05-TextureCube/"
)
add_custom_command(
   TARGET 06-KeyboardMouse POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/06-KeyboardMouse${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/06-KeyboardMouse/"
)
add_custom_command(
   TARGET 07-ModelLoading POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/07-ModelLoading${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/07-ModelLoading/"
)
add_custom_command(
   TARGET 08-BasicShading POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/08-BasicShading${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/08-BasicShading/"
)
add_custom_command(
   TARGET 09-VertexBufferObject POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/09-VertexBufferObject${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/09-VertexBufferObject/"
)
add_custom_command(
   TARGET 10-Transparency POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/10-Transparency${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/10-Transparency/"
)
add_custom_command(
   TARGET 11-Text POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/11-Text${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/11-Text/"
)
add_custom_command(
   TARGET 13-NormalMapping POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/13-NormalMapping${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/13-NormalMapping/"
)
add_custom_command(
   TARGET 14-RenderToTexture POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/14-RenderToTexture${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/14-RenderToTexture/"
)
add_custom_command(
   TARGET 15-Lightmaps POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/15-Lightmaps${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/15-Lightmaps/"
)
add_custom_command(
   TARGET 16-ShadowMapping POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/16-ShadowMapping${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/16-ShadowMapping/"
)





elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

