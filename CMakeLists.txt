#CMakeLists.txt
# cmake最低版本需求，不加入此行会受到警告信息
cmake_minimum_required(VERSION 3.28.1)

       



# 项目名称，同时会自动生成 PROJECT_NAME 变量，
# 使用${PROJECT_NAME} 即可访问到 Microcontroller-development-framework。
project(Mdf VERSION 1.0.1)
message(STATUS "${PROJECT_NAME} 项目已创建")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}") # 动态库文件打包后位置  .dll .exe 
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}") # 静态库文件打包后的位置 .a .lib 
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}") # linux 下的 .so  文件  mac  环境下 .dylib 文件

# 创建一个 interface 虚拟的 库 mdf_compiler_flags
# 添加编译特性 cxx_std_11 到 mdf_compiler_flags
# add_library(mdf_compiler_flags INTERFACE)
# target_compile_features(mdf_compiler_flags INTERFACE cxx_std_11)
add_library(mdf_compiler_flags INTERFACE)
target_compile_features(mdf_compiler_flags INTERFACE cxx_std_11)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "Running on Linux操作系统")
    # 在这里添加适用于Linux的操作系统的特定配置  
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")  
    message(STATUS "Running on Windows操作系统 -------------------------")  
    # 在这里添加适用于Windows的操作系统的特定配置  
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")  
    message(STATUS "Running on macOS/iOS操作系统")
    # 在这里添加适用于macOS/iOS的操作系统的特定配置
    set(VCPKG_ROOT "/usr/local/vcpkg") # 手动设置到你的vcpkg根目录
else()  
    message(STATUS "Running on an unknown operating system")  
    # 在这里添加适用于其他操作系统的通用配置  
endif()



set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
message(STATUS "${CMAKE_TOOLCHAIN_FILE} CMAKE_TOOLCHAIN_FILE")






# 使用 option 创建 一个变量 TEST_OPTION 默认值 ON/OFF TRUE/FALSE
option(TEST_OPTION "Use provided math" ON)
# SET(TEST_OPTION TRUE)
message(STATUS "TEST_OPTION is ${TEST_OPTION}")

if(TEST_OPTION)
    message(STATUS "可以通过 命令配置 TEST_OPTION 为  ON/OFF")
    # APPEND 是个列表  ； EXTA_LIBS 追加 后面是库的名称
    list(APPEND EXTRA_LIBS other)
    # 追加 后面是头文件的名称; 但是 other 已经在 自己的CMakeLists 中配置 了 target_include_directories(other PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 所以不需要了
    # list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lib/other")
endif()

# message(STATUS "${VCPKG_ROOT} VCPKG_ROOT")

# configure_file 
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)



SET(FREE_RTOS_DIR "${PROJECT_SOURCE_DIR}/extralib/freeRtos")
find_library(FreeRTOS FREE_RTOS_DIR)



# 链接src
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(extralib)

