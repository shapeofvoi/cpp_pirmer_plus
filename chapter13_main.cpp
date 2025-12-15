#include <iostream>
// #include <cstring>
#include "chapter13.hpp"
using std::string;
using std::cin;
using std::cout;
using std::endl;

// void Bravo(const Cd & disk);

/*
int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic(
        "Piano Sonata in B flat, Fantasia in C", 
        "Alfred Brendel", "Philips", 2, 57.17
    );
    Cd * pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report(); //use Cd method
    c2.Report(); //use Classic method

    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object

    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Tesing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;

}

void Bravo(const Cd & disk) {
    disk.Report();
}
*/

/*
const int CLIENTS = 4;
int main() {
    ABC * p_clients[CLIENTS];
    char temp_label[20];
    long temp_rating;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++) {
        cout << "Enter client's label: ";
        cin.getline(temp_label, 20);
        cout << "Enter client's rating: ";
        cin >> temp_rating;  // cin 不会清理换行符, getline会读到换行符
        cout << "Enter 1 for baseDMA or "
        << "2 for lackDMA " 
        << "3 for hasDMA" << endl;
        while( cin >> kind && (kind != '1' && kind != '2' && kind != '3')) {
            cout << "Enter 1, 2 or 3: ";
        }
        if (kind == '1') {
            int temp_year;
            cout << "Please enter the year of client: ";
            cin >> temp_year;
            cin.ignore(100, '\n');  // 去除留下的换行符，为下一次输入做准备
            p_clients[i] = new baseDMA(temp_year, temp_label, temp_rating);
        }
        else if (kind == '2'){
            cout << "Enter the color of client: ";
            cin.ignore(1000, '\n');
            char temp_color[40];
            cin.getline(temp_color, 40);
            p_clients[i] = new lackDMA(temp_color, temp_label, temp_rating);
        }
        else {
            cout << "Enter the style of client: ";
            cin.ignore(1000, '\n');
            char temp_style[20];
            cin.getline(temp_style, 20);
            p_clients[i] = new hasDMA(temp_style, temp_label, temp_rating);
        }
        // while (cin.get() != '\n')  // 缓冲区为空时，cin.get()会阻塞；cin 会留下'\n'，所以cin.get()
        // // 不会阻塞； 但是getline会吃掉换行符，所以缓冲区空，需要再输入一次；
        //     continue;

    }
    cout << endl;
    for (int i = 0; i < CLIENTS; i++) {
        p_clients[i]->view();
        cout << endl;
    }

    for (int i = 0; i < CLIENTS; i++) {
        delete p_clients[i];
    }
    cout << "Done.\n";
    return 0;
}
*/
// using namespace std;

int main() {

    cout << "==== Test 1: Default Construction ====" << endl;
    Port p1;
    VintagePort vp1;
    p1.Show();
    vp1.Show();


    cout << "\n==== Test 2: Normal Construction ====" << endl;
    Port p2("Gallo", "ruby", 30);
    VintagePort vp2("Taylor", 20, "Old Velvet", 1990);
    p2.Show();
    vp2.Show();


    cout << "\n==== Test 3: Copy Construction ====" << endl;
    Port p3 = p2;
    VintagePort vp3 = vp2;
    p3.Show();
    vp3.Show();


    cout << "\n==== Test 4: Assignment Operator ====" << endl;
    Port p4("Temporary", "none", 1);
    VintagePort vp4("Temp", 1, "TempNick", 2000);

    p4 = p2;
    vp4 = vp2;

    p4.Show();
    vp4.Show();


    cout << "\n==== Test 5: Deep Copy Verification ====" << endl;
    VintagePort vp5 = vp2;   // copy
    cout << "Before modifying vp5:" << endl;
    vp2.Show();
    vp5.Show();

    // 修改 vp5 看是否影响 vp2
    vp5.operator+=(50);
    vp5.Show();

    cout << "If vp2 unchanged, deep copy works:" << endl;
    vp2.Show();


    cout << "\n==== Test 6: Operator<< Output ====" << endl;
    cout << p2 << endl;
    cout << vp2 << endl;


    cout << "\n==== Test 7: Polymorphism ====" << endl;
    Port* poly = &vp2;   // 基类指针指向派生对象
    poly->Show();        // 应调用 VintagePort::Show()

    cout << "\n==== Test Completed ====\n";

    return 0;
}
