#include <iostream>

int main(int argc, char *argv[])
{
    char* str = new char[10];
    int len = 0;

    char* sample = "string";
    while (*sample) {
       len++;
       sample++;
    }

    for (int i = 0; i < len; ++i) {
        str[i] = *sample;
        sample++;
    }
    str[len] = '\n';

    std::cout << str << std::endl;
    return 0;
}
