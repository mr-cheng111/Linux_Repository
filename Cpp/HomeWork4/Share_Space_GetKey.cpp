#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <pthread.h>

using namespace std;

int main() 
{
    int shmid;
    char *shmaddr;
    char message[1024] = {'\0'};
    
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    // 创建共享内存
    shmid = shmget(1102,1024, IPC_CREAT | 0666);

    // 将共享内存附加到进程中
    shmaddr = (char*)shmat(shmid, NULL, 0);

    while(1)
    {
        cin>>message;
        if(strcmp(message,"Quit") == 0)
        {
            // 分离共享内存
            shmdt(shmaddr);
            // 删除共享内存
            shmctl(shmid, IPC_RMID, NULL);
            exit(1);
        }
        else
        {
            //获取进程锁
            pthread_mutex_lock(&mtx);
            // 写入数据到共享内存
            strcpy(shmaddr,message);
            pthread_mutex_unlock(&mtx);
        }
    }




    return 0;
}