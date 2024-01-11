#include <iostream>
// #include <fmt/format.h>
#include <print.hpp>

#include "config.h"

#ifdef TEST_OPTION
    #include <other.hpp>
#endif

// #include <evolution.h>
extern "C" {
    #include <evolution.h>
}

int main(){
    // std::cout << fmt::format("Hello, {}!", "world") << std::endl;
    // std::cout << fmt::format("fmt version : {}", FMT_VERSION) << std::endl;
    std::cout << "Hello, world!" << std::endl;
    print();
    evo_fn();

    #ifdef TEST_OPTION
        other();
    #endif
        // 打印 c++ 版本信息
        std::cout << "__cpluspluse" << __cplusplus << std::endl;
    

    // fmt::print("Hello, world!");
    return 0;
}
