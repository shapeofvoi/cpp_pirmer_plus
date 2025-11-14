#include <iostream>
#include "chapter_10.h"

void add (item & x) {
    x += 1;
}

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

    Stack cus;
    Item cus1 {"Madolche", 100};
    cus.push(cus1);
    cus.pop(cus1);

    // 6th
    std::cout << std::endl;
    Move m1(3, 4);
    Move m2(4, 3);
    m1.showmove();
    auto m3 = m1.add(m2);
    m3.showmove();

    Plorg P1(8);
    P1.showPlorg();
    P1.setCI(10);
    P1.showPlorg();
    Plorg P2(100, 8, "Madolche");
    P2.showPlorg();

    List l1;
    l1.push_back(3);
    l1.visit(add);
    l1.showList();
    l1.push_back(6);
    l1.showList();




    return 0;
};
