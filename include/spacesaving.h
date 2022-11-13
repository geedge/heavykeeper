#pragma once
//#ifndef _spacesaving_H
//#define _spacesaving_H

#include "../init/params.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
class spacesaving
{
    private:
        ssummary *ss;
        int K,M2;
     public:
     spacesaving(int M2,int K);
     void Insert(string x);
     struct Node {string x; int y;} q[MAX_MEM+10];
     static int cmp(Node i,Node j) {return i.y>j.y;}
     void work();
     pair<string ,int> Query(int k);
     //~spacesaving();







};



//#endif