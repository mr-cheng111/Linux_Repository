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
#define PORT 5000

struct Data_Pool_t
{
    char Data[1024];//接受的数据   
    int send_fd;//接收者
    char Name[20];
};

mutex mtx;
int sock_server_fd;
struct sockaddr_in server_addr;
int new_conn_fd = 0;
vector<int>fdbuff;
vector<Data_Pool_t> Data_Pool;
void Server_Thread(int _fd);
void Send_Data_Thread();
char* stringTointStar(string str);

int main()
{
    /*服务器初始化*/
    cout<<"服务器监听端口："<<PORT<<endl;
    sock_server_fd = socket(AF_INET,SOCK_STREAM,0);
    memset(&server_addr,0,sizeof(server_addr));
    //选择协议
    server_addr.sin_family = AF_INET;
    //绑定IP地址
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //绑定端口
    server_addr.sin_port = htons(PORT);

    bind(sock_server_fd,(struct sockaddr *)&server_addr,sizeof(struct sockaddr));
    //设置最大连接数：20人
    listen(sock_server_fd,20);
    cout<<"欢迎来到聊天室..."<<endl;
    sockaddr_in client_addr;
    socklen_t length;

    thread A(Send_Data_Thread);

    A.detach();
    
    while(1)
    {
        //阻塞检测是否有接入，当有新的接入的时候，创建线程进行服务
        new_conn_fd = accept(sock_server_fd, (struct sockaddr*)&client_addr, &length);
        if(new_conn_fd > 0)
        {
            fdbuff.push_back(new_conn_fd);
            thread P(Server_Thread,new_conn_fd);
            P.detach();
            new_conn_fd = 0;
        }
    }

    return 0;
}


void Server_Thread(int _fd)
{
    char Name[20];
    int temp_Counter = fdbuff.back();
    char recvbuf[1024];
    int recvlength;
    char* strl1 = "请输入你的名字:";
    send(_fd,strl1,26,0);
    cout<<"新用户加入..."<<endl;
    memset(recvbuf,0,sizeof(recvbuf));
    int num =recv(_fd, recvbuf, sizeof(recvbuf),0);
    memcpy(Name,recvbuf,sizeof(recvbuf));
    char* strl2 = "开始聊天吧!(输入\"quit\"离开聊天室)";
    send(_fd, (void *)strl2,37,0);
    memset(recvbuf,0,sizeof(recvbuf));
    while(1)
    {
        //接收到数据
        recvlength = recv(_fd, recvbuf, sizeof(recvbuf),0);
        //如果接收到数据，将数据设置好，然后转发到每个客户端
        if(recvlength > 0)
        {
            mtx.lock();
            cout<<Name<<":"<<recvbuf<<endl;
            if(strcmp(recvbuf,"quit") == 0)
            {
                exit(1);
            }
            //将数据转为临时数据
            Data_Pool_t Temp_Data;
            memcpy(Temp_Data.Data,recvbuf,sizeof(recvbuf));
            memcpy(Temp_Data.Name,Name,sizeof(Name));
            Temp_Data.send_fd = _fd;
            memset(recvbuf,0,sizeof(recvbuf));
            Data_Pool.push_back(Temp_Data);
            mtx.unlock();
        }

    }
}

void Send_Data_Thread(void)
{
    char Temp_Data[1024] = {'\0'};
    while(1)
    {   //检测当前是否有可发送数据
        if(Data_Pool.size() > 0)
        {            
            for(vector<Data_Pool_t>::iterator it1 = Data_Pool.begin(); it1 <= Data_Pool.end();)
            {
                if(it1 != Data_Pool.end() )
                {
                    for(vector<int>::iterator it2 = fdbuff.begin(); it2 <= fdbuff.end();)
                    {
                        mtx.lock();
                        
                        strcat(Temp_Data,Data_Pool.front().Name);
                        strcat(Temp_Data,":");
                        strcat(Temp_Data,Data_Pool.front().Data);
                        send(*it2,Temp_Data,sizeof(Temp_Data),0);
                        memset(Temp_Data,0,sizeof(Temp_Data));
                        mtx.unlock();
                        if(it2 == fdbuff.end())
                        {
                            break;
                        }
                        ++it2;
                    }
                }
                mtx.lock();
                std::swap(Data_Pool.front(),Data_Pool.back());
                Data_Pool.pop_back();
                mtx.unlock();
                if(it1 == Data_Pool.end())
                {
                    break;
                }
                ++it1;
            }
        } 
    }   
}
