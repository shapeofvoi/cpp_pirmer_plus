#include <iostream>
#include "chapter12.h"
// #define _CRT_SECURE_NO_WARNINGS
#include <cstring>

/*
int main() {
    // Cow c1;
    // Cow c2("Bull", "Jump", 120);
    // Cow c3;

    // c1.ShowCow();
    // c2.ShowCow();
    // c3.ShowCow();
    // c3 = c2;
    // c3.ShowCow();

    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;
    cin >> s3;
    s2 = String("My name is ") + s3; // 
    // s2 = s3 + "My name is "; // 这种情况会隐式转换
    // s2 = "My name is " + s3; 
    // 编译器不会自动把"My name is "转换成String类型，因为因为这种 隐式转换不适用于非成员函数的第一个参数
    // 就是说 const char* + String 没有匹配的 operator+
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
        << " 'A' characters in it.\n";
    s1 = "red";
    String rgb[3] = {String(s1), String("green"), String("blue")};
    cout << "Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while(cin >> ans) {
        ans.stringlow();
        for (int i= 0; i < 3; i++) {
            if (ans ==  rgb[i]) {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            cout << "Try again!\n";
    }

    cout << "Bye\n";
    return 0;
}
*/

/*
const int STKS = 4;
int main() {
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    cout << "Stock holdings:\n";
    int st;
    for(st = 0; st < STKS; st++) {
        cout << stocks[st] << std::endl;
    }

    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++) {
        top = &top->topval(stocks[st]);
    }
    cout << "\nMost valuable holding:\n" << *top;

    return 0;
}
*/

// int main() {
//     Stack stk1(5);
//     stk1.push(1);
//     stk1.push(2);
//     stk1.push(3);
//     Item x;
//     stk1.pop(x);
//     cout << "The stk1's top is: " << x << std::endl;

//     Stack stk2;
//     stk2 = Stack(stk1);
//     stk2.pop(x);
//     cout << "The stk2's top is: " << x << std::endl;
    
//     Stack stk3;
//     stk3 = stk2;
//     stk2.pop(x);
//     cout << "The stk3's top is: " << x << std::endl;

//     return 0;

// }


#include <ctime>
#include <cstdlib>
const int MIN_PER_HR = 60;

bool newcustomer(double x) {
    return (std::rand() * x / RAND_MAX < 1);
}

int main() {
    std::srand(std::time(0));
    using std::ios_base;

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs);
    Queue line2(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour;  // 每小时到达客人人数
    cin >> perhour;
    double min_per_cust;  // 每个客人平均等待时间，通过下式计算
    min_per_cust = MIN_PER_HR / perhour; 
    
    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time1 = 0;
    int wait_time2 = 0;
    long line_wait = 0;

    // running the simulation
    for (int cycle = 0; cycle < cyclelimit; ++cycle) {
        // 接下来处理每过一分钟，各种变化
        if (newcustomer(min_per_cust)){
            customers++;
            if (line1.isfull() && line2.isfull()){
                turnaways++;
            }
            else {
                temp.set(cycle);
                if (line1.queuecount() < line2.queuecount()){
                    line1.enqueue(temp);
                }
                else {
                    line2.enqueue(temp);
                }
            }
        }
        if (wait_time1 <= 0 && !line1.isempty()) {
            line1.dequeue(temp);
            wait_time1 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time2 <= 0 && !line2.isempty()) {
            line2.dequeue(temp);
            wait_time2 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0) wait_time1--;
        if (wait_time2 > 0) wait_time2--;
        sum_line += (long) ((line1.queuecount() + line2.queuecount()) / 2); 
        // 统计每分钟队伍的长度，以求平均长度
    }

    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << " turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: " <<(double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

