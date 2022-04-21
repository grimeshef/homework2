cmake_minimum_required(VERSION 3.19.0)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
set(TARGET "homework2")

project(${TARGET} VERSION ${PROJECT_VERSION})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/ip_filter)

add_executable(${TARGET}_cli main.cpp)

target_link_libraries(${TARGET}_cli ip_filter_lib)
set_target_properties(${TARGET}_cli PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

install(TARGETS ${TARGET}_cli RUNTIME DESTINATION bin)


set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT alexmaltsevvik@gmail.com)
include(CPack)