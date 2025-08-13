#include <iostream>

using namespace std;

// 레퍼런스를 이용한 방법
// int main(int argc, char *argv[])
// {
//     int a = 3;
//     int& another_a = a;
//
//     another_a = 5;
//
//     cout << "a: " << a << endl;
//     cout << "another_a: " << another_a << endl;
//
//     return 0;
// }

// 포인터를 인자로 받는 방법 
// int changeVal(int *p)
// {
//     *p = 3;
//
//     return 0;
// }
//
//
// int main(int argc, char *argv[])
// {
//     int number = 5;
//
//     cout << number << endl;
//     changeVal(&number);
//     cout << number << endl;
//     return 0;
// }

// 레퍼런스를 인자로 받은 경우
int changeVal(int &p)
{
    p = 3;

    return 0;
}


int main(int argc, char *argv[])
{
    int number = 5;

    cout << number << endl;
    changeVal(number);
    cout << number << endl;
    return 0;
}
