#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <string.h>
#include <chrono>
#include <thread>

#include "cnter.h"
#include "brekaer.h"
#include "tbl_four.h"
#include "strucker_mani.h"
#include "unknown_mpeite.h"
#include "peiramatik_mt.h"

using namespace std;

int main(int argc ,char *argv[])
{
    string mynum;
    mynum.clear();
    cout<<"enter a value \n";
    mynum=argv[1];
    cout<<"enter times to pass\n";
    int tp=0;
    tp=stoi(argv[2]);
    cout<<"enter chrono sleep \n";
    int chr=0;
    chr=stoi(argv[3]);
    cout<<"u enter time to pass : " << tp <<"\n";
    cout<<"u enter number : " << mynum <<"\n";
    cnter *mycnt=new cnter();
    int r=mycnt->method_count(mynum);
    cout<<"i count the digits : " << r <<"\n";
    cout<<"breaking \n";
    brekaer *brk=new brekaer();
    int rr=brk->brk_times(mynum,r);
    int r_thr=brk->breaker(mynum,r,rr);
    int r_four=brk->sh_values();
    cout<<"copying vector to main\n";
    vector<string> cop_int;
    int li=0;
    for(int i=0;i<=brk->brk_ints.size()-1;i++){
      cop_int.push_back(brk->brk_ints.at(i));
  //    cout<<i << " " << cop_int.at(i) <<"\n";
      li+=1;
      //if(li==1){break;}
    }
    cout<<"recounting and passing to multi \n";
    tbl_four *tblf= new tbl_four();
    int rtbl=0;int rrtbl=0;
    int xi=0;
    for(int i=0;i<=cop_int.size()-1;i++){
        r=0;rtbl=0;
        if(cop_int.at(i)>="0"){
 //       cout<<"shuffling with " << cop_int.at(i) <<"\n";
        r=mycnt->method_count(cop_int.at(i));
        rtbl=tblf->psxy_change(cop_int.at(i),r);
        xi+=1;
        }
        //if(xi==5){break;}
    }
    cout<<"retrieving shuffles\n";
    int columns_to_pass=0;
    int tmp_row_count=0;
    for(int i=0;i<=tblf->mult.size()-1;i++)
    {
       //cout<<i << " with value " << tblf->mult.at(i) <<"\n";
       rrtbl=tblf->dbl_fill(tblf->mult.at(i),r);
       tblf->last_value_pos=i-1;
       string sl=" ";
       string vl="||";
       string slb="";
       int l=0,x=0,yy=0;
       l=tblf->mult.at(i).compare(sl);
       x=tblf->mult.at(i).compare(vl);
       yy=tblf->mult.at(i).compare(slb);
       if(l!=0 && x!=0 && yy!=0) {
          columns_to_pass+=1; //is the number of columns=structs=different possible number inbetween combination
         }
       if(x==0){tmp_row_count+=1;}
    }
    cout<<"da size is " << tblf->mult.size()-1 << "\n";
    cout<<"da columns is " << columns_to_pass <<"\n";
    cout<<"tmp row count " << tmp_row_count <<"\n";
    strucker_mani *stmn = new strucker_mani(columns_to_pass);
    //relooping
    int y=0;
    int z=0;
    string sl=" ";
    string vl="||";
    string slb="";
    int l=0,x=0,yy=0;
    int lkl=0;
    for(int i=0;i<=tblf->mult.size()-1;i++){
            l=tblf->mult.at(i).compare(sl);
            x=tblf->mult.at(i).compare(vl);
            yy=tblf->mult.at(i).compare(slb);
            if(l!=0 && x!=0 && yy!=0){
              //  cout<<"sending " << i << " with value " << tblf->mult.at(i) <<"\n";
                lkl=stmn->struct_filler(tblf->mult.at(i),y,z);
                }
            //std::this_thread::sleep_for(std::chrono::milliseconds(750));
       z+=1;
       if(x==0){y+=1;z=0;stmn->row_count+=1;}
    }
    //internal
    stmn->row_count=tmp_row_count;
    stmn->columns_count=columns_to_pass;
    //
    cout<<"\n";
    cout<<"@ " << tblf->last_value_pos << " with " << tblf->mult.at(tblf->last_value_pos) <<"\n";
    cout<<"\n";
    cout<<"returning struct @ main \n";
    cout<<"with row count " << stmn->row_count << " and column count " << stmn->columns_count<<"\n";
    stmn->struct_reader(lkl);
    cout<<"begging the shuffling \n";
    cout<<"using columns " << columns_to_pass << " rows " << stmn->row_count  <<"\n";
    cout<<"creating the ranges \n";
    stmn->plane_range(stmn->columns_count,stmn->row_count);
    cout<<"let joiner function do the work \n";
    stmn->joiner();
    //cout<<"the numbers: \n";
    //int mli=stmn->fvl_reader();
    //cout<<"the sub levels numbers: \n";
    //int mtlk=stmn->sub_levels();

    int lkmt=stmn->peiramatik_mt(0,stmn->columns_count,stmn->columns_count+2,tp,stmn->rows_per_column,chr);
    int prmt=stmn->prmt_vl_show(stmn->prmt_cnt);
    return 0;
}
