#include <iostream>

class Complex
{
public:
    Complex (double real, double img) : real(real), img(img) {}
    // Complex& Complex (const Complex& c) : real(c.real), img(c.img){}
    Complex (const Complex& c) { real = c.real; img = c.img; }
    // virtual ~Complex ();

    Complex operator+(const Complex& c);
    Complex operator+(const char* str); 
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);
    Complex& operator=(const Complex& c);

    // 두 개의 객체 사이의 이항 연산자이지만 한 객체만 값이 바뀐다든지 등의 
    // 동등하지 않은 이항 연산자는 멤버 함수로 오버로딩한다.
    Complex& operator+=(const Complex c);
    Complex& operator-=(const Complex c);
    Complex& operator*=(const Complex c);
    Complex& operator/=(const Complex c);
    double get_number(const char *str, int from, int to);

    void println() {
        std::cout << "( " << real << ", " << img << " )" << std::endl;
    }

    friend Complex operator+(const Complex& a, const Complex& b);

private:
    /* data */
    double real, img;
};

// 두 개의 동등한 객체 사이에서의 이항 연산자는 멤버 함수가 아닌
// 외부 함구로 오버로딩한다. 
Complex operator+(const Complex& a, const Complex& b) {
    // Complex temp(a);
    // return a + b;
    // return a.operator+(b);
    Complex temp(a.real + b.real, a.img + b.img);
    return temp;
    // return temp.operator+(b);
}
Complex Complex::operator+(const Complex& c) {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator+(const char* str) {
    // 입력받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
    // 문자열의 끝은 다음과 같다. "[부호](실수부)(부호)i(허수부)"
    // 이때 맨 앞의 부호는 생략 가능하다. (생략 시 + 라 가정)
    //
    int begin = 0, end = strlen(str);
    double str_img = 0.0, str_real = 0.0;

    //  먼저 기준이 되는 i 의 위치를 찾는다.
    int pos_i = -1;
    for (int i = 0; i != end; ++i) {
        if (str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    // 만일 i 가 없다면 이 수는 실수뿐이다.
    if (pos_i == -1) {
        str_real = get_number(str, begin, end - 1);

        Complex temp(str_real, str_img);
        return (*this) + temp;
    }

    str_real = get_number(str, begin, pos_i - 1);
    str_img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') {
        str_img *= -1.0;
    }

    Complex temp(str_real, str_img);
    return (*this) + temp;
}
Complex Complex::operator-(const Complex& c) {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) {
    Complex temp(
            real * c.real - img * c.img,
            real * c.img + img * c.real
            );
    return temp;
}
Complex Complex::operator/(const Complex& c) {
    Complex temp(
            (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
            (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img)
            );
    return temp;
}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}
Complex& Complex::operator+=(const Complex c) {
    (*this) = (*this) + c;
    return *this;
}
Complex& Complex::operator-=(const Complex c) {
    (*this) = (*this) - c;
    return *this;
}
Complex& Complex::operator*=(const Complex c) {
    (*this) = (*this) * c;
    return *this;
}
Complex& Complex::operator/=(const Complex c) {
    (*this) = (*this) / c;
    return *this;
}
double Complex::get_number(const char *str, int from, int to) {
    bool minus = false;
    if (from > to) return 0;

    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i = from; i <= to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += (str[i] - '0');
        } else if (str[i] == '.') {
            integer_part = false;
        } else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else
            break;
    }

    if (minus) {
        num *= -1.0;
    }
    return num;
}
int main(int argc, char *argv[])
{
    Complex a(0, 0);
    a = a + "-1.1 + i3.923";
    a.println();
    Complex b(1, 1);
    Complex c = a + b;
    c.println();
    // Complex b(1, 1);
    // Complex c(0,0);
    // c = a + b;
    // c.println();

    // Complex a(1.0, 2.0);
    // Complex b(3.0, -2.0);
    // Complex c(0.0, 0.0);

    // c = a * b + a / b + a + b;
    // Complex c = a * b + a / b + a + b;
    // c.println();

    // a += b;
    // a.println();
    // b.println();
    return 0;
}


