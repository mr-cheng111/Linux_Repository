#include <iostream>
#include <unistd.h>
#include <csignal>
#include <sys/wait.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
using namespace std;

pid_t p1,p2;
int Kill_Flag = 0;
void signalHandler(int signum) 
{
    cout << "Received signal " << signum << endl;
    if (signum == SIGINT) 
    {
        Kill_Flag = 1;
    }
}
void sigHandler1(int signum)
{
    if(signum == SIGTERM)
    {
        cout<<"Child Process 1 is killed by parent!"<<endl;
        exit(0);
    }
}
void sigHandler2(int signum)
{
    if(signum == SIGTERM)
    {
        cout<<"Child Process 2 is killed by parent!"<<endl;
        exit(0);
    }
}
int main()
{
    p1 = fork();
    if(p1 == 0)
    {
        int Current_Process_ID = getpid();
        signal(SIGTERM,sigHandler1);
        signal(SIGINT,sigHandler1);
        while(1)
        {
            cout<<"child 1 is alive "<<endl;
            cout<<Current_Process_ID<<endl;
            sleep(1);
        }
    }
    else
    {
        p2 = fork();
        if( p2 == 0)
        {
            int Current_Process_ID = getpid();
            signal(SIGTERM,sigHandler2);
            signal(SIGINT,sigHandler2);
            while(1)
            {
                cout<<"child 2 is alive "<<endl;
                cout<<Current_Process_ID<<endl;
                sleep(1);
            }
        }
        else
        {
            string Temp_Data;
            signal(SIGINT,signalHandler);
            system("kill -l");
            while(1)
            {   
                if(Kill_Flag == 1)
                {
                    Kill_Flag = 0;
                    kill(p1,SIGTERM);
                    kill(p2,SIGTERM);
                    while (p1 != waitpid(p1,NULL,0) && p2 != waitpid(p2,NULL,0));
                    cout<<"Kill the parent"<<endl;
                    exit(1);
                }
            }
        }
    }
    return 0;
}



















