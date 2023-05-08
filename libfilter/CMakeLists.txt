set(libPacketFilterSources
        src/FilterExpression.cpp
        src/FilterDescriptor.cpp
        src/FilterDescriptorLibrary.cpp)

set(libPacketFilterHeaders
        include/FilterExpression.h
        include/FilterDescriptor.h
        include/FilterDescriptorLibrary.h)

add_library(libpktfltr STATIC
        ${libPacketFilterHeaders} ${libPacketFilterSources})

target_include_directories(libpktfltr PUBLIC include)