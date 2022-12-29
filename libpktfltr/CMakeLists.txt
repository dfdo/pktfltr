include_directories(include)

FILE(GLOB GlobAllSrc src/*.cpp)

add_library(pktfltr ${GlobAllSrc})

