#include <iostream>
#include <cstring>
#include "chapter13.hpp"

// using std::strcpy;
using std::cout;
using std::endl;
using std::cin;

Cd::Cd(const char * s1, const char * s2, int n, double x) 
    : selections(n), playtime(x) {
        // const char * 不能用于初始化字符串数组
    performers = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
    strcpy(performers, s1);
    strcpy(label, s2);
}

Cd::Cd(const Cd & d) {
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd() : selections(0), playtime(1.0) {
    // performers = nullptr;  //??? 需要写成 new char[]吗 写成这样cout的时候未定义行为
    // // 这样写 delete [] performers是安全的
    // label = nullptr;
    performers = new char[1] {'\0'};
    label = new char[1] {'\0'};

}

Cd::~Cd() {
    delete [] performers;
    delete [] label;
}

void Cd::Report() const {
    cout << "The performers: " << performers << endl
         << "The label: " << label << endl
         << "The selections: " << selections << ", playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d) return *this;

    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime; 

    return *this;
}

Classic::Classic() : Cd() {
    primaryWork = new char[1] {'\0'};
    // strcpy(primaryWork, "\0");  不能这样写
}

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x)
    : Cd(s2, s3, n, x) {
    primaryWork = new char[strlen(s1) + 1];
    strcpy(primaryWork, s1);
} 

void Classic::Report() const {
    cout << "The primary work: " << primaryWork << endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & cl) {
    if (this == & cl) return *this;

    Cd::operator=(cl);
    delete [] primaryWork;
    primaryWork = new char[strlen(cl.primaryWork) + 1];
    strcpy(primaryWork, cl.primaryWork);
    
    return *this;
}

Classic::~Classic() {
    delete [] primaryWork;
}

/*================================ Q3 =============================*/
ABC::ABC(const char * l, int r) {
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

ABC::ABC(const ABC & rs) {
    label = new char[strlen(rs.label) + 1];
    strcpy(label, rs.label);
    rating = rs.rating;
}

ABC::~ABC() {
    delete [] label;
}

ABC & ABC::operator=(const ABC & ro) {
    if (this == & ro)
        return *this;
    
    delete [] label;
    label = new char[strlen(ro.label) + 1];
    strcpy(label, ro.label);
    rating = ro.rating;

    return *this;
}

void ABC::view() const {
    cout << "The label is: " << label << endl
         << "   the rating is: " << rating << endl;
}

baseDMA::baseDMA(int y, const char * l, int r) : ABC(l, r) {
    year = y;
}

baseDMA::baseDMA(int y, const ABC & ro) : ABC(ro) {
    year = y;
}

void baseDMA::view() const {
    cout << "The year is: " << year << endl;
    ABC::view();
}

lackDMA::lackDMA(const char * c, const char * l, int r) : ABC(l, r) {
    strcpy(color, c);
}

lackDMA::lackDMA(const char * c, const ABC & ro) : ABC(ro) {
    strcpy(color, c);
}

void lackDMA::view() const {
    cout << "The color is: " << color << endl;
    ABC::view();
}

hasDMA::hasDMA(const char * s, const char * l, int r) : ABC(l, r) {
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const ABC & ro) : ABC(ro){
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) : ABC(hs){
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    // ABC(hs) 不能这么写，因为ABC是抽象基类，但是可以列表初始化!!
}

hasDMA::~hasDMA() {
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs) {
    if (this == & hs)
        return *this;

    delete [] style;
    style = new char[strlen(hs.style) + 1];
    strcpy(style, hs.style);
    ABC::operator=(hs);

    return *this;
}

void hasDMA::view() const {
    cout << "The style is: " << style << endl;
    ABC::view();
}

/* ====================== Q4 ======================*/
Port::Port(const char * br, const char * st, int b) {
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p) {
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p) {
    if (this == &p)
        return *this;

    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;

    return *this;
}

Port & Port::operator+=(int b) {
    bottles = bottles + b;
    return *this;
}

Port & Port::operator-=(int b) {
    bottles = bottles - b;
    return *this;
}

void Port::Show() const {
    cout << "Brand: " << brand << endl
         << "Kind: " << style << endl
         << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort() : Port("none", "vintage", 0), year(0) {
    nickname = new char[10];
    strcpy(nickname, "The Noble");
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
    : Port(br, "vintage", b) {
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp){
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp) {
    if (this == &vp) 
        return *this;

    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;

    return *this;
}

void VintagePort::Show() const {
    Port::Show();
    cout << "nickname: " << nickname << endl
         << "year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp) {
    os << static_cast<const Port &>(vp) << ", " << vp.nickname <<", " << vp.year;

    return os;
}