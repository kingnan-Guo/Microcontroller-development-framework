ADD_EXECUTABLE(mdf main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(mdf PRIVATE fmt::fmt)