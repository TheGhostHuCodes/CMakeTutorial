/* Hello World program */
#include <iostream>

int main(int argc, char** argv)
{
    auto helloString = [](){
        return "HelloWorld!\n";
    };
    std::cout << helloString();
    return 0;
}
