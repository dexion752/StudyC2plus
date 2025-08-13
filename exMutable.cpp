#include <iostream>

class A
{
public:
    A (int data) : data_(data) {}
    void DoSomething(int x) const {
        data_ = x;
    }

    void PrintData() const { std::cout << "data: " << data_ << std::endl; }


private:
    mutable int data_;
};

int main(int argc, char *argv[])
{
    A a(10);
    a.DoSomething(3);
    a.PrintData();
    return 0;
}
