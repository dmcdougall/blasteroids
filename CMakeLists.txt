cmake_minimum_required( VERSION 2.8 )

project( blasteroids C )

find_package( OpenGL REQUIRED )
find_package( GLUT REQUIRED )

FILE(WRITE ${CMAKE_CURRENT_BINARY_DIR}/AllVariables.txt "")
GET_CMAKE_PROPERTY(res VARIABLES)
FOREACH(var ${res})
  FILE(APPEND ${CMAKE_CURRENT_BINARY_DIR}/AllVariables.txt "${var} \"${${var}}\"\n")
ENDFOREACH(var)


include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

add_executable( blast blasteroids.c data.c collide.c )
target_link_libraries( blast ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
