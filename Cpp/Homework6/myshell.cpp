#include <iostream>
#include <cstdlib>

using namespace std;



int main()
{
    string Command;
    while(1)
    {
        cout<<"==>";
        cin>>Command;
        if(Command.compare("clr") == 0)
        {
            system("clear");
        }
        else if(Command.compare("dir") == 0)
        {
            system("ls -l");
        }
        else if(Command.compare("env") == 0)
        {
            system("env");
        }
        else if(Command.compare("quit") == 0)
        {
            exit(1);
        }

    }
    


    return 0;
}

