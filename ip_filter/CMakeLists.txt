set(LIB_NAME ip_filter_lib)
set(SOURCES src/ip_filter.cpp)

add_library(${LIB_NAME} ${SOURCES})

target_include_directories(${LIB_NAME} PUBLIC
        include
        PRIVATE "${CMAKE_BINARY_DIR}"
        )
