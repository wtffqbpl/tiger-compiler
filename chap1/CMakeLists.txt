project(chap1)

add_library(chap1 OBJECT
        main.cc
        prog1.cc
        slp.cc
        util.cc
  )
target_include_directories(chap1 PRIVATE ${gtest_SOURCE_DIR}/include)