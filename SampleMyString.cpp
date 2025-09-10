#include <iostream>
#include <string.h>


class MyString
{
public:
    MyString (char c);
    MyString (const char* str);
    MyString (const MyString& str);
    ~MyString ();

    int length() const;
    int capacity() const;
    void reserve(int size);
    void print() const;
    void println() const;
    char at(int i) const; 

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, char c);
    MyString& myInsert(int loc, const MyString& str); 

    MyString& erase(int loc, int num);
    
    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;

    bool operator==(MyString& str); 
    char& operator[](const int index);

private:
    char* string_content;
    int string_length;
    int memory_capacity;
};
MyString::MyString(char c)
{
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
    memory_capacity = 1;
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; ++i) {
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; ++i) {
        string_content[i] = str.string_content[i];
    }
}
MyString::~MyString() {
    delete [] string_content;
}
int MyString::length() const {
    return string_length;
}
int MyString::capacity() const {
    return memory_capacity;
}
void MyString::print() const {
    for (int i = 0; i != string_length; ++i) {
        std::cout << string_content[i];
    }
}
void MyString::println() const {
    for (int i = 0; i != string_length; ++i) {
        std::cout << string_content[i];
    }
    std::cout << std::endl;
}
MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        delete string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }

    for (int i = 0; i < str.string_length; ++i) {
        string_content[i] = str.string_content[i];
    }
    string_length = str.string_length;
    return *this;
}
MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        delete [] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }

    for (int i = 0; i < str_length; ++i) {
        string_content[i] = str[i];
    }

    string_length = str_length;
    return *this;
}
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;
        
        for (int i = 0; i < string_length; ++i) {
            string_content[i] = prev_string_content[i];
        }
        delete [] prev_string_content;
    }
}
char MyString::at(int i) const {
    if (i >= string_length || i < 0) {
        return '\0';
    } else {
        return string_content[i];
    }
}
MyString& MyString::insert(int loc, const MyString& str) {
    if (loc < 0 || loc > string_length) {
        return *this;
    }

    if (string_length + str.string_length > memory_capacity) {
        if (memory_capacity * 2 > string_length + str.string_length) {
            memory_capacity *= 2;
        } else {
            memory_capacity = string_length + str.string_length;
        }

        char* prev_string_content = string_content;

        string_content = new char[memory_capacity];

        int i;
        for (i = 0; i < loc; ++i) {
            string_content[i] = prev_string_content[i];
        }
        
        for (int j = 0; j < str.string_length; ++j) {
            string_content[i + j] = str.string_content[j];
        }

        for ( ; i < string_length; i++) {
            string_content[str.string_length + i] = prev_string_content[i];
        }

        delete [] prev_string_content;

        string_length = string_length + str.string_length;

        return *this;
    }

    for (int i = string_length - 1; i >= loc; i--) {
        string_content[i + str.string_length] = string_content[i];
    }
    for (int i = 0; i < str.string_length; ++i) {
        string_content[i + loc] = str.string_content[i];
    }
    string_length = string_length + str.string_length;
    return *this;
}
MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::myInsert(int loc, const MyString& str) {
    // 기존 삽입이 기존 메모리 용량 안해서 수행될 수 있는 경우에
    // 대한 처리가 빠져 있다. 
    if (loc < 0 || loc > string_length) {
        return *this;
    }

    char* prev_string_content = string_content;
    
    if (string_length + str.string_length > memory_capacity) {
        if (memory_capacity * 2 > string_length + str.string_length) {
            memory_capacity *= 2;
        } else {
            memory_capacity = string_length + str.string_length;
        }
        string_content = new char[ memory_capacity ];
    }
    int j = 0;
    int tmp = 0;
    for (int i = 0; i < string_length + str.string_length; i++) {
        if (i < loc) {
            string_content[i] = prev_string_content[i];
            tmp = i;
        } else if ( i >= loc && i < str.string_length + loc) {
            string_content[i] = str.string_content[j];
            j++;
        } else {
            string_content[i] = prev_string_content[tmp + 1];
            tmp++;
        }
    }
    string_length += str.string_length;
    delete [] prev_string_content;

    return *this;
}

MyString& MyString::erase(int loc, int num) {
    // 지울 문자 개수가 0 이거나
    // 지울 문자의 범위가 0 보다 작거나 문자열 길이를 벗어났거나
    // 지울 문자의 개수가 기존 문자열 길이보다 큰 경우
    // 해당 객체를 리턴하고 함수 종료.
    if (num < 0 || loc < 0 || loc > string_length || num > string_length) {
        return *this;
    }
    char* prev_string_content = string_content;

    for (int i = loc; i < string_length - num; ++i) {
        string_content[i] = prev_string_content[i + num];
    }
    string_length -= num;

    return *this;
}

int MyString::find(int find_from, const MyString& str) const {
    int i, j;
    if (str.string_content == 0) {
        return -1;
    }
    for (i = find_from; i < string_length - str.string_length; ++i) {
        for (j = 0; j < str.string_length; ++j) {
            if (string_content[i + j] != str.string_content[j]) {
                break;
            }
        }
        if (j == str.string_length) {
            return i;
        }
    }
    return -1;
}
int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}
int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}
int MyString::compare(const MyString& str) const {
    // (*this) - (str)을 수행해서 그 1, 0, -1 로 그 결과를 리턴
    // 1 : (*this)가 사전식으로 더 뒤에 온다는 의미
    // 0 : 두 문자열이 같다는 의미
    // -1 : (*this) 가 사전식으로 더 앞에 온다는 의미
    for (int i = 0; i < std::min(string_length, str.string_length); ++i) {
        if (string_content[i] > str.string_content[i]) {
            return 1;
        } else if (string_content[i] < str.string_content[i]) {
            return -1;
        }
    }

    // 만일 여기까지 했는데 끝나지 않았다면 앞 부분까지 모두 똑같은 것
    // 만일 문자열 길이가 모두 같다면 두 문자열은 이에 같은 문자열임
    if (string_length == str.string_length) {
        return 0;
    } else if (string_length > str.string_length){
        return 1;
    }
    return -1;
}
bool MyString::operator==(MyString& str) {
    return !compare(str);
}
char& MyString::operator[](const int index) {
    return string_content[index];
}
int main(int argc, char *argv[])
{
    MyString str("abcdef");
    str[3] = 'c';

    str.println();
    // MyString str1("a word");
    // MyString str2("sentence");
    // MyString str3("sentence");
    //
    // if (str1 == str2) {
    //     std::cout << "str1과 str2는 같다." << std::endl;
    // } else {
    //     std::cout << "str1과 str2는 다르다." << std::endl;
    // }
    //
    // if (str2 == str3) {
    //     std::cout << "str2와 str3은 같다." << std::endl;
    // } else {
    //     std::cout << "str2와 str3은 다르다." << std::endl;
    // }

    // MyString str1("abcdef");
    // MyString str2("abcde");
    //
    // std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
    return 0;
}
