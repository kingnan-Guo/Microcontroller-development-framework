#include <iostream>
#include <print.hpp>
#include <other.hpp>
extern "C" {
    #include <evolution.h>
    #include <new.h>
    #include <point.h>
    #include <point2.h>
    #include <pointApplication.h>
    #include <fileOpen.h>
    #include <transformToByte.h>
}

int main() {
    std::cout << "main function" << std::endl;
    print();
    evo_fn();
    other();
    newPrint();
    point_fn();
    point_fn2();



    point_application_main();
    fileOpenMain();
    transformToByteMain();
    return 0;
}
