#ifndef DCU_OPERATION
#define DCU_OPERATION

#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>
#include <string>
#include <thread>
#include <mutex>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

using namespace std;
class file_Control
{
    public:
        void show_menu(void);
        file_Control(void)
        {
            this->Control_Data = "Start";
        }
    private:
        string Control_Data;
        string filename;
        string Input_Data;
        string Output_Data;
        struct stat file_state;
        fstream File;


};



#endif