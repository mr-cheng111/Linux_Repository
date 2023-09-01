#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <pthread.h>

#define KEY 1102 // 共享内存的key值

int main() {
    int shmid;
    char *shmaddr;
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    // 获取共享内存
    shmid = shmget(KEY, 0, 0);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // 将共享内存附加到进程中
    shmaddr = (char*)shmat(shmid, NULL, 0);
    if (shmaddr == (char*)-1) {
        perror("shmat");
        exit(1);
    }
    while(1)
    {
        pthread_mutex_lock(&mtx);
        // 读取共享内存中的数据
        printf("KeyData is: %s\n", shmaddr);
        pthread_mutex_unlock(&mtx);
    }


    // 分离共享内存
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    return 0;
}