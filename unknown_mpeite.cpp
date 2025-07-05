#include "unknown_mpeite.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

unknown_mpeite::unknown_mpeite(int sizofptr,string s){
gth=(struct gen_them*)malloc(sizofptr*sizeof(gen_them));
lbsu(s);
}//ctor
unknown_mpeite::~unknown_mpeite(){}//dtor
unknown_mpeite::unknown_mpeite(const unknown_mpeite& other){}//copy ctor
unknown_mpeite& unknown_mpeite::operator=(const unknown_mpeite& rhs)
{if (this == &rhs) return *this; // handle self assignment//assignment operator
    return *this;
}


string unknown_mpeite::lsub(string s){
  string tmp;
  string ltp;
  string mntp; mntp.clear();
  mntp+=s;
  int x=0,y=0,z=0;int initl=0;int initl_pos=0;int i=0;int t=0;int k=0;
  t=s.size()-1;
  t=t+1;
  initl=s.at(0);initl_pos=0;
   //for(i=0;i<=s.size()-1;i++){
      tmp.clear();
      ltp.clear();
      x=0;
      y=i+1;
      while(x<=i){
        tmp+=s.at(x);
        x+=1;
      }
      while(y<=s.size()-1){
        ltp+=s.at(y);
        y+=1;
      }
      ltp+=tmp;
      if(i==0){
        cout<<i << " for initial value " << s <<  " temp sub value : " << ltp << "\n";
        mntp.clear();
        mntp+=ltp;
//        break;
      }
      tmp.clear();
      ltp.clear();
  // }
return mntp;
}

int unknown_mpeite::allocate_gen_space(int size_of_ptr){
gth=(struct gen_them*)malloc(size_of_ptr*sizeof(gen_them));
return 0;
}

int unknown_mpeite::free_da_struct(){
free(gth);
return 0;
};

int unknown_mpeite::lbsu(string s){
  cout<<"allocating space: " << s.size() <<" for number " << s <<"\n";
  //allocate_gen_space(s.size()-1);
  strptr=0;
  //aristero meros
  int arxi=0;
  int telos=1;
  string temp;
  //dexi meros
  int arxi_dexi=arxi+1;
  int telos_dexi=s.size()-1;
  string dtemp;
  //aristero meros
  for(;;){
   while(arxi<telos){
   temp+=s.at(arxi);
   arxi+=1;
   }
//   cout<<"da temp is " << temp <<"\n";
   gth[strptr].part_one+=temp;
   arxi=0;
   telos+=1;
   temp.clear();
   strptr+=1;
   if(telos==s.size()){break;}
  }
  //dexi meros
  strptr=0;arxi=0;arxi_dexi=arxi+1;int cnt=0;
  for(;;){
    while(arxi_dexi<=telos_dexi){
     dtemp+=s.at(arxi_dexi);
      arxi_dexi+=1;
    }
    cnt+=1;
    gth[strptr].part_two+=dtemp;
    //cout<<"da dexi_temp is " << dtemp <<"\n";
   // cout<<"arxi_dexi is " << arxi_dexi <<"\n";
    arxi_dexi=arxi+1+cnt;
    dtemp.clear();
    strptr+=1;
    if(arxi_dexi==s.size()){break;}
  }
  string lmi;
  for(int i=0;i<=strptr;i++){
    cout<<i << " " << gth[i].part_two <<  gth[i].part_one <<"\n";
    lmi.clear();
    lmi+=gth[i].part_two;
    lmi+=gth[i].part_one;
    final_v.push_back(lmi);
  }
  //for(int i=0;i<=strptr;i++){
  //  free(*gth[i]);
  //}
  //free_da_struct();
  return 0;
}
