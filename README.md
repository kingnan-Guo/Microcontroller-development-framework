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
cmake -B ./build -S . -DCMAKE_TOOLCHAIN_FILE="[vcpkg-root]/scripts/buildsystems/vcpkg.cmake"







####
#github 代理
git config --global url.https://hub.fastgit.xyz/.insteadof=https://github.com/
git config --global --unset url.https://hub.fastgit.xyz/.insteadof=https://github.com/
git config --global --unset url.https://ghproxy.com/https://github.com.insteadof
git config --global --unset url.https://hub.fastgit.xyz/.insteadof
git config --global --unset  url.https://github.com.cnpmjs.org.insteadof




###
添加mac vcpkg 环境变量
vim .bash_profile 
source .bash_profile
export PATH=/usr/local/vcpkg:$PATH