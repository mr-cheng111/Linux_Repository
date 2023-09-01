#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main(int argc,char **argv)
{
    execl("/bin/ls","ls",NULL);
    cout<<"hello"<<endl;
    return 0;
}







