#include <iostream>

class string
{
public:
    string(char c, int n);     // 문자 c 가 n 개 있는 문자열로 정의
    string(const char *s);
    string(const string& s);
    ~string();


    void add_string(const string& s);       // str 뒤에 s를 붙인다.
    void copy_string(const string &s);      // str 에 s를 복사한다.
    int strlen(const char* s);                           // 문자열 길이 리턴
    void show_status();

private:
    int len;
    char *str;
};

void string::copy_string(const string& s)
{
    len = s.len;
    str = new char [len + 1];
    for (int i = 0; i < len; ++i) {
        str[i] = s.str[i];
    }
    str[len] = '\0';
}

void string::add_string(const string& s)
{
    // std::cout << "기존 문자열 : " << str << std::endl;
    // std::cout << "추가 문자열 : " << s.str << std::endl;
    int j = 0;
    int len_sum = len + s.len;
    char *tmp = new char[len];
    for (int i = 0; i < len; ++i) {
        tmp[i] = str[i];
    }

    delete [] str;
    str = new char[len_sum + 1];

    // std::cout << "기존 문자열 : " << tmp << std::endl;
    for (int i = 0; i < len; ++i) {
        str[i] = tmp[i] ;
    }
   
    for (int i = len; i < len_sum; ++i) {
       // std::cout << s.str] << std::endl;
       str[i] = s.str[j];
       j++;
    }
    // std::cout << "결합 문자열 : " << str << std::endl;
    // std::cout << str << std::endl;
    str[len_sum] = '\0';
    // str = tmp;
    delete [] tmp;
    len = len_sum;
}

string::string(char c, int n)
{
    len = n;
    str = new char[len + 1];
    for (int i = 0; i < len; ++i) {
       str[i] = c; 
    } 
    str[len] = '\0';
}

string::string(const char *s)
{
    len = strlen(s);
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s[i];
    }

    str[len] = '\0';
}

string::string(const string& s)
{
    len = s.len;
    str = new char[len + 1];
    for (int i = 0; i < len; ++i) {
       str[i] = s.str[i];
    }
    str[len] = '\0';
}

string::~string()
{
    if (str) {
       delete [] str; 
    }
}
void string::show_status()
{
    std::cout << str << std::endl;
    std::cout << len << std::endl;
}
int string::strlen(const char *s)
{   
    static int len = 0;
    while (*s) {
       len++; 
       s++;
    }
    return len;
}

int main(int argc, char *argv[])
{
    string s1('x', 3);
    string s2('a', 6);
    string s3("abcdefg");
    string s4(s3);

    s1.show_status();
    s2.show_status();
    s3.show_status();
    s4.show_status();

    std::cout << "----------------" <<std::endl;
    s3.add_string(s1);
    s3.show_status();
    std::cout << "----------------" <<std::endl;
    s3.copy_string(s4);
    s3.show_status();

    return 0;
}
