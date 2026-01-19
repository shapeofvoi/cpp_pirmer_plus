#include <iostream>
#include "chapter14.hpp"

using std::cin;
using std::cout;
using std::endl;

/*
void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;

int main() {
    Student ada[pupils] = 
        {Student(quizzes), Student(quizzes), Student(quizzes)};
    
    int i;
    for (i = 0; i < pupils; ++i) {
        set(ada[i], quizzes);
    }
    cout << "\nResults:";

    for (i = 0; i < pupils; ++i) {
        cout << endl << ada[i];
        cout << "average: " << ada[i].Average() << endl;
    }
    cout << "Done!\n";

    return 0;
}

void set(Student & sa, int n) {
    cout << "Please enter the student's name: ";
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++) {
        cin >> sa[i];
    }
    while(cin.get() != '\n')
        continue;
}
        */

int main() {
    using std::cout;
    using std::endl;
    using std::string;
    Pair<string, int> ratings[4] = {
        Pair<string, int>("The Purpled Duck", 5),
        Pair<string, int>("Jaquie's Frisco Al Fresco", 4),
        Pair<string, int>("Cafe Souffle", 5),
        Pair<string, int>("Bertie's Eats", 3)
    };

    int joints = sizeof(ratings) / sizeof(Pair<string, int>);
    cout << "Rating:\t Eatery\n";
    for (int i = 0; i < joints; ++i) {
        cout << ratings[i].second() << ":\t"
             << ratings[i].first() << endl;
    }
    cout << "Oops! Revised rating:\n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;
    cout << ratings[3].second() << ":\t"
         << ratings[3].first() << endl;

    return 0;

}
