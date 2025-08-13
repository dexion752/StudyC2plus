#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int user_input;
    cout << "저의 정보를 표시합니다." << endl;
    cout << "1. 이름" << endl;
    cout << "2. 나이" << endl;
    cout << "3. 성별" << endl;
    cin >> user_input;

    switch (user_input) {
        case 1:
            cout << "Dexion!" << endl;
            break;
        case 2:
            cout << "100살" << endl;
            break;
        case 3:
            cout << "남자" << endl;
            break;
        default:
            cout << "궁금한 게 없군." << endl;
            break;
    }
    return 0;

}
