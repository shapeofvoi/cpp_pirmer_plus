#include <iostream>
#include <cstring>
#include "chapter12.h"

// Cow::Cow(): name("warrior"), weight(100) {  数组不能用列表初始化 X
//     hobby = new char[4];
//     hobby = "run"; //  hobby是地址，不能直接这么赋值
//     *hobby = "run"; // *hobby是单个字符，"run"是const char *; 必须先分配内存再strcpy拷贝！！
// }

Cow::Cow(): weight(100) {
    std::strcpy(name, "warrior");
    hobby = new char[4];
    std::strcpy(hobby, "run");
}

Cow::Cow(const char * nm, const char * ho, double wt) {
    std::strcpy(name, nm);
    hobby = new char[std::strlen(ho) + 1];
    std::strcpy(hobby, ho);
    weight = wt;
}

// 显示定义复制构造函数
Cow::Cow(const Cow & c){
    std::strcpy(name, c.name);
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow() {
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c){
    if (this == &c)
        return *this;
    delete [] hobby;
    hobby = new char[std::strlen(c.hobby) + 1];
    std::strcpy(hobby, c.hobby);
    std::strcpy(name, c.name);
    weight = c.weight;
    return *this;  // *this是引用
}

void Cow::ShowCow() const {
    std::cout << "The name: " << name << std::endl
        << "The weight: " << weight << std::endl
        << "The hobby: " << hobby << std::endl;
}

/* -------------------String类方法实现--------------------*/
int String::num_strings = 0;  // 类外必须定义一次，只声明不行

String::String(const char * s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    
}

String::String(){
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st) {
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    num_strings++;
}

String::~String() {
    delete [] str;
    num_strings--;
}

String & String::operator=(const String & st) {
    if (*this == st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);

    return *this;
}

String & String::operator=(const char * s) {
    len = strlen(s);
    delete [] str;
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

String String::operator+(const String & st) {
    String res;
    res.len = len + st.len;
    res.str = new char[res.len + 1];
    strcpy(res.str, str);
    strcat(res.str, st.str);

    return res;
}

char & String::operator[](int i) {
    return str[i];
}

const char & String::operator[](int i) const {
    return str[i];
}

bool operator<(const String& st, const String& st2) { 
    // strcmp函数按照字母顺序，第一个小于第二个返回-1，相等返回0，大于返回1
    return (strcmp(st.str, st2.str) < 0);  
}

bool operator>(const String & st, const String & st2) {
    return (strcmp(st.str, st2.str) > 0);
}

bool operator==(const String & st, const String & st2) {
    return (strcmp(st.str, st2.str) == 0);
}

String operator+(const String & st, const String & st2) {
    // String res;
    // res = st + st2;
    return st + st2;
}

ostream & operator<<(ostream & os, const String & st) {
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st) {
    // char temp[String::CINLIM];
    // is.get(temp, String::CINLIM);
    // if (is)
    //     st = temp;
    // while(is && is.get() != '\n')
    //     continue;
    // return is;

    char temp[String::CINLIM];
    is.getline(temp, String::CINLIM);  // 直接读取一行
    if (is)
        st = temp;
    return is;

}

int String::HowMany() {
    return num_strings;
}

void String::stringlow() {
    for (int i = 0; i < len; ++i) {
        if (isalpha(static_cast<unsigned char>(str[i])))
            str[i] = std::tolower(static_cast<unsigned char>(str[i]));
    }
}

void String::stringup() {
    for (int i = 0; i < len; ++i) {
        if (isalpha(static_cast<unsigned char>(str[i])))
            str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

int String::has(const char c) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == c)
            count++;
    }
    return count;
}

/*==================Stock类方法实现=================*/
Stock::Stock(): len(7), shares(0), share_val(0), total_val(0) {
    company = new char[len + 1];
    strcpy(company, "no name");
}

Stock::Stock(const char * co, long n, double pr) {
    len = strlen(co);
    company = new char[len + 1];
    strcpy(company, co);

    if (n < 0) {
        cout << "Number of shares can't be negative; "
            << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock() {
    delete [] company;
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        cout << "Number of shares purchased can't be nagetive. "
            << "Transaction is aborted.\n";
    }
    else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0) {
        cout << "Number of shares sold can't be negative. "
            << "Transaction is aborted.\n";
    }
    else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const {
    if (s.total_val > total_val) {
        return s;
    }
    else 
        return *this;
}

ostream & operator<<(ostream & os, const Stock & sto) {
    using std::ios_base;
    ios_base::fmtflags orig = 
        os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os << "Company: " << sto.company 
        << " Shares: " << sto.shares << '\n';
    os << " Share Price: $" << sto.share_val;

    os.precision(2);
    os << " Total Worth: $" << sto.total_val;

    os.setf(orig, ios_base::floatfield);
    os.precision(prec);

    return os;
}

/*=================Stack类方法实现=================*/
Stack::Stack(int n){
    if (n > MAX) {
        cout << "The max number of elements can't be more than " << MAX
             << "\nThe constructor didn't work.";
        n = MAX;
    }
    else {
        size = n;
        pitems = new Item[size];
        top = 0;
    }


}

Stack::Stack(const Stack & st) {
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; ++i) {
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack() {
    delete [] pitems;
}

bool Stack::isempty() const{
    return top == 0;
}

bool Stack::isfull() const{
    return top == size;
}

bool Stack::push(const Item & item){
    if (top < size){
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item){
    if (top > 0){
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack & Stack::operator=(const Stack & st) {
    // if (*this == st)
        // return *this;
    delete [] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; ++i) {
        pitems[i] = st.pitems[i];
    }

    return *this;

}

/*=============Queue类方法实现===================*/
Queue::Queue(int qs): qsize(qs) {
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue() {
    Node * temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;  // 因为队列的每个元素是用new创建的新对象
    }
}

bool Queue::isempty() const {
    return items == 0;
}

bool Queue::isfull() const {
    return items == qsize;
}

int Queue::queuecount() const {
    return items;
}

bool Queue::enqueue(const Item & item) {
    if (isfull())
        return false;
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    // 边界情况：如果队列本来为空，则front应该指向刚刚添加的那个元素
    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    items++;
    return true;
}
// 增删的核心是，处理好front, rear指针
bool Queue::dequeue(Item & item) {
    if (isempty())
        return false;
    item = front->item;
    Node * temp = front;
    front = front->next;
    delete temp;
    items--;
    // 边界情况：如果刚删除的是最后一个元素，则rear指向的对象被删除了
    if (items == 0)
        rear = nullptr;

    return true;
}

void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}