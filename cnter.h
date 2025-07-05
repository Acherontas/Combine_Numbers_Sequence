#ifndef CNTER_H
#define CNTER_H
#include "string"
using namespace std;


class cnter
{
    public:
        cnter();
        virtual ~cnter();
        cnter(const cnter& other);
        cnter& operator=(const cnter& other);
        int ctr=0;
        int method_count(string bcd);
    protected:

    private:
};

#endif // CNTER_H
