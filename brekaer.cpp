#include "brekaer.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

brekaer::brekaer(){}//ctor

brekaer::~brekaer(){}//dtor

brekaer::brekaer(const brekaer& other){}//copy ctor

brekaer& brekaer::operator=(const brekaer& rhs)
{if (this == &rhs) return *this; // handle self assignment//assignment operator
    return *this;
}

int brekaer::brk_times(string br,int sizof){
    ti_mes=0;
    double diar,fractpart,intpart;
    diar=sizof/4;
    fractpart=modf(diar,&intpart);
    int xy=0;
    xy=intpart*4;
    int lx=0;
    lx=sizof-xy;
    int yx=0;
    yx=intpart+lx;
    cout<<"need to split " << yx  << " times \n";
    return yx;
}

int brekaer::breaker(string brk,int sizof,int spl_times){
    cout<<"max digits per break is 4\n";
    cout<<"using number " << brk <<" with sizeof " << sizof << " and spl_times " << spl_times <<"\n";
    int ct_times=0;
    int pos=3;
    int spos=0;
    string conce;
    conce.clear();
    string tmp_string;
    int szof=0;
    for(;;)
        {
        //  cout<<"using " << spos << " with pos " << pos  << " and pivot = 3[0/4] \n";
          for(spos;spos<=pos;spos+=1)
          {
            conce+=brk.at(spos);
            szof+=1;
          }
          ct_times+=1;
       //   cout<<"inserting value " << conce <<" with ct_times " << ct_times <<"\n";
          brk_ints.push_back(conce);
          conce.clear();
          spos=pos+1;
          pos=pos+4;
       //   cout<<"\n";
       //   cout<<"continue with " << spos << " and pos " << pos <<"\n";
          if(pos>brk.size()){pos=brk.size()-1;goto A;}
          if(pos==brk.size()){pos=pos-1;goto A;}
          A:
          if(ct_times==spl_times){break;}
        }
     return 0;
}

int brekaer::sh_values(){
  cout<<"showing values to user \n";
  for(int i=0;i<=brk_ints.size()-1;i++){
  cout<<i << " " << brk_ints.at(i) <<"\n";
  }
  return 0;
}


