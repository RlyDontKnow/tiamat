cmake_minimum_required(VERSION 3.7)

project(tiamat CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "..." FORCE)
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/project" CACHE PATH "..." FORCE)
endif()

find_package(Boost COMPONENTS thread signals system REQUIRED)

add_library(tiamat SHARED
  src/agent.cpp
  src/agent.h
  src/agent_animator.cpp
  src/agent_animator.h
  src/movement.h
  src/registry.cpp
  )
target_include_directories(tiamat PUBLIC
  "${CMAKE_SOURCE_DIR}/godot_headers"
  "${CMAKE_SOURCE_DIR}/cpp_bindings/include"
  "${CMAKE_SOURCE_DIR}/cpp_bindings/include/core"
  "${Boost_INCLUDE_DIR}"
  )
target_link_libraries(tiamat PUBLIC "${CMAKE_SOURCE_DIR}/cpp_bindings/bin/cpp_bindings.windows.64.lib")

install(TARGETS tiamat
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )
