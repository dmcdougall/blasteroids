cmake_minimum_required( VERSION 2.8 )

project( blasteroids C )

find_package( OpenGL REQUIRED )
find_package( GLUT REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

add_executable( blast blasteroids.c data.c collide.c )
target_link_libraries( blast ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
