cmake_minimum_required(VERSION 3.27)
project(mdf)

set(CMAKE_CXX_STANDARD 11)

message(STATUS "${PROJECT_NAME} 项目已创建")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}") # 动态库文件打包后位置  .dll .exe
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}") # 静态库文件打包后的位置 .a .lib
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}") # linux 下的 .so  文件  mac  环境下 .dylib 文件

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "Running on Linux操作系统")
    # 在这里添加适用于Linux的操作系统的特定配置
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "Running on Windows操作系统 -------------------------")
    # 在这里添加适用于Windows的操作系统的特定配置
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message(STATUS "Running on macOS/iOS操作系统")
    # 在这里添加适用于macOS/iOS的操作系统的特定配置
else()
    message(STATUS "Running on an unknown operating system")
    # 在这里添加适用于其他操作系统的通用配置
endif()


# configure_file 复制文件到  build 的 /config.h
configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)



include_directories(
        source
        static/print
        static/evolution
        static/point
        static/point2
        static/pointApplication
        static/fileOpen
        static/transformToByte
)

file(GLOB_RECURSE static_SOURCES "static/*.*" )
file(GLOB_RECURSE SOURCES "source/*.*" )





add_executable(mdf ${SOURCES} ${static_SOURCES})



#======== 动态链接库相关 ======

#file(GLOB_RECURSE lib_SOURCES "lib/*.*" )
## 添加动态库
#add_library(lib_library SHARED ${lib_SOURCES})
#
## 设置动态库的输出目录（可选）
#set_target_properties(lib_library PROPERTIES
#        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib"
#)
##添加动态链接库 的include
#target_include_directories(mdf PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/other" "${CMAKE_CURRENT_SOURCE_DIR}/lib/new")
##添加动态链接库到 主项目
#target_link_libraries(mdf PRIVATE lib_library)


## 获取 /lib 文件夹下的所有 CPP 和 HPP 文件
file(GLOB lib_other_SOURCES "lib/other/*.*" )
file(GLOB lib_new_SOURCES "lib/new/*.*" )
## 添加动态库
add_library(lib_other_SOURCES SHARED ${lib_other_SOURCES})
add_library(lib_new_SOURCES SHARED ${lib_new_SOURCES})

set_target_properties(lib_other_SOURCES PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib"
)
set_target_properties(lib_new_SOURCES PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lib"
)

#添加动态链接库 的include
target_include_directories(mdf PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/other" "${CMAKE_CURRENT_SOURCE_DIR}/lib/new")
#添加动态链接库到 主项目
target_link_libraries(mdf PRIVATE lib_other_SOURCES)
target_link_libraries(mdf PRIVATE lib_new_SOURCES )

