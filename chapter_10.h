#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>

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

#endif