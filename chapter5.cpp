#include <iostream>
#include <array>
#include <string>
#include <cstring>
using namespace std;
/*
const int CityNum = 5;
int main(){
    const char * p_cities[CityNum] = {
        "Beijing",
        "Shanghai",
        "Guangzhou",
        "Shenzhen",
        "Chengdu"
    };

    for (int i = 0; i < CityNum; ++i){
        cout << p_cities[i] << " at "<< &p_cities[i] << endl;
        // cout << cities[i] << " at " << (int)&cities[i] << endl;
    }
    cout << p_cities << endl;
    cout << p_cities + 1 << endl;
    cout << *(p_cities + 1) << endl;
    return 0;
}
*/
// /*
int main(){
    cout << "Enter the two nums:" << endl;
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = a; i <= b; ++i){
        sum += i;
    }
    cout << "The sum of " << a << " and " << b << " is: " << sum << endl;
    return 0;
}

// */
/*
P2
const int ArSize = 16;
int main(){
    array<long long, ArSize> factorials;
    factorials[1] = factorials[0] = 1LL;
    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];
    for (int i = 0; i < ArSize; i++)
        cout << i << "! = " << factorials[i] << endl;

    return 0;
}

// P3
int main(){
    cout << "Enter the number, it will compute the sum before '0'.\n";
    int a, sum = 0;
    cin >> a;
    while (a != 0){
        sum += a;
        cin >> a;
    }
    cout << "The result is: " << sum << endl;
    return 0;
}
*/
/* P4
int main(){
    float Daphne = 100.0, Cleo = 100.0;
    int year = 0;
    do {
        Daphne += 10;
        Cleo *= 1.05;
        year++;
    } while (Cleo <= Daphne);
    cout << "The Cleo is more than Daphne at " << year << endl;
    cout << "They have " << Daphne << " and " << Cleo << " dollars.\n";
    return 0;
} */
/* P7
int main(){
    const char months[12][20] = {
        "January", "Febrauary", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int sum = 0, sale_single[12];
    for (int i = 0; i < 12; i++){
        cout << "Please enter the sale in " << months[i] << endl;
        cin >> sale_single[i];
        sum += sale_single[i];
    }
    for (int i = 0; i < 12; i++){
        cout << months[i] << ": " << sale_single[i] << endl;
    }
    cout << "The total sale in this year is: " << sum << endl;
    return 0;
}
*/
/* P6
int main(){
    struct Car{
        string maker;
        int year_birth;
    };
    cout << "How many cars do you wish to catalog?\n";
    int num;
    cin >> num;
    cin.get();  //吸收回车
    Car * cars = new Car [num];  //动态分配内存
    for (int i = 0; i < num; ++i){
        cout << "Car #" << i + 1 << ":\n";
        cout << "Please enter the make: ";
        getline(cin, cars[i].maker);
        cout << "Please enter the year made: ";
        cin >> cars[i].year_birth;  // !!cin不会舍弃换行符，缓冲区还有"\n"，后面的循环会用getline读到空行
        cin.get();  //吸收回车
    }
    cout << "Here is your collection:\n";
    for (int i = 0; i < num; ++i){
        cout << cars[i].year_birth << " " << cars[i].maker << endl;
    }
    delete [] cars;  //释放内存
    return 0;
}
*/
/* P8
int main(){
    cout << "Enter words (to stop, type the word done):\n";
    int count = 0;
    char word[20];
    cin >> word;
    
    while(strcmp(word, "done") != 0){
        cin >> word;
        cout << word;
        count++;
    } 
    cout << "You entered a total of " << count << " words" << endl;
    return 0;
}
*/
/* P9
int main(){
    cout << "Enter words (to stop, type the word done):\n";
    int count = -1;
    string word;
    do {
        cin >> word;  //cin会跳过空白前导符
        // getline(cin ,word);  //getline会读取空白符
        cout << word;
        count++;
    } while(word != "done");
    cout << "You entered a total of " << count << " words" << endl;
    return 0;
}
*/

/*
int main(){
    cout << "Please enter thr number of rows:";
    int rows;
    cin >> rows;
    for (int i = 0; i < rows; i++){
        int j = 0;
        for (; j < rows - i - 1; j++)
            cout << '.';
        for (int k = j; k < rows; k++)
            cout << '*';
        cout << endl;
    }
    return 0;
}
*/