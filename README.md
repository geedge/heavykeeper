**HeavyKeeper.README**



**配置要求**

linux 5.15.0

cmake 3.16

**安装步骤**

git clone https://git.mesalab.cn/zhangzhihao/heavykeeper.git


**文件目录说明**

HeavyKeeper中存放算法实现，include中存放算法声明，tools中属于工具库。

filetree

HeavyKeeper
 
    ├── CMakeLists
    
    ├──cmsketch.cpp
    
    ├──CSS.cpp
    
    ├──heavykeeper.cpp
   
    ├──LossyCounting.cpp
      
    ├──spacesaving.cpp

include

    ├──cmsketch.h
    
    ├──CSS.h
      
    ├──heavykeeper.h
    
    ├──LossyCounting.h
   
    ├──spacesaving.h

init
   
    ├──BOBHash32.cpp
   
    ├──BOBHash32.h
   
    ├──BOBHash64.cpp

    ├──BOBHash64.h
   
    ├──params.h
   
    ├──ssummary.cpp

    ├──ssummary.h

dataset
    
    ├──2016.dat
   
    ├──2018.dat

├──main.cpp

├──CMakeLists.txt


**部署**

无


**如何运行**



注意，数据集在dataset中，切勿泄露！
2016年数据集的五元组是8字节，可以在main3中直接运行；2018年的数据集是18字节，其中包含13字节五元组和5字节时间戳，运行时需要把5字节时间戳删掉，以免影响精确度。

需要在main中修改数据集的存储位置



`cd heavykeeper` //进入文件夹


`mkdir build`//建立文件夹接收cmake生成的文件

`cd build` 

`cmake ..`

`make`//编译成可执行文件main

`./main` //执行

输入MEM和K，可输出五种代码的对比结果

ssummary.h是草图代码，在优化的HeavyKeeper中使用

BOBHash32和BOBHash64的功能可以从http://burtleburtle.net/bob/hash/evahash.html  获取

**版权说明**

该项目签署了MIT 授权许可，详情请参阅 [LICENSE.txt](https://git.mesalab.cn/zhangzhihao/heavykeeper/-/blob/main/LICENSE.txt)

**作者**

中国科学院信息工程研究所-张智皓







