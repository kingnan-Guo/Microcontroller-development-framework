# Microcontroller-development-framework
gcc/xcode/VisualStudio +  cmake +  vcpkg  
Microcontroller development framework

#####
include     用于存放.h/.hpp的头文件
bin         用干存放编译输出的可执行文件
build       为工程编译路径
extralib    用于存放第三方库的源码文件
lib         用于存放.a/.so的库文件
modules     用干存放功能模块的代码文件
resource    用干存放图片等资源文件
src         用于存放main源码文件


### win 编译
./build
cmake ..  -G "MinGW Makefiles"

mkdir build
cd build
cmake ..
cmake --build . 


#配置 路径
cmake -D CMAKE_INSTALL_PREFIX=D:\vcpkg\scripts\buildsystems\vcpkg.cmake ..
cmake -D CMAKE_INSTALL_PREFIX=D:\vcpkg\scripts\MDF  ..

cmake --install .

### linux 编译

### Mac 编译

cmake ..
cmake --build . 
