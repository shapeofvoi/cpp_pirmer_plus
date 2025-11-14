#include <cmath>
#include "chapter11.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;
using std::cin;

namespace VECTOR {
    const double Rad_to_deg = 45.0 / atan(1.0); // about 57.296

    void Vector::set_mag() {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang() {
        if (x == 0.0 && y == 0.0) {
            ang = 0.0;
        }
        else
            ang = atan2(y, x);
    }

    void Vector::set_x() {
        x = mag * cos(ang);
    }

    void Vector::set_y() {
        y = mag * sin(ang);
    }

    // public methods
    Vector::Vector() {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    
    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT){
            x = n1;
            y = n2;
            set_ang();
            set_mag();
        }
        else if (form == POL) {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }

    }

    void Vector::reset(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT){
            x = n1;
            y = n2;
            set_ang();
            set_mag();
        }
        else if (form == POL) {
            mag = n1;
            ang = n2;
            set_x();
            set_y();
        }
        else {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector(){

    }

    void Vector::polar_mode(){
        mode = POL;
    }

    void Vector::rect_mode() {
        mode = RECT;
    }

    // 运算符重载
    Vector Vector::operator+(const Vector & b) const {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector & b) const {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const {
        return Vector(n * x, n * y);
    }

    // 友元函数
    Vector operator*(double n, const Vector & a) {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v){
        if (v.mode == Vector::RECT) // 友元函数不算类作用域内
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL){
            os << "(m, a) = (" << v.mag << ", "
                << v.ang * Rad_to_deg << ")"; 
        }
        else
            os << "Vector object mode is invalid";
        return os;
    }

    
    
}

Time::Time() {
    hours = minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h){
    hours += h;
}

void Time::Reset(int h, int m){
    hours = h;
    minutes = m;
}

Time operator+(const Time & t1, const Time & t2){
    Time res;
    res.minutes = t1.minutes + t2.minutes;
    res.hours = t1.hours + t2.hours + res.minutes / 60;
    res.minutes %= 60;
    return res;
}

Time operator-(const Time & t1, const Time & t2) {
    Time res;
    int tol1, tol2;
    tol1 = t1.hours * 60 + t1.minutes;
    tol2 = t2.hours * 60 + t2.minutes;
    res.minutes = (tol1 - tol2) % 60;
    res.hours = (tol1 - tol2) / 60;
    return res;
}

Time operator*(const Time & t, double n) {
    Time res;
    long totalminutes = t.hours * 60 * n + t.minutes * n;
    res.hours = totalminutes / 60;
    res.minutes = totalminutes % 60;
    return res;
}

Time operator*(double n, const Time & t) {
    return t * n;
}

std::ostream & operator<<(std::ostream & os, const Time & t){
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}

Stonewt::Stonewt(double lbs) {
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int (lbs) % Lbs_per_stn + lbs - int (lbs);
    pounds = lbs;
    mode = pounds_double;
}

Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = pounds_double;
}

Stonewt::Stonewt () {
    stone = pounds = pds_left = 0;
    mode = pounds_double;
}

Stonewt::~Stonewt(){

}

Stonewt Stonewt::operator+(const Stonewt & stn) {
    Stonewt res;
    res.pounds = pounds + stn.pounds;
    res.pds_left = (int) res.pounds % Lbs_per_stn;
    res.stone = (int) res.pounds / Lbs_per_stn;

    return res;

}
Stonewt Stonewt::operator-(const Stonewt & stn) {
    Stonewt res;
    res.pounds = pounds - stn.pounds;
    res.pds_left = (int) res.pounds % Lbs_per_stn;
    res.stone = (int) res.pounds / Lbs_per_stn;

    return res;
}

Stonewt Stonewt::operator*(double n) {
    Stonewt res;
    res.pounds = n * pounds;
    res.pds_left = (int) res.pounds % Lbs_per_stn;
    res.stone = (int) res.pounds / Lbs_per_stn;
    
    return res;
}

bool Stonewt::operator>(const Stonewt & stn){
    return pounds > stn.pounds;
}

bool Stonewt::operator<(const Stonewt & stn){
    return pounds < stn.pounds;
}

bool Stonewt::operator==(const Stonewt & stn){
    return pounds == stn.pounds;
}

void Stonewt::set_mode(Mode new_mode) {
    mode = new_mode;
}

Stonewt::operator int() const {
    return int (pounds + 0.5);
}

Stonewt::operator double() const {
    return pounds;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & stn) {
    if (stn.mode == Stonewt::stn_type) {
        os << "Wow! " << stn.stone << " stone, " << stn.pds_left << " pounds\n";
    }
    else if (stn.mode == Stonewt::pounds_int) {
        os << "Wow! " << (int) (stn.pounds + 0.5) << " pounds!(int)" << std::endl;
    }
    else {
        os << "Wow! " << stn.pounds << " pounds!(double)" << std::endl;
    }

    return os;
}

complexx::complexx(): x(0), y(0) {}

complexx::complexx(double a, double b): x(a), y(b) {}

complexx::~complexx(){

}

complexx complexx::operator+(const complexx & c) const {
    return complexx(x + c.x, y + c.y);
}

complexx complexx::operator-(const complexx& c) const {
    return complexx(x - c.x, y - c.y); 
}

complexx complexx::operator*(double n) const {
    return complexx(n * x, n * y);
}

complexx complexx::operator*(const complexx & c) const {
    return complexx(x * c.x - y * c.y, x * c.y + y * c.x);
}

complexx operator*(double n, const complexx & c) { 
    return c * n; 
}

complexx complexx::operator~() const {
    return complexx(x, -y);
}

std::ostream & operator<<(std::ostream & os, const complexx & c) {
    os << "(" << c.x << ", " << c.y << "i)";
    return os;
}

std::istream & operator>>(std::istream & is, complexx & c) {
    cout << "real: ";
    is >> c.x;
    cout << "imaginary: ";
    is >> c.y;

    return is;
}
