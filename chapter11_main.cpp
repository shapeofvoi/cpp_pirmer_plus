#include <iostream>
#include <cstdlib> // rand(), srand()
#include <ctime>
#include "chapter11.h"
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

/*
int main() {
    using namespace std;
    using VECTOR::Vector;

    srand(time(0));
    double direction;
    Vector step;
    Vector result(0, 0); // 默认为直角坐标系
    unsigned long steps = 0; // 步数
    double target;
    double dstep;
    double n_step[10];
    // unsigned long total_steps = 0;

    ofstream fout;
    fout.open("../thewalk.txt");  // 打开文件

    cout << "Enter target distance (q to quit): ";
    int i = 0;
    while (cin >> target) {
        cout << "Enter step size: ";
        if (!(cin >> dstep))
            break;

        // fout << "Target Distance: " << target << ", Step Size: " << dstep << std::endl;
        while (result.magval() < target){
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
            // fout << steps << ": " << result << std::endl;
        }
        // fout << "After " << steps << " steps, the subject has the following location:\n";
        // fout << result << std::endl;
        result.polar_mode(); // 改变坐标系
        // fout << " or\n" << result << std::endl;
        // fout << "Average outward distance per step = " << result.magval() / steps << std::endl;
        
        // Q3对应部分
        n_step[i] = result.magval() / steps;
        ++i;


        // 重置条件
        steps = 0;
        result.reset(0, 0);
        cout << "Enter target distance (q to quit): ";
    }

    double min_step = n_step[0];
    double max_step = n_step[0];
    double total_steps = 0;

    for (int j = 0; j < i; ++j) {
        min_step = (n_step[j] < min_step) ? n_step[j] : min_step;
        max_step = (n_step[j] > max_step) ? n_step[j] : max_step;
        total_steps += n_step[j];
    }
    fout << "The max average is: " << max_step << endl;
    fout << "The min average is: " << min_step << endl;
    fout << "The average is: " << total_steps / (i + 1) << endl;
    fout.close();
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
    return 0;
    
}
*/

/*
int main() {
    using std::cout;
    using std::endl;
    Time aida(3, 25);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosac: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

    return 0;
}
*/

/*
int main() {
    using std::cout;
    using std::endl;
    
    Stonewt stns[6] = {275, 285.7, Stonewt(21, 8)};
    int i = 0,  j = 1;
    if (stns[i] > stns[j]) {
        cout << "The first element is more than second!\n";
    }
    else if (stns[i] == stns[j]) {
        cout << "They are the same!\n";
    }
    else {
        cout << "The second one is bigger!\n";
    }

    int stn1 = int (stns[1]);
    cout << stn1;
    // Stonewt incognito = 275;
    // Stonewt wolfe(285.7);
    // Stonewt taft(21, 8);

    // cout << "The celebrity weighed " << incognito << endl;
    // wolfe.set_mode(Stonewt::stn_type);
    // cout << "The detective weighed " << wolfe << endl;
    // cout << "The double incognito is " << incognito * 2.0 << endl;

    return 0;
}
*/

int main() {
    complexx a(3.0, 4.0);
    complexx c;
    cout << "Enter a complex number (q to quit):\n";
    while(cin >> c) {
        cout << "c is "  << c << '\n';
        cout << "complex conjugate is " << ~c << endl;
        cout << "a is " << a << endl;
        cout << "a + c is " << a + c << endl;
        cout << "a - c is " << a - c << endl;
        cout << "a * c is " << a * c << endl;
        cout << "2 * c is " << 2 * c << endl;
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}