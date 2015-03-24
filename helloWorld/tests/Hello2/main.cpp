/* Hello World program */
#include <iostream>
#include <functional>

int main(int argc, char** argv)
{
    typedef std::function<const char* const(void)> StringFunction_t;
    StringFunction_t helloString = [](){
        return "Hello World!\n";
    };
    std::cout << helloString();
    return 0;
}
