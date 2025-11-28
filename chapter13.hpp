#ifndef ACCTABC_H_
#define ACCTABC_H_

#include <iostream>
#include <string>

class AcctABC {
    private:
        std::string fullname;
        long acctNum;
        double balance;

    protected:
        struct Formatting {
            std::ios_base::fmtflags flag;
            std::streamsize pr;
        };
        
}

#endif