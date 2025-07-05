#include "strucker_mani.h"
#include "unknown_mpeite.h"
#include <iostream>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int xli=0;

strucker_mani::strucker_mani(int columns_hav){cout<<"creating structs with sum of them : " << columns_hav <<"\n";
columns_have=columns_hav;
p= (struct my_list*) malloc((columns_have+10) *sizeof(struct my_list));}//ctor
strucker_mani::~strucker_mani(){}//dtor
strucker_mani::strucker_mani(const strucker_mani& other){}//copy ctor
strucker_mani& strucker_mani::operator=(const strucker_mani& rhs){if (this == &rhs) return *this; return *this;}
// handle self assignment //assignment operator

int strucker_mani::struct_filler(string vlue,int col_ha,int col_end)
{
   //cout<<"using " << col_ha << " with " << col_end << " and vlue " << vlue <<"\n";
   string sl=" ";
   string vl="||";
   string slb="";
   int l=vlue.compare(sl);
   int x=vlue.compare(vl);
   int y=vlue.compare(slb) ;
   if(l!=0 && x!=0 && y!=0){
   //       cout<<"inserting " << l << " "<< x << " " << y <<" --> " << col_ha << " " << col_end << " "<< vlue <<"\n";
          p[col_ha].clm[col_end]=vlue;
   //       cout<<"i insert value " << p[col_ha].clm[col_end] <<"  @ " << col_ha << " and " << col_end <<"\n";
          }
   else{
   //cout<<"discarding value " << vlue <<"\n";
   }
   return 0;
}

int strucker_mani::plane_range(int columns,int rows){
 //   cout<<"columns " << columns <<" with rows "<< rows <<"\n";
    two_nti=(struct two_nti_plane*) malloc(columns_have *sizeof(struct two_nti_plane));
    two_nti[0].ar_start=1;
    two_nti[0].ar_end=24;
 //   cout<<"AR " << two_nti[0].ar_start << " " << two_nti[0].ar_end <<"\n";
    int x=1, y=24;
    int l=0,m=0;
    for(int i=1;i<=rows-1;i++){
        l=two_nti[i-1].ar_start+y;
        m=two_nti[i-1].ar_end+y;
        two_nti[i].ar_start=two_nti[i-1].ar_start+y;
        two_nti[i].ar_end=two_nti[i-1].ar_end+y;
        if(i==rows-1){
  //          cout<<"setting last range in i==rows\n";
            two_nti[i].ar_end=columns;
          }
          else{two_nti[i].ar_end=m;}
  //        cout<<"internal ranges " << l << " to " << m <<"\n";
          l+=1;
    }
    for(int i=0;i<=rows-1;i++){
        //cout<<i << " " << two_nti[i].ar_start<< " --> ";
        //cout << two_nti[i].ar_end <<"\n";
    }
    return 0;
}

int strucker_mani::joiner(){
   string flm;
   int x=0; //pos range start
   int y=23; //pos range end
   int pos_of_struct=0;
   int internal_pos_of_struct=0;
   string stmp;
  // cout<<"starting with value: " << p[0].clm[0]<<"\n";
   flm.clear();
   flm+=p[0].clm[0];
   string ax[150];int psh=0;int lxh=0;
  // cout<<"flm " << flm <<"\n";
   int xx=1,yy=1;
   int i=1;int ii=1;int lti=0;
   int lst_start=0;int lst_end=0;int ct=0;
   cout<<"semi parts ---------------\n";
   for(;;){
 //   cout<<"using x " << x <<"\n";
    for(i;i<=row_count-1;i++){
 //    cout<<"starting with " << i << "  and " << row_count <<"\n";
      if(i<row_count-1){
        while(two_nti[i].ar_start<=two_nti[i].ar_end){
  //       cout<<"i " <<i << " with " << two_nti[i].ar_start <<"\n";
         two_nti[i].ar_start+=1;
         flm+=p[i].clm[x];
   //      cout<<"setting flm as " << flm <<"\n";
         break;
        }
        }
        if(i==row_count-1){
    //     cout<<"last columns with flm " << flm <<"\n";
         if (ct==0){lst_start=two_nti[i].ar_start;
                   lst_end=two_nti[i].ar_end;
                   ct+=1;}
         if(lst_start!=0 && lst_end!=0 && ct==1 ){
           two_nti[i].ar_start=lst_start;
           two_nti[i].ar_end=lst_end;
           }
  //       cout<<"ADD " << two_nti[i].ar_start << " " << two_nti[i].ar_end <<"\n";
         while(two_nti[i].ar_start<=two_nti[i].ar_end){
    //       cout<<"i " <<i << " with " << two_nti[i].ar_start <<"\n";
           two_nti[i].ar_start+=1;
           ax[psh]+=flm;
           ax[psh]+=p[i].clm[lxh];
     //      cout<<"using the pattern " << ax[psh] <<"\n";
    //       cout<<"i insert " << p[i].clm[lxh] <<"\n";
           lxh+=1;
           psh+=1;
         }
      }
    }
   cout<<flm <<"\n";
   string slk=" ";
   string sli="";

   for(int i=0;i<=100;i++){
     if(ax[i].compare(slk)!=0 && ax[i].compare(sli)!=0){
       //cout<<"full value @ " << i << " is " << ax[i] <<"\n";
       //std::this_thread::sleep_for(std::chrono::milliseconds(550));
       full_value.push_back(ax[i]);
       }
   }
   flm.clear();
   flm+=p[0].clm[0];
   x+=1;
   lxh=0;
   psh=0;
   lti+=1;
   i=1;
   for(int i=0;i<=100;i++){ax[i].clear();}
   if(lti==10){break;}
  }
  cout<<"-----------\n";
return 0;
}

int strucker_mani::fvl_reader(){
  cout<<"Values are : \n";
  int lct=0;
  for(int i=0;i<=full_value.size()-1;i++){
    // cout<<"@ i " << i << " is " << full_value.at(i) <<"\n";
     lct+=1;
  }
return lct;
}

int strucker_mani::sub_levels(){
   for(int i=0;i<=full_value.size()-1;i++){
     //cout<<"@ i " << i << " is " << full_value.at(i) <<"\n";
     unknown_mpeite *unkmp = new unknown_mpeite(full_value.size()-1,full_value.at(i));
  }
 return 0;
}

int strucker_mani::struct_reader(int lkl){
   for(int i=0;i<=row_count;i++){ //columns_to_pass -1
      if(i<row_count){
    //   cout<<i << " smaller " <<"\n";
       for(int z=0;z<=23;z++){
            //l=stmn->p[i].clm[z].compare(sl);
            //x=stmn->p[i].clm[z].compare(vl);
            //yy=stmn->p[i].clm[z].compare(slb);
    //        //if(l!=0 && x!=0 && yy!=0){
       //       cout<<"returning " << i << "  with " << z << " and  " << p[i].clm[z] <<"\n";
            //  std::this_thread::sleep_for(std::chrono::milliseconds(750));
            //}
        }
        }
        if(i==row_count){
  //       cout<<i << " equal "<<"\n";
          for(int z=0;z<=lkl-1;z++){
  //          cout<<"returning g " << i << "  with " << z << " and  " << p[i].clm[z] <<"\n";
            // std::this_thread::sleep_for(std::chrono::milliseconds(750));
          }
        }
       // std::this_thread::sleep_for(std::chrono::milliseconds(750));
    }
  return 0;
}

int strucker_mani::peiramatik_mt(int start_range,int end_range,int arr_size,int t_f,int rows_per_column,int tim){
    std::mt19937 rng(std::time(0)); // `std::minstd_rand` would also work.
    std::uniform_int_distribution d(start_range,end_range); //0,38 the columns count
    int lx=0;
    int arrayr[arr_size]; //columns count
    if(lx==0){
         arrayr[lx]=d(rng);
         cout<<"for lx=0  value " << arrayr[lx] << "\n";
         lx+=1;
         }
    int startt=0,fndt=0,ct=0,value=0,t_pass=0;
    int brk=0,colm=0,rw=0,kp=0,lp=0;
    string lk;


    //for vector check;
    int vec_cnt=0;
    int str_vec=0;
    int vec_fnd=0;string ml_k;

    for(;;){
            lx=0;
            for(int i=0;i<=arr_size;i++){arrayr[lx]=-100;}
            cout<<"\n";
            arrayr[lx]=d(rng);cout<<"for lx=0 value " << arrayr[lx] << " with t_pass " << t_pass <<"\n";
            lx+=1;
            ct=0;brk=0;colm=0;rw=0;kp=0;lp=0;lk.clear();vec_fnd=0;str_vec=0;ml_k.clear();
        for(;;){
            startt=0;fndt=0;value=0;
            value=d(rng);str_vec=0;vec_fnd=0;ml_k.clear();
          //cout<<"|----------- ";
          //cout<<"value is " << value <<" ";
          //cout<<"|-----------|\n";
            while(startt<=lx){
                  if(arrayr[startt]==value){
                      fndt+=1;
                  //    cout<<" ------------------------------> found same number " << arrayr[startt] << " with drng " << value <<  " @ lx " << lx <<"\n";
                  }
                    startt+=1;
                    if(startt==lx){break;}
                  }
                  //cout<<" -----> exiting with fnd_times " << fndt <<"\n";
            if(fndt==0){
                 arrayr[lx]=value;lx+=1;ct+=1;
              //   cout<<"       -------> inserting unique value so far " << arrayr[lx-1] << " with drng " << value<<  " @ lx " << lx-1 <<"\n";
               //  cout<<"ct is " << ct <<"\n";
                 }
            if(ct==end_range){break;}
       }

       for(int i=0;i<=lx-1;i++){
          // cout<<"i " << i << " with value " << arrayr[i] <<"\n";
          brk+=1;
          if(brk%(rows_per_column-1)==1){
           //  cout<<"\n";
           //  cout<<"column " << colm <<" --> ";
             colm+=1;
           }
           //cout<<" rw " << rw << " vl " << arrayr[i] <<"  "  ;
           //cout <<mst[colm].ar[rw] <<" ";
           lp=(arrayr[i]/rows_per_column)*rows_per_column;
           kp=arrayr[i]-lp;
           //cout<<arrayr[i] << " " <<arrayr[i]/rows_per_column << " " << kp <<  " { "  ;
           //cout<<p[arrayr[i]/rows_per_column].clm[kp] << " } " ;
           lk+=p[arrayr[i]/rows_per_column].clm[kp];
           //cout<<p[arrayr[i]/rows_per_column].clm[kp] << "-" ;
           rw+=1;
       }
       //cout<<lk;

       if(vec_cnt>0){
          while(str_vec<vec_cnt){
              ml_k.clear();
              ml_k+=prmt_vl.at(str_vec);
              if(prmt_vl.at(str_vec).compare(lk)==0){vec_fnd+=1;}
              if(ml_k==lk){vec_fnd+=1;}
              if(ml_k.compare(lk)==0){vec_fnd+=1;}
              str_vec+=1;
              }
       }
       if(vec_fnd==0){prmt_vl.push_back(lk);vec_cnt+=1;}
       if(vec_fnd>0){cout<<"same value \n";}
       if(vec_cnt==0){prmt_vl.push_back(lk);vec_cnt+=1;}
       cout<<"\n";
    if(t_pass==t_f){break;}
    t_pass+=1;
    std::this_thread::sleep_for(std::chrono::milliseconds(tim));
}
prmt_cnt=vec_cnt;
return 0;
}

int strucker_mani::prmt_vl_show(int pmrt_ctn){
   for(int i=0;i<=pmrt_ctn-1;i++){
      cout<<"\n";
      cout<<i << " with value : " << prmt_vl.at(i) <<"\n";
   }
  return 0;
}




