#pragma once
//ifndef _heavykeeper_H
//#define _heavykeeper_H
#include "../init/params.h"

#define HK_d 2
#define HK_b 1.08
#define rep(i,a,n) for(int i=a;i<=n;i++)
using namespace std;

class heavykeeper
{
    private:
        ssummary *ss;
        struct node {int C,FP;} HK[HK_d][MAX_MEM+10];
        BOBHash64 * bobhash;
        int K,M2;
     public:
     heavykeeper(int M2, int K);
     void clear();
     unsigned long long Hash(string ST);
     void Insert(string x);
     struct Node {string x; int y;} q[MAX_MEM+10];
     static int cmp(Node i,Node j) {return i.y>j.y;}
     void work();
     pair<string ,int> Query(int k);
     //~heavykeeper();





};


//#endif