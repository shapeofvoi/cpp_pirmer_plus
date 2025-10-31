#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
/*
int main(){
    char a = 'a';
    cout << a + 1 << endl;
    cout << ++a << endl;

    return 0;
}
*/
/*P1*/
/*
int main(){
    char ch;
    cout << "Enter a character: (enter '@' to quit)\n";
    cin >> ch;
    while (ch != '@'){
        if (ch >= 'a' && ch <= 'z')
            ch = toupper(ch);
        else if (ch >= 'A' && ch <= 'Z')
            ch = tolower(ch);
        else
            continue;
        cout << ch;
        cin >> ch;
    }
    return 0;
}
*/
/*P2*/
/*
const int Max = 10;
int main(){
    double arr[Max], sum = 0.0;
    cout << "Please enter at most 10 numbers:\n";
    int i, count = 0;
    for (i = 0; i < Max; i++){
        cout << "round #" << i + 1 << ":";
        if (!(cin >> arr[i]))
            break;

        sum += arr[i];
        count++;
        if (i < Max)
            cout << "Please enter a new number:\n";
    }
    if (count == 0){
        cout << "No numbers!\n";
        return 0;
    }

    // 计算平均值,并查看有多少大于平均值的数
    double average = sum / count;
    int num = 0;  // 计算有多少大于平均值的数
    for (int j = 0; j < count; j++){
        if (arr[j] > average)
            num++;
    }

    // 输出结果
    cout << "The average of these numbers is:" << average
        << ", and there are "  << num << " numbers greater than average!\n";
    return 0;

}
*/

/*P3*/
/*
void showMenu();

int main() {
    char choice;

    showMenu();
    cin >> choice;

    while (choice != 'c' && choice != 'p' && choice != 't' && choice != 'g') {
        cout << "Please enter a c, p, t, or g: ";
        cin >> choice;
    }

    switch (choice) {
        case 'c':
            cout << "A tiger is a carnivore.\n";
            break;
        case 'p':
            cout << "You are going to be a pianist!\n";
            break;
        case 't':
            cout << "A maple is a tree.\n";
            break;
        case 'g':
            cout << "Game is fun!\n";
            break;
    }

    return 0;
}

void showMenu() {
    cout << "Please enter one of the following choices:\n"
         << "c) carnivore   p) pianist\n"
         << "t) tree        g) game\n";
}
*/

/*P4*/
/*
const int strsize = 20, arrsize = 4;
struct bop {
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};
void showmenu();

int main() {
    bop p[4] = {{"wimp Macho", "aa", "aaa", 0},
                {"Raki Rhodes", "Junior Programmer", "bbb", 1},
                {"Celia Laiter", "cc", "MIPS", 2},
                {"Pat Hand", "dd", "LOOPY", 2}};
    showmenu();
    char choice;
    cout << "Enter your choice:";
    cin >> choice;
    int idx;  // 选择用哪个名称展示，数字与结构体的顺序对应，0即展示fullname

    while (choice != 'q') {
        switch (choice) {
            case 'a':
                for (int i = 0; i < arrsize; i++) {
                    cout << p[i].fullname << endl;
                }
                break;
            case 'b':
                for (int i = 0; i < arrsize; i++) {
                    cout << p[i].title << endl;
                }
                break;
            case 'c':
                for (int i = 0; i < arrsize; i++) {
                    cout << p[i].bopname << endl;
                }
                break;
            case 'd':
                for (int i = 0; i < arrsize; i++) {
                    int idx = p[i].preference;
                    switch (idx) {
                        case 0:
                            cout << p[i].fullname << endl;
                            break;
                        case 1:
                            cout << p[i].title << endl;
                            break;
                        case 2:
                            cout << p[i].bopname << endl;
                    }
                }
                break;
        }
        if (choice !=  'q'){
            cout << "Next choice:";
            cin >> choice;
        }
    }
    cout << "Bye!\n";
    return 0;
}

void showmenu() {
    cout << "a. display by name     b. display by title\n"
         << "c.display by bopname    d. display by preference\n"
         << "q. quit";
}
*/

/*P5*/
/*
int main() {
    double income, res;

    cout << "Please enter income:";
    while (cin >> income) {
        // income的返回值是一个istream对象，在bool上下文会转换为true或false
        if (income < 0) break;
        if (income <= 5000)
            res = 0;
        else if (income <= 15000)
            res = (income - 5000) * 0.1;
        else if (income <= 35000)
            res = 1000 * 0.1 + (income - 15000) * 0.15;
        else
            res = 1000 * 0.1 + 20000 * 0.15 + (income - 35000) * 0.2;
        cout << "The tax is : " << res << " tvarps." << endl;
        cout << "Please enter another income:";
    }
    return 0;
}
*/

/*P6*/
/*
struct Patron{
    string name;
    double number;
};

int main(){
    Patron * patrons = new Patron[100];
    int count = 0;
    char quit;
    cout << "Please enter the name of patron and the amount of donation:\n" << "(Enter 'q' to stop!)";
    while(count < 100){
        cout << "Name:";
        getline(cin, patrons[count].name);
        cout << "Number:";
        cin >> patrons[count].number;
        cin.get();

        cout << "One patron has been writen!\n"
            << "Any more?(Enter 'y' to continue, 'q' to quit)";
        cin >> quit;
        cin.get();
        count++;
        if (quit == 'q') break;
        cout << "Continue:";

    }

    cout << "The followings are Grand Patrons:\n";
    for (size_t i = 0; i < count; i++){
        if (patrons[i].number >= 10000){
            if (patrons[i].name.empty())
                patrons[i].name = "none";
            cout << patrons[i].name << ": "<< patrons[i].number << endl;   
        }
            
    }
    cout << "Patrons:\n";
    for (size_t i = 0; i < count; i++){
        if (patrons[i].number < 10000){
            if (patrons[i].name.empty())
                patrons[i].name = "none";
            cout << patrons[i].name << ": "<< patrons[i].number << endl;   
        }
            
    }
    delete [] patrons;
    return 0;
    
}
*/

/* P6(vector)*/
/*
struct Patron{
    string name;
    double number;
};
int main(){
    vector <Patron> patrons;
    int count = 0;

    cout << "Please enter the name of patron and the amount of donation:\n" << "(Enter 'q' as name to stop!)\n";
    // cin.ignore();  忽略一个字符！！
    // cin.get(); 从输入缓冲区中读取字符（包括空白字符）
    while(true){
        Patron p;
        cout << "Name:";
        getline(cin,p.name);
        if (p.name == "q") break;

        cout << "Number:";
        cin >> p.number;
        cin.get();

        patrons.push_back(p);
        count++;
        cout << "Patron added successfully!\n\n";
    }

    // 显示结果
    cout << "\n=== DONATION REPORT ===\n";

    cout << "The followings are Grand Patrons:\n";
    for (int i = 0; i < count; i++){
        if (patrons[i].number >= 10000){
            if (patrons[i].name.empty())
                patrons[i].name = "none";
            cout << patrons[i].name << ": "<< patrons[i].number << endl;   
        }
            
    }

    cout << "Patrons:\n";
    for (size_t i = 0; i < count; i++){
        if (patrons[i].number < 10000){
            if (patrons[i].name.empty())
                patrons[i].name = "none";
            cout << patrons[i].name << ": "<< patrons[i].number << endl;   
        }
            
    }
    return 0;
}
*/

/*P7*/
int main(){
    cout << "Enter words (q to quit):\n";
    string word;
    int vowels = 0, consonants = 0, others = 0;
    while(cin >> word && word != "q"){
        if (isalpha(tolower(word[0]))){
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')
                vowels++;
            else
                consonants++;
        }
        else
            others++;
    }

    cout << vowels << " words beginning with vowels.\n"
        << consonants << " words beginning with consonants.\n"
        << others << " others.\n";
    return 0;
}