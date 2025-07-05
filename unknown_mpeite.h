#ifndef UNKNOWN_MPEITE_H
#define UNKNOWN_MPEITE_H

#include <string>
#include <vector>
using namespace std;
class unknown_mpeite
{
    public:
        unknown_mpeite(int sizofptr,string sil);
        virtual ~unknown_mpeite();
        unknown_mpeite(const unknown_mpeite& other);
        unknown_mpeite& operator=(const unknown_mpeite& other);
        vector<string> sub_values;
        string lsub(string s);
        int lbsu(string s);
        int strptr=0; //sum of structs
        int allocate_gen_space(int size_of_ptr);
        int free_da_struct();
        vector<string> final_v;
    protected:

    private:
      struct gen_them{string part_one;string part_two;};
      struct gen_them *gth;

};

#endif // UNKNOWN_MPEITE_H
