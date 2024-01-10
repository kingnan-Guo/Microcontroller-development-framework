# Microcontroller-development-framework
gcc/xcode/VisualStudio +  cmake +  vcpkg  Microcontroller development framework
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
Drivers     
compile     用于放置 交叉编译的 依赖文件
device      设备 文件


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





####

/usr/local/vcpkg
cmake -B ./build -S . -DCMAKE_TOOLCHAIN_FILE="[vcpkg-root]/scripts/buildsystems/vcpkg.cmake"



vcpkg install library_name





###### mac

这个版本中 
1、安装了 vcpkg 放到了   /usr/local/vspkg 目录下
<!-- 2、安装了 cmake 放到了   /usr/local/vspkg/scripts/buildsystems 目录下 -->
2、brew 安装了  pkg-config : pkg-config
3、vcpkg install  fmt
4、vcpkg.json 配置了信息 但是 "builtin-baseline": "c9919121dde6f61c0436adda94624636e041226b", 会导致安装 报错
5、首选项 配置
"cmake.configureSettings": {
    "CMAKE_TOOLCHAIN_FILE": "/usr/local/vspkg/scripts/buildsystems/vcpkg.cmake",//"/Users/kingnan/.espressif/tools/cmake/3.24.0/CMake.app/Contents/share/cmake-3.24/Modules/Platform/ESP32.cmake"
}

6、 shift+commad/ctrl +p 搜索 ：C/C++ 配置 生成 c_cpp_properties.json
7、 

