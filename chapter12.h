#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include <cctype>

typedef int Item;
using std::ostream;
using std::cin;
using std::cout;
using std::istream;

class Queue {
    private:
        struct Node {Item item; struct Node * next;};
        enum {Q_SIZE = 10};

        Node * front;
        Node * rear;
        int items;
        const int qsize;

    public:
        Queue(): qsize(0), front(nullptr), rear(nullptr) {};
};

class Cow {
    private:
        char name[20];
        char * hobby;
        double weight;

    public:
        Cow();
        Cow(const char * nm, const char * ho, double wt);
        Cow(const Cow & c);
        ~Cow();
        Cow & operator=(const Cow & c);
        void ShowCow() const;
};

class String {
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;

    public:
        String(const char * s);
        String();
        String(const String &);
        ~String();
        int length() const {return len; }

        // overloaded operator
        String & operator=(const String &);
        String & operator=(const char *);
        String operator+(const String & st);
        char & operator[](int i);
        const char & operator[](int i) const;  // 适用于常量对象

        // overloaded operator friends
        friend bool operator<(const String & st, const String & st2);
        friend bool operator>(const String & st, const String & st2);
        friend bool operator==(const String & st, const String & st2);
        friend String operator+(const String & st, const String & st2);
        friend ostream & operator<<(ostream & os, const String & st);
        friend istream & operator>>(istream & is, String & st);

        static int HowMany();
        void stringlow();
        void stringup();
        int has(const char c);


};

#endif