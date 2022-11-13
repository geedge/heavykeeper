**HeavyKeeper.README**



**配置要求**

linux 5.15.0

cmake 3.16

**安装步骤**

git clone https://git.mesalab.cn/zhangzhihao/heavykeeper.git


**文件目录说明**

filetree
- Compare
    - CSS.h
    - LossyCounting.h
    - cmsketch.h
    - heavykeeper.h   
    - spacesaving.h
- dataset
    - 2016.dat
    - 2018.dat
- BOBHash32.h
- BOBHash64.h
- CMakeList.txt
- main3.cpp
- params.h
- ssummary.h
- LICENSE.txt

**部署**

无


**如何运行**

下载后将compare中的文件与外部文件放到一个文件夹，可在linux中直接运行，也可以建立共享文件夹运行。

注意，数据集在dataset中，切勿泄露！
2016年数据集的五元组是8字节，可以在main3中直接运行；2018年的数据集是18字节，其中包含13字节五元组和5字节时间戳，运行时需要把5字节时间戳删掉，以免影响精确度。

需要在main3中修改数据集的存储位置
以linux运行为例，所有文件在enjoy的文件夹中


`cd enjoy` //进入文件夹

`cp -r ./Compare/* ./`  //复制文件

`mkdir build`//建立文件夹接收cmake生成的文件

`cd build` 

`cmake ..`

`make`//编译成可执行文件main3

`./main3` //执行

输入MEM和K，可输出五种代码的对比结果

ssummary.h是草图代码，在优化的HeavyKeeper中使用

BOBHash32和BOBHash64的功能可以从http://burtleburtle.net/bob/hash/evahash.html  获取

**版权说明**

该项目签署了MIT 授权许可，详情请参阅 [LICENSE.txt](https://git.mesalab.cn/zhangzhihao/heavykeeper/-/blob/main/LICENSE.txt)

**作者**

中国科学院信息工程研究所-张智皓







