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
#include <fstream>
#include <signal.h>
#include <string.h>
using namespace std;

int main()
{
    cout<<"Shell by 程允杰, type \"quit\" return to bash"<<endl;
    
    int n;
    string Temp_Data;
    string Command_Data1, Command_Data2;
    int old_fd = dup(STDOUT_FILENO);
    int New_fd = -1;
    int a = 0;
    while(1)
    {
        if (a == 1)
        {
            // 如果不需要将输出重定向到文件中，则将标准输出重定向到终端窗口
            dup2(old_fd, STDOUT_FILENO);
            std::cout << std::flush;
            cout << ">";
            cout.flush();
            dup2(New_fd, STDOUT_FILENO);
        }
        else
        {
            cout << ">";
        }

        
        getline(cin,Temp_Data);
        if((n = Temp_Data.find_first_of('|')) != string::npos)
        {   
            int fd[2];
            pipe(fd);//创建读写管道
            Command_Data1 = Temp_Data.substr(0, n);
            Command_Data2 = Temp_Data.substr( n + 1 );
            int p1 = fork();
            if( p1 == 0)//此为子进程
            {   
                close(fd[0]);
                dup2(fd[1],STDOUT_FILENO);//将写入变为fd[1]
                system(Command_Data1.c_str());
                cout.flush();
                exit(1);
            }
            else
            {
                close(fd[1]);
                int old_stdin = dup(STDIN_FILENO);
                dup2(fd[0],STDIN_FILENO);//将读出变为fd[0]
                waitpid(p1,NULL,0);
                system(Command_Data2.c_str());
                cout.flush();
                dup2(old_stdin,STDIN_FILENO);//恢复
                Temp_Data.empty();
                Command_Data1.empty();
                Command_Data2.empty();
                continue;
            }
        }
            else if( (n = Temp_Data.find_first_of('&')) != string::npos)
            {
                Command_Data1 = Temp_Data.substr(0, n);
                int p1 = fork();
                if( p1 == 0)//此为子进程
                {
                    system(Command_Data1.c_str());
                    cout.flush();
                    exit(1);
                }
                else
                {
                    while(p1 != waitpid(p1,NULL,0));
                    Command_Data1.empty();
                }
                Temp_Data.empty();
            }
            // else if( (n = Temp_Data.find_first_of('>')) != string::npos)
            // {
            //     Command_Data2 = Temp_Data.substr( n + 1 );
            //     New_fd = open(Command_Data2.c_str(),O_WRONLY | O_CREAT,0);
            //     dup2(New_fd,STDOUT_FILENO);
            //     system(Command_Data1.c_str());
            //     cout.flush();
            //     Temp_Data.empty();
            //     Command_Data1.empty();
            //     Command_Data2.empty();
            //     a = 1;
            // }
            else 
            {
                system(Temp_Data.c_str());
                cout.flush();
                Temp_Data.empty();
            }
        }
    return 0;
}





