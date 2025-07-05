#ifndef JOINNER_H
#define JOINNER_H
#include <vector>
#include <string>
using namespace std;

class joinner
{
    public:
        joinner();
        virtual ~joinner();
        joinner(const joinner& other);
        joinner& operator=(const joinner& other);
        int number_of_columns=0;
        int number_of_rows=0;
        vector<string> fnlstring;
        int jnr(int number_of_columns,int number_of_rows,struct cio);
        struct sli;

    protected:

    private:
};

#endif // JOINNER_H
