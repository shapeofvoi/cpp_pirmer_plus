#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR{
    class Vector{
        public:
            enum Mode {RECT, POL};

        private:
            double x;
            double y;
            double mag;
            double ang;
            Mode mode;
            void set_mag();
            void set_ang();
            void set_x();
            void set_y();

        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void reset(double n1, double n2, Mode form = RECT);
            ~Vector();
            double xval() const {return x;}
            double yval() const {return y;}
            double magval() const {return mag;}
            double angval() const {return ang;}
            void polar_mode();
            void rect_mode();

            // opetrating overloading
            Vector operator+(const Vector & b) const;
            Vector operator-(const Vector & b) const;
            Vector operator-() const;
            Vector operator*(double n) const;

            friend Vector operator*(double n, const Vector & a);
            friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}

class Time {
    private:
        int hours;
        int minutes;

    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        
        friend Time operator+(const Time & t1, const Time & t2);
        friend Time operator-(const Time & t1, const Time & t2);
        friend Time operator*(const Time & t, double n);
        friend Time operator*(double m, const Time & t);
        friend std::ostream & operator<< (std::ostream & os, const Time & t);
};

class Stonewt {
    public:
        enum Mode {stn_type, pounds_int, pounds_double};

    private:
        enum {Lbs_per_stn = 14};
        int stone;
        Mode mode;
        double pds_left;
        double pounds;

    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        Stonewt operator+(const Stonewt & stn);
        Stonewt operator-(const Stonewt & stn);
        Stonewt operator*(double n);
        bool operator>(const Stonewt & stn);
        bool operator<(const Stonewt & stn);
        bool operator==(const Stonewt & stn);
        void set_mode(Mode new_mode);
        operator int() const;
        operator double() const;
        
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & stn);

};

class complexx {
    private:
        double x;
        double y;

    public:
        complexx();
        complexx(double a, double b);
        ~complexx();

        complexx operator+(const complexx & c) const;
        complexx operator-(const complexx & c) const;
        complexx operator*(double n) const;
        complexx operator*(const complexx & c) const;
        complexx operator~() const;

        friend complexx operator*(double n, const complexx & c);
        friend std::ostream & operator<<(std::ostream & os, const complexx & c);
        friend std::istream & operator>>(std::istream & is, complexx & c);
};

#endif