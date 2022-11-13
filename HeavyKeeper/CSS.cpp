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
# include "../include/CSS.h"
using namespace std;

CSS::CSS(int M2,int K):M2(M2),K(K) {bobhash=new BOBHash32(1001);}
void CSS::clear()
{
      Value_Index[0]=M2-1; ID_index[0].wz=-1;
      for (int i=0; i<M2; i++) R[i]=i,head[i]=i+1,ID_index[i+1].wz=i;
}
int CSS::Hash(string ST)
{
     return (bobhash->run(ST.c_str(),ST.size()))%M2;
}
int CSS::Find(string x)
{
            int X=Hash(x);
            int now=head[X];
            while (now && ID_index[now].ID!=x) now=Next[now];
            if (!now) return -1; else
            return ID_index[now].wz;
}
void CSS::Change(int x,int y,int z)
{
            int now=head[x];
            while (now && ID_index[now].wz!=y) now=Next[now];
            ID_index[now].wz=z;
}
 void CSS::Change(int x,int y,int z,string a)
 {
            int now=head[x];
            while (now && (ID_index[now].wz!=y || ID_index[now].ID!=a)) now=Next[now];
            ID_index[now].wz=z;
 }

 void CSS::Insert_Hash(int x,string y,int z)
 {
            ID_index[Last].ID=y; ID_index[Last].wz=z;
            Next[Last]=head[x];
            head[x]=Last;
 }

 void CSS::Delete(int x,int y)
        {
            if (ID_index[head[x]].wz==y) {Last=head[x]; head[x]=Next[head[x]]; return;}
            int now=head[x];
            while (now && ID_index[Next[now]].wz!=y) now=Next[now];
            Last=Next[now];
            Next[now]=Next[Next[now]];
        }

void CSS::Insert(string x)
        {
            int p=Find(x);
            if (p!=-1)
            {
                int Q=Counter_Array[p]+1;
                int z=Value_Index[Counter_Array[p]];
                if (z!=p)
                {
                    Change(R[z],z,p);
                    R[p]=R[z];
                    Value_Index[Counter_Array[p]]=z-1;
                }
                 else
                   if (z && Counter_Array[z-1]==Counter_Array[z]) Value_Index[Counter_Array[z]]=z-1; else Value_Index[Counter_Array[z]]=0;
                Value_Index[Q]=max(Value_Index[Q],z);
                R[z]=Hash(x);
                Counter_Array[z]=Q;
                Change(R[z],p,z,x);
            }
            else
            {
                Delete(R[0],0); int Q=Counter_Array[0]+1;
                int z=Value_Index[Counter_Array[0]];
                if (z)
                {
                    Change(R[z],z,0);
                    R[0]=R[z];
                    Value_Index[Counter_Array[0]]=z-1;
                } else
                  Value_Index[Counter_Array[0]]=0;
                Value_Index[Q]=max(Value_Index[Q],z);
                R[z]=Hash(x);
                Counter_Array[z]=Q;
                Insert_Hash(R[z],x,z);
            }
        }
        
        void CSS::work()
        {
           int CNT=0;
            for (int i=M2-1; i>=M2-K; i--)
            {
                int now=head[R[i]];
                while (1) {if (ID_index[now].wz==i) {q[CNT].x=ID_index[now].ID;q[CNT].y=Counter_Array[i]; CNT++; break;} now=Next[now]; }
            }
           sort(q,q+K,cmp);
        }

        pair<string ,int> CSS::Query(int k)
        {
            return make_pair(q[k].x,q[k].y);
        }

        //CSS::~CSS()
        //{
          
        //}