#include <iostream>
#include <string>

class N_Array
{
public:
    N_Array (int n);
    virtual ~N_Array ();

private:
    /* data */
};


int main(int argc, char *argv[])
{

    int d;
    std::cin >> d;
    std::cout << d << std::endl;
    char* arr;
    arr = new char[d];
    
    std::cout << arr.length() << std::endl;

    return 0;
}
