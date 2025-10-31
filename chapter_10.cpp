#include <iostream>
#include "chapter_10.h"

Account::Account(){
    std::cout << "Default constructor called\n";
    name = "";
    account = "";
    deposit = 0.0;
}
Account::Account(const std::string & na, std::string acc, double depos){  // 初始化字符串，其类型为const char[]
    // 则必须用const才可以； 即 “临时对象（右值）不能绑定到非 const 引用”
    std::cout << "Constructor using " << na << " called\n";
    name = na;
    account = acc;
    if (depos < 0){
        std::cout << "The deposit can't be nagetive;";
        deposit = 0;
    }
    else{
        deposit = depos;
    }

}

void Account::show() const{
    using std::cout;
    using std::ios_base;

    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    
    cout << "Accout name: " << name
        << "accout: " << account
        << "Deposit: " << deposit << std::endl;
    cout.precision(2);

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

void Account::save(double price){
    deposit += price;
}

void Account::extract(double price){
    deposit -= price;
}

Person::Person(const std::string & ln, const char * fn){
    lname = ln;
    std::strncpy(fname, fn, sizeof(fname));  // 传统C风格字符需要手动字符串拷贝和结尾'\0'
    fname[sizeof(fname) - 1] = '\0';
}

void Person::show() const {
    std::cout << "The full name is: " << fname
        << " " << lname << std::endl;
}

void Person::Formalshow() const{
    std::cout << "The full name is: " << lname << ", " << fname << std::endl;
}

Golf::Golf(const std::string & na, const int & hc){
    fullname = na;
    handicap = hc;
}

void Golf::setgolf(const std::string & na, const int & hc){
    Golf temp(na, hc);
    *this = temp;
    // return *this;
}

void Golf::show(){
    std::cout << "The fullname is: " << fullname << std::endl
    << "The handicap is: " << handicap << std::endl;
}

SALES::Sales::Sales(const double ar[], int n){
    auto max_temp = ar[0], min_temp = ar[0];
    double sum = 0;
    for (int i = 0; i < n; i++){
        sales[i] = ar[i];
        if (ar[i] > max_temp) max_temp = ar[i];
        if (ar[i] < min_temp) min_temp = ar[i];
        sum += ar[i];
    }
    max = max_temp;
    min = min_temp;
    average = sum / n;
}

void SALES::Sales::setSales(const double ar[], int n){
    Sales o_temp(ar, n);
    *this = o_temp;
}

void SALES::Sales::showSales(){
    std::cout << "The max is: " << max << std::endl
        << "The min is: " << min << std::endl
        << "The average of array is: " << average << std::endl;
}