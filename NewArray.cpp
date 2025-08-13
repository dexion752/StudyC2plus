#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int arrSize;
    cout << "array size: ";
    cin >> arrSize;

    int* list = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
       cin >> list[i];
    }
    for (int i = 0; i < arrSize; i++) {
        cout << i << "th element of list: " << list[i] <<endl;
    }

    delete[] list;
    return 0; 
}
