#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>
class Student {
    private:
        typedef std::valarray<double> ArrayDb;
        std::string name;
        ArrayDb scores;
        std::ostream & arr_out(std::ostream & os) const;

    public:
        Student() : name("Null Student"), scores() {};
        explicit Student(const std::string & s)
            : name(s), scores() {};
        explicit Student(int n) : name("Nully"), scores(n) {};
        Student(const std::string & s, int n) : name(s), scores(n) {};
        Student(const std::string & s, const ArrayDb & a)
            : name(s), scores(a) {};
        Student(const char * str, const double * pd, int n)
            : name(str), scores(pd, n) {};
        ~Student() {};

        double Average() const;
        const std::string & Name() const;
        double & operator[](int i);
        double operator[](int i) const;

        // friends
        friend std::istream & operator>>(std::istream & is, Student & stu);
        friend std::istream & getline(std::istream & is, Student & stu);  // 读取名字的时候获得一整行
        friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};

//==============================类模板==========================
template<class Type>
class Stack {
    private:
        enum {SIZE = 10};  // 栈默认容量
        int stacksize;
        Type* items;  // 指向动态数组的指针，每个元素都是type类型
        int top;  // index for top stack item 指向空位置的索引
        // 初始化为0，表示0位置没有元素 若stacksize = 10,top = 10时，
        // 已经有了0-9，也就是10各元素了

    public:
        explicit Stack(int ss = SIZE);
        Stack(const Stack& st);
        ~Stack() {delete [] items; }
        bool isempty() {
            return top == 0;
        }
        bool isfull() {
            return top == stacksize;
        }
        bool push(const Type& item);
        bool pop(Type& item);
        Stack& operator=(const Stack& st);

};

/*===============pair模板=====================*/
template<class T1, class T2>
class Pair {
    private:
        T1 a;
        T2 b;

    public:
        T1& first();
        T2& second();
        T1 first() const {return a;}
        T2 second() const {return b;}
        Pair(const T1& aval, const T2& bval) : a(aval), b(bval) {}
        Pair() {};
};

template<class T1, class T2>
T1& Pair<T1, T2>::first() {
    return a;
}

template<class T1, class T2>
T2& Pair<T1, T2>::second() {
    return b;
}

#endif