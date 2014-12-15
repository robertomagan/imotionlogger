add_library(inc SHARED
  thread/threadengine.cpp
  lcm/lcmthread.cpp
  lcm/lcmhandler.cpp
  beans/node.cpp
  lcm/protectedmutex.cpp 
  motion/BonnMotionFile.cpp
  motion/BonnMotionMobility.cpp
  motion/Coord.cpp
)
target_link_libraries(inc ${LCM_LIBRARY})
