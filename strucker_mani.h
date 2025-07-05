#ifndef STRUCKER_MANI_H
#define STRUCKER_MANI_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class strucker_mani
{
    public:
        strucker_mani(int columns_hv);
        int strucker_mani_d(int columns_hv);
        virtual ~strucker_mani();
        strucker_mani(const strucker_mani& other);
        strucker_mani& operator=(const strucker_mani& other);
        int row_count=0;
        int columns_count=0;
        int rows_per_column=24;
        int r_per_col=0;
        int struct_filler(string vlue,int col_ha,int col_end);
        struct my_list{string clm[24];};
        struct my_list *p;
        int columns_have=0;
        struct two_nti_plane{int ar_start;int ar_end;};
        struct two_nti_plane *two_nti;
        int plane_range(int columns,int rows);
        int joiner();
        int struct_reader(int lkl);
        vector<string> full_value;
        int fvl_reader();
        int sub_levels();
        int peiramatik_mt(int start_range,int end_range,int arr_size,int t_f,int rows_per_column,int tim);
        vector<string> prmt_vl;
        int prmt_cnt=0;
        int prmt_vl_show(int pmrt_ctn);
    protected:
    private:
};

#endif // STRUCKER_MANI_H
