#pragma once
//#ifndef _ssummary_H
//#define _ssummary_H

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include "BOBHash32.h"
#include "params.h"
#define len2 9973
#define rep(i,a,n) for(int i=a;i<=n;i++) 
class ssummary
{
    public:
        int tot;
        int sum[M+10],K,last[M+10],Next[M+10],ID[M+10];
        int head[N+10],Left[N+10],Right[N+10],num;
        string str[M+10];
        int head2[len2+10],Next2[M+10];
        BOBHash32 * bobhash;

        ssummary(int K);
        void clear();
        int getid();
        int location(string ST);
        void add2(int x,int y);
        int find(string s);
        void linkhead(int i,int j);
        void cuthead(int i);
        int getmin();
        void link(int i,int ww);
        void cut(int i);
        void recycling(int i);
       // ~ssummary();
};





//#endif