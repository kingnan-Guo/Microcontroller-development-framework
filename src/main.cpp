#include <iostream>
#include <fmt/format.h>



int main(){
    std::cout << fmt::format("Hello, {}!", "world") << std::endl;
    std::cout << fmt::format("fmt version : {}", FMT_VERSION) << std::endl;
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
