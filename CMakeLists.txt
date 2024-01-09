#CMakeLists.txt
# cmake最低版本需求，不加入此行会受到警告信息
cmake_minimum_required(VERSION 3.28.1)

# 项目名称，同时会自动生成 PROJECT_NAME 变量，
# 使用${PROJECT_NAME} 即可访问到 Microcontroller-development-framework。
project(MDF)

# set(CMAKE_C_COMPILER gcc)
# set(CMAKE_CXX_COMPILER g++)

# TARGET_LINK_LIBRARIES(MDF lib) #链接的库
# 添加头文件路径
INCLUDE_DIRECTORIES(include)


# 添加源代码文件夹 src，并生成可执行文件到 bin 文件夹
ADD_SUBDIRECTORY(src bin)
ADD_SUBDIRECTORY(lib libBin)  #添加子目录
# AUX_SOURCE_DIRECTORY(. SRC_LIST) #把当前目录下所有源代码文件名加入变量SRC_LIST








if(CMAKE_SYSTEM_NAME MATCHES "Linux")  
    message(STATUS "Running on Linux操作系统")  
    # 在这里添加适用于Linux的操作系统的特定配置  
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")  
    message(STATUS "Running on Windows操作系统 -------------------------")  
    # 在这里添加适用于Windows的操作系统的特定配置  
    message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
    message(STATUS "CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
    # 添加头文件搜索路径
    INCLUDE_DIRECTORIES(include)
    LINK_DIRECTORIES(lib)

    
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")  
    message(STATUS "Running on macOS/iOS操作系统")  
    # 在这里添加适用于macOS/iOS的操作系统的特定配置  
else()  
    message(STATUS "Running on an unknown operating system")  
    # 在这里添加适用于其他操作系统的通用配置  
endif()



############################################
# 安装规则

# 注意，下面的命令将在项目编译完成后自动安装目标二进制和目标文件到 /usr/local/bin 和 /usr/local/
# INSTALL(TARGETS MDF DESTINATION bin)
# DESTINATION  目标二进制和目标文件的安装路径，如果目标二进制和目标文件不安装到默认路径，需要在此指定安装路径
INSTALL(FILES COPYING README.md DESTINATION share/doc/${PROJECT_NAME})

# 非目标可执行脚本的 程序安装 runProject.sh
INSTALL(PROGRAMS runProject.sh DESTINATION bin)

# 安装目录 doc/text.txt
# doc 这个目录安装到目标路径下
# doc/   这个目录下的内容安装到目标路径下
INSTALL(DIRECTORY doc/ DESTINATION share/doc/${PROJECT_NAME})

#安装可执行程序
# INSTALL(TERGETS mdf DEFINITIONS bin)



