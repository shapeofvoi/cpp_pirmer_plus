#include "chapter14.hpp"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::Average() const {
    if (scores.size() > 0)
        return scores.sum() / scores.size();
    else
        return 0;
}

const string & Student::Name() const {
    return name;
}

double & Student::operator[](int i) {
    return scores[i];
}

double Student::operator[](int i) const{
    return scores[i];
}

// private method
ostream & Student::arr_out(ostream & os) const {
    int i;
    int lim = scores.size();
    if (lim > 0) {
        for (i = 0; i < lim; ++i) {
            os << scores[i] << " ";
            if (i % 5 == 4) os << endl;
        }
        if (i % 5 != 0) os << endl;
    }
    else
        os << " empty array ";
    
    return os;
}

// friends
istream & operator>>(istream & is, Student & stu) {
    is >> stu.name;
    return is;
}

istream & getline(istream & is, Student & stu) {
    getline(is, stu.name);
    return is;
}

ostream & operator<<(ostream & os, const Student & stu) {
    os << "Scores for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}

// =====================类模板=====================
template<class Type>
Stack<Type>::Stack(int ss) : stacksize(ss), top(0) {
    items = new Type [stacksize];
}

template<class Type>
Stack<Type>::Stack(const Stack& st) {
    stacksize = st.stacksize;
    top = st.top;
    items = new Type [stacksize];
    for (int i = 0; i < stacksize; ++i) {
        items[i] = st.items[i];
    }
}

template<class Type>
bool Stack<Type>::push(const Type& item) {
    if (top < stacksize) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}

template<class Type>
bool Stack<Type>::pop(Type& item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}

template<class Type>
Stack<Type>& Stack<Type>::operator=(const Stack& st) {
    if (this == &st)
        return *this;
    
    top = st.top;
    stacksize = st.stacksize;
    delete [] items;
    items = new Type [stacksize];
    for (int i = 0; i < top; ++i)
        items[i] = st.items[i];

    return *this;
}

/* ==================== Pair模板 =====================*/
// template<class T1, class T2>
// T1& Pair<T1, T2>::first() {
//     return a;
// }

// template<class T1, class T2>
// T2& Pair<T1, T2>::second() {
//     return b;
// }