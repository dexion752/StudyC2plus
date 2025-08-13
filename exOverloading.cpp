// #include <iostream>
//
// void print(int x)
// {
//     std::cout << "int : " << x << std::endl;
// }
// void print(char x)
// {
//     std::cout << "char : " << x << std::endl;
// }
// void print(double x)
// {
//     std::cout << "double : " << x << std::endl;
// }
//
// int main(int argc, char *argv[])
// {
//     int x = 2;
//     char y = 'x';
//     double z = 3.14f;
//     print(x);
//     print(y);
//     print(z);
//     return 0;
// }
#include <iostream>

void print(int num) {
	std::cout << "정수 : " << num << std::endl;
}

void print(double num) {
	std::cout << "실수 : " << num << std::endl;
}

void print(int *ptr) {
	if (ptr == nullptr) {
		std::cout << "널 포인터" << std::endl;
	} else {
		std::cout << "포인터 주소 : " << ptr << std::endl;
	}
}

int main() 
{
	print(10);  //정수 10 
	print(3.14); // 실수 3.14
	print(0);  // 정수 0(0이 int로 변환)
	print(nullptr);  // 널 포인터
    print((int*)0);  // 널 포인터 (명시적으로 int* 타입으로 변환    
    return 0;
}
