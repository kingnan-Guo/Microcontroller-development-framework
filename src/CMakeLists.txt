ADD_EXECUTABLE(mdf main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(mdf PRIVATE fmt::fmt)

# 添加链接库  连接src下的main.c 与 lib文件夹下的print.cpp  
# target_link_libraries(mdf PUBLIC /lib/print)

# #制定头文件 位置
# # PUBLIC  PRIVATE I
target_include_directories(mdf 
PUBLIC 
    ${PROJECT_BINARY_DIR}
    ${PROJECT_BINARY_DIR}/lib
    ${PROJECT_SOURCE_DIR}/lib
)

add_subdirectory(evolution)
target_link_libraries(mdf 
PUBLIC
    evolution
    print
)


