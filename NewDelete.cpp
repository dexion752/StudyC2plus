// new, delete 사용법
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int* p = new int;
    *p = 10;

    cout << *p << endl;

    delete p;
    return 0;
}
