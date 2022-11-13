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
#include "../include/spacesaving.h"
using namespace std;
 spacesaving::spacesaving(int M2,int K):M2(M2),K(K) {ss=new ssummary(M2); ss->clear();}
        void spacesaving::Insert(string x)
        {
            bool mon=false;
            int p=ss->find(x);
            if (p) mon=true;
            if (!mon)
            {
                int q;
                if (ss->tot<M2) q=1; else
                q=ss->getmin()+1;
                int i=ss->getid();
                ss->add2(ss->location(x),i);
                ss->str[i]=x;
                ss->sum[i]=q;
                ss->link(i,0);
                while(ss->tot>M2)
                {
                    int t=ss->Right[0];
                    int tmp=ss->head[t];
                    ss->cut(ss->head[t]);
                    ss->recycling(tmp);
                }
            } else
            {
                int tmp=ss->Left[ss->sum[p]];
                ss->cut(p);
                if(ss->head[ss->sum[p]]) tmp=ss->sum[p];
                ss->sum[p]++;
                ss->link(p,tmp);
            }
        }
        
        void spacesaving::work()
        {
            int CNT=0;
            for(int i=N;i;i=ss->Left[i])
                for(int j=ss->head[i];j;j=ss->Next[j]) {q[CNT].x=ss->str[j]; q[CNT].y=ss->sum[j]; CNT++; }
            sort(q,q+CNT,cmp);
        }
        pair<string ,int> spacesaving::Query(int k)
        {
            return make_pair(q[k].x,q[k].y);
        }
       // spacesaving::~spacesaving()
       // {

       // }