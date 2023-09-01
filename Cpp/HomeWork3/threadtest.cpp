#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void Pr(int n,char c)
{
    for(int i = 0; i < n ; i++)
    {
        cout<<c;
    }
}




int main()
{
    thread P1(Pr,100000,'*'),P2(Pr,100000,'#');
    P1.join();
    P2.join();


    return 0;
}