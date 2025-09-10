#include <iostream>

class Test
{
public:
    Test (int x) : x(x) {}
    Test (const Test& t) : x(t.x) {}

    Test& operator++() {
        x++;
        std::cout << "전위 증감 연산자" << std::endl;
        return *this;
    }

    // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
    // 받지만 실제로는 아무것도 전달되지 않는다.
    Test operator++(int) {
        Test temp(*this);
        x++;
        std::cout << "후위 증감 연산자" << std::endl;
        return temp;
    }

    int get_x() const {
        return x;
    }

private:
    /* data */
    int x;
};
void func(const Test& t) {
    std::cout << "x : " << t.get_x() << std::endl;
}

int main(int argc, char *argv[])
{
    Test t(3);

    func(++t);
    func(t++);
    std::cout << "x : " << t.get_x() << std::endl;
    return 0;
}
