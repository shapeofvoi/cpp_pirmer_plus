#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>
#include <cstring>

class Account {
    private:
    std::string name;
    std::string account;
    double deposit;

    public:
    Account();
    Account(const std::string& name, std::string Account = "", double deposit = 0.0);
    void show() const;
    void save(double price);
    void extract(double price);
    
};

class Person {
    private:
    static const int LIMIT = 25;
    std::string lname;
    char fname[LIMIT];

    public:
    Person() {lname = ""; fname[0] = '\0';}
    Person(const std::string & ln, const char * fn = "Heyyou");
    void show() const;
    void Formalshow() const;
};


class Golf
{
    // const int Len = 40;
    private:
    std::string fullname;
    int handicap;

    public:
    Golf();
    Golf(const std::string & name, const int & hc);
    void setgolf(const std::string & n_name, const int & n_hc);
    void show();
};

namespace SALES{
    const int QUARTERS = 4;
    class Sales{
        private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;

        public:
        Sales(const double ar[], int n);
        void setSales(const double ar[], int n);
        void showSales();

    };
}

// 5th
struct customer {
    char fullname[35];
    double payment;
};

typedef customer Item;
class Stack{
    private: 
        enum {MAX = 10};
        Item items[MAX];
        int top;
        double deleted_payment_total;
    
    public:
        Stack();
        bool isempty() const;
        bool isfull() const;
        bool push(const Item & item);
        bool pop(Item & Item);
};

class Move {
    private:
        double x;
        double y;
    
    public:
        Move(double a = 0, double b = 0);
        void showmove() const;
        Move add(const Move & m) const;
        void reset (double a= 0, double b = 0);
};

// 7th
class Plorg {
    private:
        static const int len = 19;  // static 表示这是类共享常量（所有对象用一个）
        char name[len + 1];
        int CI;

    public:
        Plorg(const int & ci, const int ln = 6, const char * na = "Plorga");
        void setCI(const int & ci);
        void showPlorg();


};

// 8th
typedef int item;
class List{
    private:
        enum {MAX = 100};
        item array[MAX];
        int len = 0;
     
    public:
        // List();
        void push_back(const item & x);
        bool isempty();
        bool isfull();
        void visit(void (*pf) (item & x));
        void showList();
};

#endif