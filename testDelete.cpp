#include <iostream>

class Test
{
public:
    Test (char x);
    virtual ~Test ();

    void functionSample();

private:
    /* data */
    char c;
};
Test::Test(char x)
{
    c = x;
    std::cout << "생성자 호출!"<< std::endl;
    std::cout << c << std::endl;
}
Test::~Test()
{
    std::cout << "소멸자 호출!"<< std::endl;
    std::cout << c << std::endl;
}
void functionSample()
{
    Test b('b');
}

int main(int argc, char *argv[])
{
    Test a('a');
    functionSample();
    return 0;
}
