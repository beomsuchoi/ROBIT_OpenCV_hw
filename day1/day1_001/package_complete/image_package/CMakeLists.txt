cmake_minimum_required(VERSION 3.8)
project(image_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

# Include directories
include_directories(include)

# Add executable for the node
add_executable(image_filter_node src/image_filter.cpp src/main.cpp)
ament_target_dependencies(image_filter_node rclcpp std_msgs sensor_msgs cv_bridge OpenCV)

# Install targets
install(TARGETS image_filter_node
  DESTINATION lib/${PROJECT_NAME})

# Install header files
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION include/${PROJECT_NAME})

ament_package()
