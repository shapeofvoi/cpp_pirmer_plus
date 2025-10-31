#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/* P1 */
/*
void showStr(const string & str, int n = 1);

int main(){
    string s = "Hello, C++ primer plus";
    showStr(s);

    showStr(s, 3);
    return 0;
}

void showStr(const string & str, int n){
    for (int i = 0; i < n; i++){
        cout << str << endl;
    }
}
*/

/* P2 */
/*
struct CandyBar {
    char name[20];
    double weight;
    int calor;
};
void setCandyBar(CandyBar & C, const char name[] = "Millennium Munch",   // 字符串常量是只读的，因此需要用const char
                double weight = 2.85, int calor = 350);
void showCandyBar(const CandyBar & C);
int main(){
    CandyBar C;
    setCandyBar(C);
    showCandyBar(C);
}
void setCandyBar(CandyBar & C, const char name[], double weight, int calor){
    // strcpy(C.name, name);
    // strcpy(dest, src) 的参数类型是 const char* src，完全兼容。
    int i = 0;  
    while(*name != '\0'){
        C.name[i++] = *name++;
    }
    C.name[i] = '\0';
    C.weight = weight;
    C.calor = calor;
}
void showCandyBar(const CandyBar & C){
    cout << "Name: " << C.name << endl;
    cout << "Weight: " << C.weight << endl;
    cout << "Calories: " << C.calor << endl;
}
*/

/* P3 */
/*
string & str_upper(string & str);
int main(){
    string str;
    cout << "Enter a string (q to quit):";

    while(true){
        getline(cin, str);  // getline(cin, string)才是string对象的方法
        if (str == "q") break;
        cout << str_upper(str) << endl;
        cout << "Next string (q to quit):";
    }
    return 0;
}


string & str_upper(string & str){
    for (auto & c:str)
        c = toupper(c);  // toupper不是原地修改，需要赋值
    return str;
}
*/

/* P4 */
/*
struct stringy {
    char * str;  
    int ct;  // 记录string的长度，不包括'\0'
};

void set(stringy & s, const string & str);
void show(const stringy & s, int n = 1);
void show(const string & str, int n = 1);

int main(){
    stringy beany;
    string testing = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing = "This is a test.";
    show(testing);
    show(testing, 3);
    delete[] beany.str;  //释放内存
    return 0;
}

void set(stringy & s, const string & str){
    // delete[] s.str;
    s.ct = str.size();
    s.str = new char[s.ct + 1];  // 必须为str里面的'\0'分配空间，所以+1

    strcpy(s.str, str.c_str());
}
void show(const stringy & s, int n){
    for (int i = 0; i < n; i++){
        cout << s.str << endl;
    }
}
void show(const string & str, int n){
    for (int i = 0; i < n; i++){
        cout << str << endl;
    }
}
*/

template <typename T> 
T max5(T arr[]);

template <typename T>
T maxN(T arr[], int n);

template <> const char* maxN(const char * arr[], int n);

int main(){
    int arr1[] = {1, 5, 2, 3, 9, 10};
    double arr2[] = {2.0, 3.5, 5.4, 9.6};
    cout << maxN(arr1, 4) << endl;
    cout << maxN(arr2, 6) << endl;

    const char* arr_char[] = {"Hello", "world!", "C++ primer plus", "Hello world!!!"};  // 字符串常量用const char*
    // 可以让arr_char[0]指向别的字符串常量，但是不能改变"Hello"的内容
    // char * arr = "Hello" 会退化为 const char * arr = "Hello",所以"Hello"是只读的
    // char arr[] = "Hello" 其中arr[0]可以进行修改
    // char arr[][] 是真·二维数组，数据连续、内容可改；
    // const char* arr[] 是“指针数组”，每个元素指向不同字符串，可以改指针，不可改内容。
    
    cout << maxN(arr_char, 4) << endl;
    return 0;
}

template <typename T> T max5(T arr[]){
    T res = arr[0];
    for (int i = 1; i < 5; i++){
        res = arr[i] > res ? arr[i] : res;
    }
    return res;
}

template <typename T>
T maxN(T arr[], int n){
        T res = arr[0];
    for (int i = 1; i < n; i++){
        res = arr[i] > res ? arr[i] : res;
    }
    return res;
}

template <> const char* maxN(const char * arr[], int n){
    const char* res = arr[0];
    for (int i = 1; i < n; i++){
        int len = strlen(arr[i]);
        res = strlen(res) < len ? arr[i] : res;
    }
    return res;
}
