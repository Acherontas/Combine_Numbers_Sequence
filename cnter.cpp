#include "cnter.h"
#include "string"


cnter::cnter(){}//ctor

cnter::~cnter(){}//dtor

cnter::cnter(const cnter& other){}//copyctor

cnter& cnter::operator=(const cnter& rhs)
{if (this == &rhs) return *this; // handle self assignment//assignment operator
    return *this;
}

int cnter::method_count(string bcd)
{
  ctr=0;
     for(int i=0;i<=bcd.size()-1;i++){
         ctr+=1;
         }
  return ctr;
}
