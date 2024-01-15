mac 交叉编译工具链

ESP8266
vim .bash_profile

 export PATH=/usr/local/vcpkg:$PATH
 export PATH=/usr/local/opt/gnu-sed/libexec/gnubin:$PATH
 export PATH=/opt/mcu/ESP8266/cross_compilation/xtensa-lx106-elf/bin:$PATH


source .bash_profile
xtensa-lx106-elf-gcc -v 是否安装成功