#include <iostream>
#include "chapter12.h"
// #define _CRT_SECURE_NO_WARNINGS
#include <cstring>

int main() {
    // Cow c1;
    // Cow c2("Bull", "Jump", 120);
    // Cow c3;

    // c1.ShowCow();
    // c2.ShowCow();
    // c3.ShowCow();
    // c3 = c2;
    // c3.ShowCow();

    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;
    cin >> s3;
    s2 = String("My name is ") + s3; // 
    // s2 = s3 + "My name is "; // 这种情况会隐式转换
    // s2 = "My name is " + s3; 
    // 编译器不会自动把"My name is "转换成String类型，因为因为这种 隐式转换不适用于非成员函数的第一个参数
    // 就是说 const char* + String 没有匹配的 operator+
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
        << " 'A' characters in it.\n";
    s1 = "red";
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while(cin >> ans) {
        ans.stringlow();
        for (int i= 0; i < 3; i++) {
            if (ans ==  rgb[i]) {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }

    cout << "Bye\n";
    return 0;
}