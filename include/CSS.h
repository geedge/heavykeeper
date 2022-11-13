#pragma once
//#ifndef _CSS_H
//#define _CSS_H
#include "../init/params.h"

#define rep(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
class CSS
{
      private:
        int head[M+10],Next[M+10],M2,K;
        struct node {int wz; string ID;} ID_index[M+10];
        int R[MAX_MEM+10],Counter_Array[MAX_MEM+10],m,Last;
        int Value_Index[MAX_MEM+10];
        BOBHash32 * bobhash;
     public:
         CSS(int M2,int K);
         void clear();
         int  Hash(string ST);
         int Find(string x);
         void Change(int x,int y,int z);
         void Change(int x,int y,int z,string a);
         void Insert_Hash(int x,string y,int z);
         void Delete(int x,int y);
         void Insert(string x);
         struct Node {string x; int y;} q[MAX_MEM+10];
         static int cmp(Node i,Node j) {return i.y>j.y;}
         void work();
         pair<string ,int> Query(int k);
        // ~CSS();

};



//#endif
