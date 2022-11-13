#pragma once
//#ifndef _cmsketch_H
//#define _cmsketch_H
#include "../init/params.h"
#define cm_d 5

#define rep(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
class cmsketch
{
     private:
        ssummary *ss;
        struct node {int C,FP;} cm[cm_d][MAX_MEM+10];
        BOBHash64 * bobhash;
        int K,M2;
     public:
         cmsketch(int M2,int K);
         void clear();
         unsigned long long Hash(string ST);
         void Insert(string x);
         struct Node {string x; int y;} q[MAX_MEM+10];
         static int cmp(Node i,Node j) {return i.y>j.y;}
         void work();
         pair<string ,int> Query(int k);
        // ~cmsketch();
};




//#endif