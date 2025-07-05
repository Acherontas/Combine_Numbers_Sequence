#ifndef PEIRAMATIK_MT_H
#define PEIRAMATIK_MT_H

#include "strucker_mani.h"

class peiramatik_mt
{
    public:
        peiramatik_mt();
        virtual ~peiramatik_mt();
        peiramatik_mt(const peiramatik_mt& other);
        peiramatik_mt& operator=(const peiramatik_mt& other);
        int shufle_them(int sizofarra,int start_of_range,int end_of_range,int times_to_pass,int throth_thread,struct my_list *p);
    protected:

    private:
};

#endif // PEIRAMATIK_MT_H
