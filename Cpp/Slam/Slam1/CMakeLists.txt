#声明cmake最低版本

 cmake_minimum_required( VERSION 2.8 )

 #声明一个cmake工程

 project( HelloSlam )

 #添加可执行文件
 #语法：add_executable( 程序名  源码文件)
 add_executable( HelloSLAM Slam1.cpp )