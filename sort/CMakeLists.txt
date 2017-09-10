project(sort)

include_directories(${CMAKE_CURRENT_LIST_DIR})

#source directory
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_LIST_DIR} DIR_SRCS) 

#${PROJECT_NAME}
add_executable(${PROJECT_NAME} ${DIR_SRCS} )