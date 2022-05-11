cmake_minimum_required(VERSION 3.20)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(OPENCV_PATH external/opencv)
set(OPENCV_MODULES highgui core imgcodecs videoio)

project(TestOpencv)

add_subdirectory(external/opencv)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME}
        PUBLIC ${OPENCV_PATH}/include
        PUBLIC ${PROJECT_BINARY_DIR}
        )

foreach(module IN LISTS OPENCV_MODULES)
    target_include_directories(${PROJECT_NAME} PUBLIC ${OPENCV_PATH}/modules/${module}/include)
endforeach()

target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR}/bin)

foreach(module IN LISTS OPENCV_MODULES)
    target_link_libraries(${PROJECT_NAME} opencv_${module})
endforeach()