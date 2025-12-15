#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/* P1
int main(){
    char name[20];

    cout << "What is your first name?";
    cin.getline(name, 20);
    cout << "What is your last name?";
    char lname[20];
    cin.getline(lname, 20);
    cout << "What letter grade do you deserve?";
    char grade;
    cin >> grade;
    cout << "Name: " << lname << ", " << name << endl;
    cout << "Grade: " << char('B'+1) << endl;
    cout << int('A') << endl;

    return 0;
}
*/

/* P2
int main(){
    string name;
    string dessert;

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
    return 0;
}  */
/* P3
int main(){
    char fname[20];
    char lname[20];
    cout << "Enter your first name:\n";
    cin >> fname;
    cout << "Enter your last name:\n";
    cin >> lname;
    char fullname[40];
    strcpy(fullname, fname);  
    strcat(fullname, ", ");  //返回的是指针，不用返回值！
    strcat(fullname, lname);
    cout << "Here's the information in a single string: " << fullname << endl;
    return 0;
}*/
/*P4
int main(){
    string fname;
    string lname;

    cout << "Enter your first name:\n";
    cin >> fname;
    cout << "Enter your last name:\n";
    cin >> lname;
    cout << "Here's the information in a single string: " << lname << ", " << fname << endl;
    return 0;
} */
/* P5/6  动态创建数组
struct CandyBar{
    string brand;
    float weight;
    int calories;
};

int main(){
    CandyBar snack[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Choco Delight", 1.5, 250},
        {"Caramel Crunch", 2.0, 300}
    };
    CandyBar * p_snack = new CandyBar[3];  //动态分配内存，并且直接把指针当作数组名使用！！
    cout << "Brand: " << snack[0].brand << endl;
    cout << "Weight: " << snack[1].weight << endl;
    cout << "Calories: " << snack[2].calories << endl;
    cout << "Enter brand: ";
    cin >> p_snack[0].brand;
    cout << "The brand you entered is: " << p_snack[0].brand << endl;
    delete [] p_snack;  //释放内存
    // cout << "Brand: " << p_snack[0]->brand << endl;
    
    return 0;
} 
*/

// /* P7/8
struct Pizza{
    string company;
    float diameter;
    int weight;
};

int main(){
    Pizza * p1 = new Pizza;  //动态分配内存
    // string company;
    // float diameter;
    // int weight;
    cout << "Enter the pizza diameter: ";
    cin >> p1->diameter;
    cout << "Enter the pizza company name: ";
    cin >> p1->company;

    cout << "Enter the pizza weight: ";
    cin >> p1->weight;
    cout << "Pizza company: " << p1->company << endl;
    cout << "Pizza diameter: " << p1->diameter << endl;
    cout << "Pizza weight: " << p1->weight << endl;
    delete p1;  //释放内存
    return 0;
}  
// */
/*
#include <array>
int main(){
    array<int, 3> arr;
    cout << "Plearse enter 3 integers: ";
    for (int i = 0; i < 3; i++){
        cin >> arr[i];
    };
    float grade = (arr[0] + arr[1] + arr[2]) / 3.0;
    cout << "The average of these integers is: " << grade << endl;
    return 0;
}
*/
/*
int main(){
    char ch;
    int count = 0;
    cout << "Enter characters, enter # to quit:\n";

    cin.get(ch);  //一次只读一个字符
    while(ch != '#'){
        cout << ch;
        count++;
        cin.get(ch);  //一次只读一个字符，但是回车前的所有字符都会发送给程序，所以一次回车可以读很多次！！
    };
    cout << endl << count << " characters read." << endl;
    return 0;
}
*/