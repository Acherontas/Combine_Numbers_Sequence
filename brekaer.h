#ifndef BREKAER_H
#define BREKAER_H

#include "string"
#include <vector>
using namespace std;
class brekaer
{
    public:
        brekaer();
        virtual ~brekaer();
        brekaer(const brekaer& other);
        brekaer& operator=(const brekaer& other);
        int ti_mes=0;
        int brk_times(string br,int sizof);
        vector <string> brk_ints;
        int breaker(string brk,int sizof,int spl_times);
        int sh_values();


    protected:

    private:
};

#endif // BREKAER_H
