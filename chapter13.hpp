#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

using std::ostream;

class AcctABC {
    private:
        std::string fullname;
        long acctNum;
        double balance;

    protected:
        struct Formatting {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        
};

/*========== Q1 2 =============*/
class Cd {
    private:
        char * performers;
        char * label;
        int selections;
        double playtime;

    public:
        Cd(const char * s1, const char * s2, int n, double x);
        Cd(const Cd & d);
        Cd();
        virtual ~Cd();
        virtual void Report() const;
        virtual Cd & operator=(const Cd & d);
};

class Classic : public Cd {
    private:
        char * primaryWork;

    public:
        Classic();  // 一旦定义了构造函数，则默认构造函数必须自己写，{}也是不可少的（如果不想写定义的话）
        Classic(const char * s1, const char * s2, const char * s3, int n, double x);
        ~Classic();
        void Report() const;
        Classic & operator=(const Classic & cl);
    
};

/*============== Q3 =================*/
class ABC {
    private:
        char * label;
        int rating;

    public:
        ABC(const char * l = "null", int r = 0);
        ABC(const ABC & rs);
        virtual ~ABC();
        virtual ABC & operator=(const ABC & ro);
        virtual void view() const = 0;
};

class baseDMA : public ABC {
    private:
        int year;

    public:
        baseDMA(int y = 18, const char * l = "null", int r = 0);
        baseDMA(int y, const ABC & ro);
        ~baseDMA() {};
        // baseDMA & operator=(const baseDMA & base);
        void view() const;
        
};

class lackDMA : public ABC {
    private:
        enum { COL_LEN = 40 };
        char color[COL_LEN];

    public:
        lackDMA(const char * c = "blank", const char * l = "null", int r = 0);
        lackDMA(const char * c, const ABC & ro);
        // 没有动态分配内存的话，默认的复制构造函数就可以了，会执行成员复制
        ~lackDMA() {};
        void view() const ;
};

class hasDMA : public ABC {
    private:
        char * style;

    public:
        // 动态分配内存必须重写 析构、复构、赋值运算符
        hasDMA(const char * s = "none", const char * l = "null", int r = 0);
        hasDMA(const char * s, const ABC & ro);
        hasDMA(const hasDMA & hs);
        ~hasDMA();
        hasDMA & operator=(const hasDMA & hs);
        void view() const;
};


/*======================= Q4 ==========================*/
class Port {
    private:
        char * brand;
        char style[20];  // i.e.,tawny, ruby, vintage
        int bottles;

    public:
        Port(const char * br = "none", const char * st = "none", int b = 0);
        Port(const Port & p);
        virtual ~Port() { delete [] brand; }
        Port & operator=(const Port & p);
        Port & operator+=(int b);  // add b to bottles
        Port & operator-=(int b);  // substracts b from bottles, if available
        int BottleCount() const { return bottles; }
        virtual void Show() const;
        friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port {
    private:
        char * nickname; // i.e.,"The Noble" or "Old Velvet", etc.
        int year; // vintage year

    public:
        VintagePort();
        VintagePort(const char * br, int b, const char * nn, int y);
        VintagePort(const VintagePort & vp);
        ~VintagePort() { delete [] nickname ;}
        VintagePort & operator=(const VintagePort & vp);
        void Show() const;
        friend ostream & operator<<(ostream & os, const VintagePort & vp);
};


/*
b.第二个任务是解释为什么有的方法重新定义了，而有些没有重新定义
构造函数不会被继承，也不能被重写；派生类需要定义自己的构造函数；

析构函数需要重新定义，因为派生类进行了动态内存分配，析构函数需要进行清理工作；

派生类需要自己的赋值运算符，因为需要深拷贝；有自己的动态内存分配；

Show()函数为虚函数，派生类多了一些成员需要展示，因此需要重新定义；

友元函数不是成员函数，不能声明为虚函数；
每个类都需要自己的operator<<重载，因为要输出的成员不同，函数签名也不一样；
*/

#endif

/*
8. 可以将派生类对象的地址赋给基类指针吗？可以将基类对象的地址赋给派生类指针吗？
    前者可以，后者不可以；
    前者为上行转换，只能访问其中的基类部分；
    后者为下行转换，不行，因为派生类有基类没有的成员；

9.可以将派生类对象赋给基类对象吗？可以将基类对象赋给派生类指针吗？
    Q1；可以将派生类对象赋给基类对象，但这只涉及基类的成员；
        Brass::opeator=(const Brass &) Brass引用可以指向派生类对象，因此该赋值运算符可以直接调用；
    Q2；如果派生类包含了将基类对象转换成派生类对象的定义，例如 BrassPlus (const Brass & ba);
        或者派生类定义了用于将基类对象赋给派生对象的赋值运算符，也可以；
        BrassPlus & BarssPlus::operator=(const Brass & ba)

10.假设定义了一个函数，它将基类对象的引用作为参数。为什么该函数也可以将派生类对象作为参数？
    因为基类对象的引用可以绑定到派生类对象的“基类子对象部分”，这是合法的上行转换。

11.假设定义了一个函数，它将基类对象作为参数（即函数按值传递基类对象）。为什么该函数也可以将派生类对象作为参数？
    按值传递基类对象时，实参要通过复制构造函数构造出一个基类的临时对象。
    派生类对象可以向上转换为基类对象，因此可以作为实参，但派生类的扩展部分会被切掉，
    只复制基类部分，这称为对象切片（object slicing）。

12.为什么通常按引用传递对象比按值传递对象的效率更高？
    按引用传递不需要复制对象，因此不需要调用复制构造函数和析构函数，节省了时间和内存开销。
    同时按引用传递还能避免对象切片，并保留多态特性。因此通常比按值传递更高效。

13.假设Corporation是基类，PublicCorporation是派生类。再假设这两个类都定义了head()函数，
    ph是指向Corporation类型的指针，且被赋给了一个PublicCorporation对象的地址。如果基类将head()定义为：
    a.常规非虚方法；
    b.虚方法；
    则ph->head()将被如何解释？
    a:若head()为常规非虚方法，则按指针类型解释，则解释为Corporation::head();
        这是静态多态/隐藏
    b:若为虚，则按对象解释，PublicCorporation::head();
        动态绑定/运行期多态

14.下述代码有什么问题？
class Kitchen {
    private:
        double kit_sq_ft;

    public:
        Kitchen() {kit_sq_ft = 0.0; }
        virtual double area() const { return kit_sq_ft * kit_sq_ft; }

};

class House : public Kitchen {
    private:
        double all_sq_ft;
    public:
        House() { all_sq_ft += kit_sq_ft; }
        double area(const char * s) const {cout << s; return all_sq_ft; }
};
    派生类默认构造函数有问题，不能访问基类私有成员，all_sq_ft没有初始值；

    派生类的area()方法的参数列表和基类不同，这不是override，而是隐藏了；
    派生类构造函数最好写成：
    House() : Kitchen(), all_sq_ft(0) {};

    派生类隐藏基类的函数后，基类版本仍然存在，
    但不能通过派生类对象的“派生类身份”直接调用，只能通过基类身份或作用域解析来访问。

*/