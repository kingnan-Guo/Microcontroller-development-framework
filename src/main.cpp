#include <iostream>
#include <fmt/format.h>
#include <print.hpp>
// #include <evolution.h>
extern "C" {
    #include <evolution.h>
}

int main(){
    std::cout << fmt::format("Hello, {}!", "world") << std::endl;
    std::cout << fmt::format("fmt version : {}", FMT_VERSION) << std::endl;
    std::cout << "Hello, world!" << std::endl;
    print();
    evo_fn();
    // fmt::print("Hello, world!");
    return 0;
}



// #include <stdio.h>
// // #include <fmt/format.h>
// #include <print.hpp>
// #include <evolution.h>
// #include <iostream>
// // extern "C" {
// //     #include <evolution.h>
// // }

// int main(){

//     // printf("fmt version : %d\n", FMT_VERSION);
//     printf("Hello, world main.c!\n");
//     print();
//     evo_fn();
//     // fmt::print("Hello, world!");
//     return 0;
// }