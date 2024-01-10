# version V1.0.2
这个版本要搭建工程目录  main.cpp/main.c 要放在 src 中

# Microcontroller-development-framework
gcc/xcode/VisualStudio +  cmake +  vcpkg  
Microcontroller development framework




##### ------ 工程目录结构 ------ 
.temp      自定义文件夹 用于存一些备份信息
.vscode    vscode 配置文件


include         用于存放.h/.hpp的头文件
bin             用干存放编译输出的可执行文件
build           为工程编译路径
extralib        用于存放第三方库的源码文件
lib             用于存放.a/.so的库文件
modules         用干存放功能模块的代码文件
resource        用干存放图片等资源文件
src             用于存放main源码文件
Drivers     
compile         用于放置 交叉编译的 依赖文件
device          设备 文件
vcpkg.json      vcpkg 配置文件
config.h.in     一些固定的变量会存到这里 ; 会在 build 文件夹下 生成 config.h ; 可以 用于存放 交叉编译的 配置文件
run.sh          运行脚本
CMakeLists.txt  cmake 配置文件
.gitignore      git 忽略文件
doc             文档
 
### --- 编译 命令 -----
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
rm -rf *
cmake ..
cmake --build . 


### --- 编译 命令 ----- end







###### 解决问题的记录 ########
###### mac  #####

这个版本中  
1、安装了 vcpkg 放到了   /usr/local/vspkg 目录下; 修改了 vcpkg 下 bootstrap-vcpkg.sh 因为 vspkg-macOs 无法下载下来；然后是在网上找了 vspkg-macOs  资源 修改 .sh内的判断 如果下载 vspkg-macOs 那么直接跳过
<!-- 2、安装了 cmake 放到了   /usr/local/vspkg/scripts/buildsystems 目录下 -->
2、brew 安装了  pkg-config : brew install pkg-config
3、vcpkg install    执行了这个命令 vcpkg 自己安装了 vcpkg 需要的库
4、 vcpkg install  fmt   执行这个 用于 安装  fmt
5、vcpkg.json 配置了信息 但是 "builtin-baseline": "c9919121dde6f61c0436adda94624636e041226b", overrids:[{"name": "fmt", "version": '7.1.0'}]  会导致安装 报错
6、首选项 配置
"cmake.configureSettings": {
    "CMAKE_TOOLCHAIN_FILE": "/usr/local/vspkg/scripts/buildsystems/vcpkg.cmake",//"/Users/kingnan/.espressif/tools/cmake/3.24.0/CMake.app/Contents/share/cmake-3.24/Modules/Platform/ESP32.cmake"
}
7、 shift+commad/ctrl +p 搜索 ：C/C++ 配置 生成 c_cpp_properties.json
8、 

###### win  #####


###### linux  #####


#### 解决问题的记录 end ######






#### 

/usr/local/vcpkg
# 下面这个 不好用 暂存
cmake -B ./build -S . -DCMAKE_TOOLCHAIN_FILE="[vcpkg-root]/scripts/buildsystems/vcpkg.cmake"


# vcpkg 下载 依赖包的命令
vcpkg install library_name