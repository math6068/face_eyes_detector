cmake_minimum_required(VERSION 3.13)

project(faces_detector)

# Find the Opencv and GTest lib
find_package(OpenCV REQUIRED)

# Add include directories
include_directories(/usr/local/include/opencv4)


# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()


# Set sources files
set(DETECTOR_LIB
    detector_lib/FaceDetector.hpp
    detector_lib/FaceDetector.cpp
    detector_lib/EyesDetector.hpp
    detector_lib/EyesDetector.cpp
)

# Set header files
set(DETECTOR_LIB_HEADER
    detector_lib/FaceDetector.hpp
    detector_lib/EyesDetector.hpp
)

set(MAIN_FUNCTION
    "detect/main.cpp"
)


# Set test files
set(TEST_SOURCES
    test/TestFaceDetector.cpp
    test/TestEyesDetector.cpp
)
set(OpenCV_DIR /usr/local/opencv/share/OpenCV)

include_directories(".")
add_library(detector_libs  ${DETECTOR_LIB})
add_executable(${PROJECT_NAME} ${MAIN_FUNCTION} ${DETECTOR_LIB_HEADER})

target_link_libraries(${PROJECT_NAME} detector_libs ${OpenCV_LIBS})

add_executable(detector_test ${TEST_SOURCES} )
target_link_libraries(detector_test gtest gtest_main detector_libs ${OpenCV_LIBS})
