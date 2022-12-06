#include <gtest/gtest.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include "../tools/ssummary.h"
#include "../include/heavykeeper.h"
#include "../tools/BOBHash32.h"
#include "../tools/BOBHash64.h"
#include "../tools/params.h"
#include <pthread.h>
//using namespace std;
int hktest1(){
    
    int K=10;
    int hk_M;
    string x="1122334455667788";
    string y="2233445566778899";
    for (hk_M = 1; 32 * hk_M * HK_d + 432 * K <= 10 * 1024 * 8; hk_M++); if (hk_M % 2 == 0) hk_M--;
    heavykeeper* hk; hk = new heavykeeper(hk_M, K); hk->clear();
    hk->Insert(x);
    hk->Insert(y);
    hk->work();
    return hk->test1();   //插入一个、两个流，进行测试


}
int hktest2(){
    
    int K=10;
    int hk_M;
    string x="1122334455667788";
    for (hk_M = 1; 32 * hk_M * HK_d + 432 * K <= 10 * 1024 * 8; hk_M++); if (hk_M % 2 == 0) hk_M--;
    heavykeeper* hk; hk = new heavykeeper(hk_M, K); hk->clear();
    for(int i=0;i<10;i++) hk->Insert(x);
    hk->work();
    return hk->test2(x);     //tongji you duoshaoge 


}
int hktest3(){
    
    int K=2;
    int hk_M;
    string x="11223344";
    string y="22334455";
    for (hk_M = 1; 32 * hk_M * HK_d + 432 * K <= 10 * 1024 * 8; hk_M++); if (hk_M % 2 == 0) hk_M--;
    heavykeeper* hk; hk = new heavykeeper(hk_M, K); hk->clear();
    for(int i=0;i<10;i++) hk->Insert(x);
    hk->Insert(y);
    string z="33445566";
    hk->Insert(z);
    hk->work();
    return hk->test1();    //tongji tot


}
int hktest4(){
    
    int K=1;
    int hk_M;
    string x="11223344";
    
    for (hk_M = 1; 32 * hk_M * HK_d + 432 * K <= 10 * 1024 * 8; hk_M++); if (hk_M % 2 == 0) hk_M--;
    heavykeeper* hk; hk = new heavykeeper(hk_M, K); hk->clear();
    for(int i=0;i<23;i++) hk->Insert(x);
    string z="33445566"; //yu x zhiwen xiangtong   you keneng huibiancheng 9
    hk->Insert(z);
    hk->work();
    return hk->test2(x);  


}
int hktest5(){
    
    int K=1;
    int hk_M;
    string x="11223344";
    
    for (hk_M = 1; 32 * hk_M * HK_d + 432 * K <= 10 * 1024 * 8; hk_M++); if (hk_M % 2 == 0) hk_M--;
    heavykeeper* hk; hk = new heavykeeper(hk_M, K); hk->clear();
    for(int i=0;i<2;i++) hk->Insert(x);
    string z="33445566"; //yu x zhiwen xiangtong   you keneng huibiancheng 9
    hk->Insert(z);
    hk->work();
    return hk->test2(x);  
}
TEST(HKTEST,HKTEST1)
{
     EXPECT_EQ(hktest1(),2);
     EXPECT_EQ(hktest2(),10);
     EXPECT_EQ(hktest3(),2);
     if (hktest4()==23)
     EXPECT_EQ(hktest4(),23);
     else if(hktest4()==22)
     EXPECT_EQ(hktest4(),22);
     else EXPECT_FALSE(hktest4());
     if(hktest5()==2)
     EXPECT_EQ(hktest5(),2);
     else if(hktest5()==1)
     EXPECT_EQ(hktest5(),2);
     else EXPECT_FALSE(hktest5());
}
int main(int argc,char **argv)
{     
    
     testing::InitGoogleTest(&argc,argv);
     return RUN_ALL_TESTS();
}


