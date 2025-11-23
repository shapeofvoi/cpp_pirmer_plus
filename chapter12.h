#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include <cctype>


// typedef int Item;
// typedef unsigned long Item;
using std::ostream;
using std::cin;
using std::cout;
using std::istream;
using std::endl;

class Customer {
    private:
        long arrive;
        int processtime;

    public:
        Customer() {arrive = processtime = 0; }
        void set (long when);
        long when() const {return arrive; }
        int ptime() const {return processtime; }
};

typedef Customer Item;
class Queue {
    private:
        struct Node {Item item; struct Node * next;};
        enum {Q_SIZE = 10};

        Node * front;
        Node * rear;
        int items;
        const int qsize;

        // 写在私有方法是为了禁止复制、赋值！！ 妙
        Queue(const Queue & q): qsize(0) {};
        Queue & operator=(const Queue & q) {return *this;}

    public:
        Queue(int qs = Q_SIZE);
        ~Queue();
        bool isempty() const;
        bool isfull() const;
        int queuecount() const;
        bool enqueue(const Item & item);  // add item to end
        bool dequeue(Item & item);  // remove item from front
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

class Stock {
    private:
        char * company;
        int len;
        int shares;
        double share_val;
        double total_val;
        void set_tot() {total_val = shares * share_val; }

    public:
        Stock();
        Stock(const char * co, long n = 0, double pr = 0.0);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        const Stock & topval(const Stock & s) const;

        friend ostream & operator<<(ostream & os, const Stock & sto);
};


class Stack{
    private: 
        enum {MAX = 10};
        Item * pitems;
        int size;
        int top;  // index for top stack item
    
    public:
        Stack(int n = MAX);
        Stack(const Stack & st);
        ~Stack();

        bool isempty() const;
        bool isfull() const;
        bool push(const Item & item);
        bool pop(Item & Item);
        Stack & operator=(const Stack & st);
};




#endif