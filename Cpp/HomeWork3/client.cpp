#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <iostream>
#include <queue>
#include <mutex>
#include <thread>

using namespace std;
#define PORT  5000

vector<string> Send_Pool;
mutex mtx;
int Client_Close_Flag = 0;
void Socket_Thread(int _fd);
void Get_Data_Thread(void);
void Send_Data_Thread(int _fd);
int main()
{

    string IP;
    cout<<"请输入服务器IP地址:"<<endl;
    cin>>IP;
    int sock_client_fd = socket(AF_INET,SOCK_STREAM, 0);
    cout<<""<<endl;
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);  
    servaddr.sin_addr.s_addr = inet_addr(IP.data());  
 
    cout<<"套接字建立成功，正在连接服务器中..."<<endl;
    while(connect(sock_client_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        cout<<"Waiting for the connection..."<<endl;
    }
    cout<<"Connect Success!"<<endl;
 
    thread th1(Socket_Thread,sock_client_fd),th2(Send_Data_Thread,sock_client_fd);
    th1.detach();
    th2.detach();
    Get_Data_Thread();
    return 0;
}

void Socket_Thread(int _fd)
{
    int fd = _fd;
    char recvbuf[1024] = {'\0'};
    int recvlen = 0;
    while(true)
    {
        recvlen = recv(fd,recvbuf,sizeof(recvbuf),0);
        if(Client_Close_Flag == 1)
        {
            exit(1);
        }
        if(recvlen > 0)
        {
            cout<<recvbuf<<endl;
            memset(recvbuf,0,sizeof(recvbuf));
        }

    }
}

void Get_Data_Thread(void)
{
    char Temp_Data[1024] = {'\0'};
    while(1)
    {
        cin>>Temp_Data;
        if(strcmp(Temp_Data,"quit") == 0)
        {
            mtx.lock();
            //离开线程
            Client_Close_Flag = 1;
            mtx.unlock();
            cout<<"正在退出,请稍候..."<<endl;
            exit(1);
        }
        else
        {
            mtx.lock();
            Send_Pool.push_back(Temp_Data);
            memset(Temp_Data,0,sizeof(Temp_Data));
            mtx.unlock();
        }
    }
}

void Send_Data_Thread(int _fd)
{
    int fd = _fd;
    while(true)
    {
        if(Send_Pool.empty() == 0)
        {
            for(vector<string>::iterator it = Send_Pool.begin(); it != Send_Pool.end();)
            {
                mtx.lock();
                cout<<"你说："<<Send_Pool.back().data()<<endl;
                send(_fd,Send_Pool.back().data(),Send_Pool.back().length(),0);
                Send_Pool.pop_back();
                mtx.unlock();
                if(it == Send_Pool.end())
                {
                    break;
                }
                ++it;
                
            }
        }
    }
    
}






