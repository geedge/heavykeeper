#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include "../init/BOBHash32.h"
#include "../init/BOBHash64.h"
#include "../init/params.h"
#include "../init/ssummary.h"
#include "../include/cmsketch.h"
using namespace std;

 cmsketch::cmsketch(int M2,int K):M2(M2),K(K) {ss=new ssummary(K); ss->clear(); bobhash=new BOBHash64(1005);}


 void cmsketch::clear()
 {
      for (int i=0; i<cm_d; i++)
               for (int j=0; j<=M2+5; j++) cm[i][j].C=cm[i][j].FP=0;
 }
 unsigned long long cmsketch::Hash(string ST)
 {
      return (bobhash->run(ST.c_str(),ST.size()));
 }
 void cmsketch::Insert(string x)
 {
      bool mon=false;
            int p=ss->find(x);
            if (p) mon=true;
            int minv=9999999;
            unsigned long long H=Hash(x); int FP=(H>>48);
            for (int j = 0; j < cm_d; j++)
            {
                int Hsh = H % (M2 - (2 * cm_d) + 2 * j + 3);
                int c = cm[j][Hsh].C;
               // if (cm[j][Hsh].FP == FP)
               // {
                    if ( c <= ss->getmin())
                    cm[j][Hsh].C++;
                    minv = min(minv, cm[j][Hsh].C);
               // }

                //else if (cm[j][Hsh].C <= 0)
               // {
                //    cm[j][Hsh].FP = FP;
                 //   cm[j][Hsh].C = 1;
                 //   minv = max(minv, 1);
                //}
            }
            //if (!mon)
           //{
                if (minv-(ss->getmin())==1 || ss->tot<K)
                {
                    int i=ss->getid();
                    ss->add2(ss->location(x),i);
                    ss->str[i]=x;
                    ss->sum[i]=minv;
                    ss->link(i,0);
                    while(ss->tot>K)
                    {
                        int t=ss->Right[0];
                        int tmp=ss->head[t];
                        ss->cut(ss->head[t]);
                        ss->recycling(tmp);
                    }
                }
           // } 
//else
            //if (minv>ss->sum[p])
            //{
             //   int tmp=ss->Left[ss->sum[p]];
              //  ss->cut(p);
              //  if(ss->head[ss->sum[p]]) tmp=ss->sum[p];        //bool 
               // ss->sum[p]=minv;
               // ss->link(p,tmp);
         //  }
 }
 void cmsketch::work()
 {
      int CNT=0;
            for(int i=N;i;i=ss->Left[i])
                for(int j=ss->head[i];j;j=ss->Next[j]) {q[CNT].x=ss->str[j]; q[CNT].y=ss->sum[j]; CNT++; }
            sort(q,q+CNT,cmp);
 }
 pair<string,int> cmsketch::Query(int k)
 {
     return make_pair(q[k].x,q[k].y);
 }

 //cmsketch::~cmsketch()
 //{
     
 //}