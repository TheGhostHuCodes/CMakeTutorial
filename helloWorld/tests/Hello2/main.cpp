/* Hello World program */
#include <iostream>
#include <functional>
#include "Hello.hpp"
#include "World.hpp"

int main(int argc, char** argv)
{
    std::cout << HelloString() << " " << WorldString();
    return 0;
}
