#pragma once
//#ifndef _LossyCounting_H
//#define _LossyCounting_H
#include "../init/params.h"

#define rep(i,a,n) for(int i=a;i<=n;i++)
using namespace std;

class LossyCounting
{
    private:
        ssummary *ss;
        int K;
    public:
         LossyCounting(int K);
         void Insert(string x,int c);
         void clear(int c);
         struct Node {string x; int y;} q[MAX_MEM+10];
         static int cmp(Node i,Node j) {return i.y>j.y;}
         void work();
         pair<string ,int> Query(int k);
         //~LossyCounting();

    
};





//#endif