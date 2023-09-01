#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <mutex>
#include <string.h>
#include<signal.h>
using namespace std;

string S;
mutex mtx;
#define WaitTime 10
void handler(int sig)
{ 
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;
}
int myshell_nowait()
{
    pid_t p1;
    int i = 0;
	p1 = fork();
	while(1)
	{
		if( p1 == 0)//此为子进程
		{
			if(!S.empty())
			{
				cout<<S<<endl;
				// S.clear();
			}
		}
		else //此为父进程
		{
			mtx.lock();
			cin>>S;
			mtx.unlock();
		}
	}

}


int main(int argc,char **argv)
{
    myshell_nowait();
    return 0;
}







