#include <iostream>
#include <cstring>
#include "chapter12.h"

// Cow::Cow(): name("warrior"), weight(100) {  数组不能用列表初始化 X
//     hobby = new char[4];
//     hobby = "run"; //  hobby是地址，不能直接这么赋值
//     *hobby = "run"; // *hobby是单个字符，"run"是const char *; 必须先分配内存再strcpy拷贝！！
// }

Cow::Cow(): weight(100) {
    std::strcpy(name, "warrior");
    hobby = new char[4];
    std::strcpy(hobby, "run");
}

Cow::Cow(const char * nm, const char * ho, double wt) {
    std::strcpy(name, nm);
    hobby = new char[std::strlen(ho) + 1];
    std::strcpy(hobby, ho);
    weight = wt;
}

// 显示定义复制构造函数
Cow::Cow(const Cow & c){
    std::strcpy(name, c.name);
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow() {
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c){
    if (this == &c)
        return *this;
    delete [] hobby;
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    std::strcpy(name, c.name);
    weight = c.weight;
    return *this;  // *this是引用
}

void Cow::ShowCow() const {
    std::cout << "The name: " << name << std::endl
        << "The weight: " << weight << std::endl
        << "The hobby: " << hobby << std::endl;
}

/* -------------------String类方法实现--------------------*/
int String::num_strings = 0;  // 类外必须定义一次，只声明不行

String::String(const char * s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    
}

String::String(){
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st) {
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings++;
}

String::~String() {
    delete [] str;
    num_strings--;
}

String & String::operator=(const String & st) {
    if (*this == st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);

    return *this;
}

String & String::operator=(const char * s) {
    len = strlen(s);
    delete [] str;
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

String String::operator+(const String & st) {
    String res;
    res.len = len + st.len;
    res.str = new char[res.len + 1];
    strcpy(res.str, str);
    strcat(res.str, st.str);

    return res;
}

char & String::operator[](int i) {
    return str[i];
}

const char & String::operator[](int i) const {
    return str[i];
}

bool operator<(const String& st, const String& st2) { 
    // strcmp函数按照字母顺序，第一个小于第二个返回-1，相等返回0，大于返回1
    return (strcmp(st.str, st2.str) < 0);  
}

bool operator>(const String & st, const String & st2) {
    return (strcmp(st.str, st2.str) > 0);
}

bool operator==(const String & st, const String & st2) {
    return (strcmp(st.str, st2.str) == 0);
}

String operator+(const String & st, const String & st2) {
    // String res;
    // res = st + st2;
    return st + st2;
}

ostream & operator<<(ostream & os, const String & st) {
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st) {
    // char temp[String::CINLIM];
    // is.get(temp, String::CINLIM);
    // if (is)
    //     st = temp;
    // while(is && is.get() != '\n')
    //     continue;
    // return is;

    char temp[String::CINLIM];
    is.getline(temp, String::CINLIM);  // 直接读取一行
    if (is)
        st = temp;
    return is;

}

int String::HowMany() {
    return num_strings;
}

void String::stringlow() {
    for (int i = 0; i < len; ++i) {
        if (isalpha(static_cast<unsigned char>(str[i])))
            str[i] = std::tolower(static_cast<unsigned char>(str[i]));
    }
}

void String::stringup() {
    for (int i = 0; i < len; ++i) {
        if (isalpha(static_cast<unsigned char>(str[i])))
            str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

int String::has(const char c) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == c)
            count++;
    }
    return count;
}