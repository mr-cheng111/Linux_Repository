#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

#define WaitTime 10
int myshell_nowait()
{
    pid_t p1;
    int i = 0;
    p1 = fork();
    if( p1 == 0)//此为子进程
    {
        //获取子进程pid
        p1 = getpid();
        cout<<"Child_Process_Pid = "<<p1<<endl;
        while(i < WaitTime)
        {
            i++;
            sleep(1);
        }
        exit(1);
    }
    else //此为父进程
    {
        //获取父进程pid
        p1 = getpid();
        cout<<"Father_Process_Pid = "<<p1<<endl;
    }
    return p1;
}


int myshell_wait()
{
    pid_t p1;
    int i = 0;
    p1 = fork();
    if( p1 == 0)//此为子进程
    {
        //获取子进程pid
        p1 = getpid();
        cout<<"Child_Process_Pid = "<<p1<<endl;
        while(i < WaitTime)
        {
            i++;
            cout<<"Tick = "<<i<<endl;
            sleep(1);
        }
        exit(1);
    }
    else //此为父进程
    {
        pid_t p2;
        p2 = waitpid(p1,NULL,0);
        cout<<"Child_Process_Pid = "<<p2<<endl;
        //获取父进程pid
        p1 = getpid();
        cout<<"Father_Process_Pid = "<<p1<<endl;
        
    }
    return p1;
}

int main(int argc,char **argv)
{
    string Control_Data;
    cout<<"Please input Parameter : \"wait\" or \"nowait\""<<endl;
    cin>>Control_Data;
    //当不输入正确参数时，输出提示
    if(Control_Data != "nowait" && Control_Data != "wait")
    {
        cout<<"Need more Parameter : \"wait\" or \"nowait\"";
        return 0 ;
    }
    else //当输入参数为nowait时，创建子进程
    {
        //不等待
        if(Control_Data == "nowait")
        {
            myshell_nowait();
        }
        else if(Control_Data == "wait")
        {
            myshell_wait();
        }
    }
    return 0;
}







