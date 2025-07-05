#ifndef TBL_FOUR_H
#define TBL_FOUR_H
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
        /*
        1	2	3	4
        1	2	4	3
        1	3	2	4
        1	3	4	2
        1	4	2	3
        1	4	3	2
        */
class tbl_four
{
    public:
        tbl_four();
        virtual ~tbl_four();
        tbl_four(const tbl_four& other);
        tbl_four& operator=(const tbl_four& other);
        vector<string> mult;
        int last_value_pos=0;
        int psxy_change(string m_vec,int sizof);
        string crt_dbfill;
        int dbl_fill(string m_vec,int sizof);



    protected:

    private:
};

#endif // TBL_FOUR_H
