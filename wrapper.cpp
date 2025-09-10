#include <iostream>

class Int
{
    // 기본 자료형(int, float)을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것.
    int data;

    public:
    Int(int data) : data(data) {}
    Int(const Int& i) : data(i.data) {}

    operator int() { return data; }
};

int main(int argc, char *argv[])
{
    Int x = 3;
    int a = x + 4;

    x = a * 2 + x + 4;
    std::cout << x << std::endl;
    return 0;
}

