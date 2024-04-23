#include <iostream>
#include <print.hpp>
#include <other.hpp>
extern "C" {
    #include <evolution.h>
    #include <new.h>
}

int main() {
    std::cout << "Hello, World! 2" << std::endl;
    print();
    evo_fn();
    other();
    newPrint();
    return 0;
}
