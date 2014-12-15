include_directories(${CMAKE_SOURCE_DIR}/includes) 

add_executable(imotionlogger imotionlogger.cpp)
target_link_libraries(imotionlogger inc ${LCM_LIBRARY} -pthread)
