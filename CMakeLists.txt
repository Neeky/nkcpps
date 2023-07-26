cmake_minimum_required(VERSION 3.21.0)
project(nkcpps VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

aux_source_directory(src src_files)

add_executable(nkcpps src/main.cpp)
add_executable(thread-create src/pthreads/create.cpp)
add_executable(thread-exit src/pthreads/join.cpp)
add_executable(thread-mutex-lock src/pthreads/mutex-lock.cpp)
add_executable(thread-mutex-dead-lock src/pthreads/mutex-dead-lock.cpp)
add_executable(thread-rwlock src/pthreads/rwlock.cpp)

add_executable(times-time src/times/time.cpp)
add_executable(times-timespec src/times/timespec.cpp)



include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(CTest)
enable_testing()

include(tests/CMakeLists.txt)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
