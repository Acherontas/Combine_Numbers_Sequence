#include "tbl_four.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <chrono>
using namespace std;
   /*   1	2	3	4               1	2	3          1  2
        1	2	4	3               1   3   2          2  1
        1	3	2	4
        1	3	4	2
        1	4	2	3
        1	4	3	2*/
tbl_four::tbl_four(){}//ctor
tbl_four::~tbl_four(){}//dtor
tbl_four::tbl_four(const tbl_four& other){}//copy ctor
tbl_four& tbl_four::operator=(const tbl_four& rhs){   if (this == &rhs) return *this; return *this;}// handle self assignment//assignment operator

int tbl_four::psxy_change(string m_vec,int sizof)
{
 // cout<<"creating dynamic array of : " << sizof <<"\n";
  int x_arr[sizof];
//  cout<<"filling the array\n";
  int xi=0;
  char k;
  for(int i=0;i<=m_vec.size()-1;i++){
     k=m_vec.at(i);
     x_arr[xi]=stoi(&k);
     xi+=1;
  }
 // cout<<"manually changing positions \n";
  string mk;
  int xmk=0;
  if(sizof==4){
  mk.clear();
  mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[3]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[2]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[0]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[3]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[0]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[1]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[0]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[2]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[0]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[1]);
  mult.push_back(mk);
  mk.clear();
  //changing to 1
  mk.clear();
  mk+=to_string(x_arr[1]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[0]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[1]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[3]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[1]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[0]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[1]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[2]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[3]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[2]);
  mult.push_back(mk);
  //changing to 2
  mk.clear();
  mk+=to_string(x_arr[2]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[2]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[2]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[0]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[2]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[3]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[2]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[3]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[2]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[3]); mk+=to_string(x_arr[1]);
  mult.push_back(mk);
  //changing to 3
  mk.clear();
  mk+=to_string(x_arr[3]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[2]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[3]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[1]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[3]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[0]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[3]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[2]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[3]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]);
  mult.push_back(mk);
  mk.clear();
  mk+=to_string(x_arr[3]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]);
  mult.push_back(mk);
  mk.clear();
 // cout<<"inserting seperator as ||\n";
  mult.push_back("||");
  }
  if(sizof==3){
   mk.clear();
   mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[2]);
   mult.push_back(mk);
   mk.clear();
   mk+=to_string(x_arr[0]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[1]);
   mult.push_back(mk);
   mk.clear();
   //changing to 1
   mk.clear();
   mk+=to_string(x_arr[1]); mk+=to_string(x_arr[2]); mk+=to_string(x_arr[0]);
   mult.push_back(mk);
   mk.clear();
   mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[2]);
   mult.push_back(mk);
   mk.clear();
   mk.clear();
   mk+=to_string(x_arr[2]); mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]);
   mult.push_back(mk);
   mk.clear();
   mk+=to_string(x_arr[2]); mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]);
   mult.push_back(mk);
   mk.clear();
   //cout<<"inserting seperator as || \n";
   mult.push_back("||");
  }
  if(sizof==2){
    mk.clear();
    mk+=to_string(x_arr[0]); mk+=to_string(x_arr[1]);
    mult.push_back(mk);
    mk.clear();
    mk+=to_string(x_arr[1]); mk+=to_string(x_arr[0]);
    mult.push_back(mk);
    mk.clear();
  //  cout<<"inserting seperator as || \n";
    mult.push_back("||");
  }
  if(sizof==1){
  mk.clear();
  mk+=to_string(x_arr[0]);
  mult.push_back(mk);
  mk.clear();
 // cout<<"inserting seperator as || \n";
  mult.push_back("||");
  }
  return 0;
}

int tbl_four::dbl_fill(string m_vec,int sizof)
{
  string lk;
  lk.clear();
  lk+=m_vec;
  lk+=m_vec;
  crt_dbfill.clear();
  crt_dbfill+=lk;
 // cout<<"new value " << crt_dbfill <<"\n";

  return 0;
}
