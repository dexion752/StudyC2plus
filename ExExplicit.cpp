#include <iostream>

class MyString
{
public:
    explicit MyString (int capacity);
    MyString (const char* str);
    MyString (const MyString& str);
    ~MyString ();

    int length() const;
    int capacity() const;

private:
    char* string_content;
    int string_length;

    int memory_capacity;
};
MyString::MyString (int capacity){
    string_content = new char[capacity];
    string_length = 0;

    memory_capacity = capacity;
}

MyString::MyString (const char* str){
    string_length = 0;
    while (str[string_length++]) {
        
    }

    string_content = new char[string_length];
    memory_capacity = string_length;

    for (int i = 0; i < string_length; ++i) {
        string_content[i] = str[i];
    }
}

MyString::MyString (const MyString& str){
    string_length = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i < string_length; ++i) {
        string_content[i] = str.string_content[i];
    }
}
MyString::~MyString () {
    delete[] string_content;
}
int MyString::length() const {
    return string_length;
}
int MyString::capacity() const {
    return memory_capacity;
}

void DoSomethingWithString(MyString s) {
    
}

int main(int argc, char *argv[])
{
    MyString s = "abc";
    MyString s = 5;

    // DoSomethingWithString(3);

    // MyString s(3);
    // std::cout << "Capacity : " << s.capacity() << std::endl;
    return 0;
}
