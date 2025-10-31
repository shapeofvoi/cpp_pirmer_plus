# include <iostream>

using namespace std;

/* P1 */
/*
int main(){
    double sum(double, double); // 计算调和平均数

    cout << "Please enter two numbers:\n";
    double x, y;
    while(cin >> x >> y){
        double aver = sum(x, y);
        cout << "The res is :" << aver << endl;
        cout << "Please enter two numbers, or enter 'q' to quit!\n";
    }
    return 0;
}

double sum(double x, double y){
    return 2.0 * x * y / (x + y);
} */

/* P2 三个数组处理函数  注意数组作为函数参数的输入方式*/
/*
int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
double cal_aver(double arr[], int n);
void Reverse_array(double arr[], int n);

int main(){
    const int Max_elems = 10;
    double arr[10];
    int n; // 储存输入元素数量

    n = fill_array(arr, Max_elems);  // 直接代入数组名
    show_array(arr, n);
    double aver = cal_aver(arr, n);
    cout << "The average of the grades is: " << aver << endl;
    Reverse_array(arr, n);
    cout << "The reversed array is: ";
    show_array(arr, n);
    return 0;
}

int fill_array(double arr[], int limit){
    double temp;
    int i = 0;
    for ( ; i < limit; i++){
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin){
            cin.clear();  // 清楚错误状态，让流恢复正常状态；但是刚刚的错误输入还是在缓冲区
            cin.ignore(100, '\n');  // 清楚缓冲区的错误输入
            cout << "Bad input; input process teminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        else
            arr[i] = temp;
    }
    return i;
}

void show_array(const double arr[], int n){
    cout << "The grades is: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

double cal_aver(double arr[], int n){
    if (n <= 0) return 0.0;
    double aver = 0.0;
    for (int i = 0; i < n; i++){
        aver += arr[i];
    }
    aver /= n;
    return aver;
} 

void Reverse_array(double arr[], int n){
    if(n <= 2){
        cout << "The elements are less than 2!\n"
            << "failed!";
    }
    else{
        int i = 1, j = n - 2;
        double temp;
        for ( ; i < j; i++, j--){
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
}
*/

/* P3 编写三个函数，运用结构体*/
/*
struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_struct(box);
void cal_vol(box* );
int main(){
    box b = {"Box11", 10, 5, 2};
    show_struct(b);
    cal_vol(&b);
    show_struct(b);
    return 0;
}

void show_struct(box b1){
    cout << "The info of box is: \n"; 
    cout << "Maker:"<< b1.maker << endl;
    cout << "Height: " << b1.height << endl;
    cout << "width: " << b1.width << endl;
    cout << "length: " << b1.length << endl;
    cout << "volume: " << b1.volume << endl;
}

void cal_vol(box * b){
    b->volume = b->height * b->length * b->width;
}
*/

/* P4 计算中奖概率*/
/*
long double probability(unsigned , unsigned , unsigned picks);

int main(){
    double total1, total2, choices;
    cout << "Enter the total number of choices on the game card in two areas and\n"
        "the number of picks allowed:\n";
    while((cin >> total1 >> total2 >> choices) && choices <= total1){
        cout << probability(total1, total2, choices);
    }
}
long double probability(unsigned n1, unsigned n2, unsigned picks){
    long double res = 1.0;
    long double n;
    unsigned p;
    for (n = n1, p = picks; p > 0; p--, n--)
        res *= n / p;
    res *= n2;
    return res;
}*/
/* P5 阶乘*/
/*
int factor(int);

int main(){
    cout << "Please enter a number: ";
    int n;
    cin >> n;
    cout << "The factor of " << n << " is " << factor(n) << endl;
    return 0;
}

int factor(int n){
    if(n == 1)
        return n;
    else 
        return n * factor(n-1);
} */
/* P7 四季账单
double * fill_array(double arr[], int limit);
void show_array(const double arr[], double * n);
double cal_aver(double arr[], double * n);

int main(){
    const int Max_elems = 10;
    double arr[10];
    int n; // 储存输入元素数量

    double * n_p = fill_array(arr, Max_elems);  // 直接代入数组名
    show_array(arr, n_p);
    double aver = cal_aver(arr, n_p);
    cout << "The average of the grades is: " << aver << endl;
    return 0;
}

double * fill_array(double arr[], int limit){
    double temp;
    int i = 0;
    for ( ; i < limit; i++){
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin){
            cin.clear();  // 清楚错误状态，让流恢复正常状态；但是刚刚的错误输入还是在缓冲区
            cin.ignore(100, '\n');  // 清楚缓冲区的错误输入
            cout << "Bad input; input process teminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        else
            arr[i] = temp;
    }
    return &arr[i];
}

void show_array(const double arr[], double * end_p){
    cout << "The grades is: ";
    for (const double * ptr = arr ; ptr != end_p; ptr++){
        cout << *ptr << " ";
    }
}

double cal_aver(double arr[], double * end_p){
    int n = end_p - arr;
    if (n <= 0) return 0.0;
    double aver = 0.0;
    for (const double * ptr = arr ; ptr != end_p; ptr++){
        aver += *ptr;
    }
    aver /= n;
    return aver;
} 

/* P8 四季账单*/
/*
const int Seasons = 4;
const char * Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};  // 字符串数组，每个元素表示一个const char *,即字符串指针

void fill(const char * names[], double * expenses);
void show (const char * names[], double * arr);
int main(){
    double expenses[Seasons];
    fill(Snames, expenses);
    show(Snames, expenses);
    return 0;
}

void fill(const char * names[], double * expenses){
    for (int i = 0; i < Seasons; i++){
        cout << "Enter " << names[i] << " expenses: ";
        cin >> expenses[i];
    }
}
void show (const char * names[], double * arr){
    double sum = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++){
        cout << names[i] << ": $" << arr[i] << endl;
        sum += arr[i];
    }
    cout << "Total expenses: $" << sum << endl;
}
*/

/* P10 */
double add(double x, double y);
double multiple(double x, double y);
double substract(double x, double y);
double calculate(double , double , double (*pa[])(double , double));

int main(){
    // 初始化指针数组，指向三个函数
    double (*pf[3])(double ,double ) = {add, multiple, substract};
    cout << "Please enter two numbers: ";
    double x, y;
    while (cin >> x >> y){
        calculate(x, y, pf);
        cout << "Please enter two numbers to continue: ";
    }
    return 0;
}

double add(double x, double y){
    return x + y;
}

double multiple(double x, double y){
    return x * y;
}
double substract(double x, double y){
    return x - y;
}

// 正确传递函数指针数组的方式： 实际上会退化为 double (**pa)(double , double)
double calculate(double x, double y, double (*pa[])(double , double)){
    cout << "两数之和、积、差分别为：\n";
    for (int i = 0; i < 3; i++){
        cout << pa[i](x, y) << endl;
    }
    return 0;
}