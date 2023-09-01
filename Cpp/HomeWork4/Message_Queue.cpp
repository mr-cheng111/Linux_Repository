#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>
using namespace std;

// 定义消息队列结构体
struct msg_buf {
    long mtype;
    char mtext[1024];
};

int main ()
{    
    // 创建消息队列
    key_t key = ftok("asad", 's');
    int msqid = msgget(key,IPC_CREAT | 0666);
    cout<<"msqid = "<<msqid<<" is prepare"<<endl;
    int pid = fork();
    if(pid == 0)
    {
        msg_buf msg;
        int PID = getpid();
        int recv_counter = 0;
        while(1)
        {
            // 接收消息
            msgrcv(msqid, &msg, sizeof(msg.mtext), 1, 0);
            if(recv_counter == 0)
            {
                // 接收消息
                cout<<"Process "<<PID<<" is Receiving: "<<msg.mtext<<endl;
                recv_counter++;
            }
            else if(recv_counter == 1)
            {
                // 接收消息
                cout<<"Process "<<PID<<" is Receiving: "<<msg.mtext<<endl;
                exit(0);
            }
        }
    }
    else 
    {
        int Send_Counter = 0;
        msg_buf msg;
        msg.mtype = 1;
        while(1)
        {
            if(Send_Counter == 0)
            {
                strcpy(msg.mtext, "This is Message 1"); 
                msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
                Send_Counter++;
            }
            else if(Send_Counter == 1)
            {
                strcpy(msg.mtext, "This is Message 2"); 
                msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
                Send_Counter++;
            }
            else 
            {
                if(waitpid(pid,NULL,WNOHANG) == pid)
                {
                    cout<<"msqid = "<<msqid<<" is to delete..."<<endl;
                    msgctl(msqid, IPC_RMID, NULL);
                    exit(1);
                }
            }
            sleep(1);
        }
    }
    
    return 0;
}





