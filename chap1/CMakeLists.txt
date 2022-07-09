cmake_minimum_required(VERSION 3.20)

project(chap1)

# Generate compile_commands.json file for auto-completion.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Set Debug mode for this project.
set(CMAKE_BUILD_TYPE Debug)

add_executable(chap1
  main.c
  prog1.c
  slp.c
  util.c
  )