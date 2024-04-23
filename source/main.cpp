#include <iostream>
#include <print.hpp>
#include <other.hpp>
extern "C" {
    #include <evolution.h>
    #include <new.h>
}

int main() {
    std::cout << "main function" << std::endl;
    print();
    evo_fn();
    other();
    newPrint();
    return 0;
}
