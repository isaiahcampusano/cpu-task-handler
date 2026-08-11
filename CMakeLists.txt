cmake_minimum_required(VERSION 3.16)

project(cpu_task_handler VERSION 1.0 LANGUAGES CXX)

add_executable(cpu-task-handler
    src/main.cpp
    src/process.cpp
    src/scheduler.cpp
)

target_include_directories(cpu-task-handler PRIVATE include)
target_compile_features(cpu-task-handler PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(cpu-task-handler PRIVATE /W4)
else()
    target_compile_options(cpu-task-handler PRIVATE -Wall -Wextra -Wpedantic)
endif()
