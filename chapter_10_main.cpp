#include <iostream>
#include "chapter_10.h"

int main(){
    using std::cout;

    cout << "Using constructors to create new objects\n";
    Account A1;
    Account A2("Madolche", "704467551", 999);
    A1.show();
    A2.show();

    A2.save(1);
    
    A2.show();

    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.show();
    std::cout << "\n";
    two.Formalshow();
    std::cout << std::endl;
    three.show();
    std::cout << std::endl;

    std::cout << "The third question:\n";
    Golf G1("Curry", 10);
    G1.show();
    G1.setgolf("Curry", 100);
    G1.show();

    double ar[3] = {4, 6, 8};
    SALES::Sales S1(ar, 3);
    S1.showSales();
    ar[2] = 10;
    S1.setSales(ar, 3);
    S1.showSales();


    return 0;
};
