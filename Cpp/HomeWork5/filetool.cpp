#include "filetool.h"

using namespace std;

int main()
{
    file_Control D;
    D.show_menu();
    return 0;
}



void file_Control::show_menu(void)
{
    while(1)
    {
        if(this->Control_Data.compare("Start") == 0)
        {
            cout<<"***********************************************"<<endl;
            cout<<"0. 退出"<<endl;
            cout<<"1. 创建新文件"<<endl;
            cout<<"2. 写文件"<<endl;
            cout<<"3. 读文件"<<endl;
            cout<<"4. 修改文件权限"<<endl;
            cout<<"5. 查看当前文件的权限并退出"<<endl;
            cout<<"***********************************************"<<endl;
            cout<<"please input your choice(0-5)"<<endl;
            cin>>this->Control_Data;
        }
        else if(this->Control_Data.compare("0") == 0)
        {
            exit(1);
        }
        else if(this->Control_Data.compare("1") == 0)
        {
            cout<<"Please input your file name to create it."<<endl;
            cin>>this->filename;
            this->File.open(this->filename,ios::app);
            if(!this->File.is_open())
            {
                cout<<"Create error"<<endl;
            }
            else
            {
                cout<<"File Creation Success!"<<endl;
                this->File.close();
                this->Control_Data = "Start";
            }
        }
        else if(this->Control_Data.compare("2") == 0)
        {
            if(this->filename.size() > 0)
            {
                if(access(this->filename.c_str(),F_OK) == 0)
                {
                    this->File.open(this->filename,ios::app);
                    if(this->File.is_open())
                    {
                        cout<<"Please input your data to the file."<<endl;
                        cin>>this->Input_Data;
                        this->File<<this->Input_Data<<endl;
                        this->File.close();
                        this->Control_Data = "Start";                        
                    }
                }
                else 
                {
                    if (errno == ENOENT)
                    {
                        cout<<"your file don't exist!"<<endl;
                        this->Control_Data = "1";
                    }
                    else
                    {
                        cout<<"其他错误："<< strerror(errno)<<endl;
                        cout<<"请尝试修改权限"<<endl;
                        this->Control_Data = "4";
                    }
                }
            }
            else
            {
                cout<<"please input your filename"<<endl;
                cin>>this->filename;
            }
        }
        else if(this->Control_Data.compare("3") == 0)
        {
            if(this->filename.size() > 0)
            {
                if(access(this->filename.c_str(),R_OK) == 0)
                {
                    this->File.open(this->filename,ios::in);
                    if(this->File.is_open())
                    {
                        while (std::getline(this->File, this->Output_Data)) 
                        { // 逐行读取文件内容并输出
                            std::cout << this->Output_Data <<endl;
                        }
                        this->File.close();
                        this->Control_Data = "Start";
                    }
                }
                else 
                {
                    if (errno == ENOENT)
                    {
                        cout<<"your file don't exist!"<<endl;
                        this->Control_Data = "1";
                    }
                    else
                    {
                        cout<<"其他错误："<< strerror(errno)<<endl;
                        cout<<"请尝试修改权限"<<endl;
                        this->Control_Data = "4";
                    }
                }
            }
            else
            {
                cout<<"please input your filename"<<endl;
                cin>>this->filename;
            }
        }
        else if(this->Control_Data.compare("4") == 0)
        {
            if(this->filename.size() > 0)
            {
                if(stat(this->filename.c_str(),&this->file_state) == 0)
                {
                    int Temp;
                    mode_t mode;
                    cout<<"请输入你想修改的权限"<<endl;
                    cout<<"0700"<<endl;
                    cout<<"0400"<<endl;
                    cout<<"0200"<<endl;
                    cout<<"0100"<<endl;
                    cin>>Temp;
                    switch (Temp)
                    {
                        case 700:
                            if(chmod(filename.c_str(), S_IRWXU) == 0)
                            {
                                cout<<"成功"<<endl;
                            }
                            break;
                        case 400:
                            if(chmod(filename.c_str(), S_IRUSR) == 0)
                            {
                                cout<<"成功"<<endl;
                            }
                            break;
                        case 200:
                            if(chmod(filename.c_str(), S_IXUSR) == 0)
                            {
                                cout<<"成功"<<endl;
                            }
                            break;
                        case 100:
                            if(chmod(filename.c_str(), S_IWUSR) == 0)
                            {
                                cout<<"成功"<<endl;
                            }
                            break;
                        default:
                            break;
                    }
                    this->File.close();
                    this->Control_Data = "Start";
                    
                }
                else 
                {
                    if (errno == ENOENT)
                    {
                        cout<<"your file don't exist!"<<endl;
                        this->Control_Data = "1";
                    }
                    else
                    {
                        cout<<"其他错误："<< strerror(errno)<<endl;
                    }
                }
            }
            else
            {
                cout<<"请输入文件名："<<endl;
                cin>>this->filename;
            }
        }
        else if(this->Control_Data.compare("5") == 0)
        {
            if(this->filename.size() > 0)
            {
                if(stat(this->filename.c_str(),&this->file_state) == 0)
                {
                    cout << "当前文件权限：" << std::oct << (this->file_state.st_mode & 0777) << endl;
                    cout << "文件大小：" << this->file_state.st_size << " bytes" << endl;
                    cout << "文件修改时间：" << ctime(&this->file_state.st_mtime);
                    cout << "文件访问时间：" << ctime(&this->file_state.st_atime);
                    cout << "文件创建时间：" << ctime(&this->file_state.st_ctime);
                    this->File.close();
                    exit(0);
                }
                else 
                {
                    if (errno == ENOENT)
                    {
                        cout<<"your file don't exist!"<<endl;
                        this->Control_Data = "1";
                    }
                    else
                    {
                        cout<<"其他错误："<< strerror(errno)<<endl;
                    }
                }
            }
            else
            {
                cout<<"请输入文件名："<<endl;
                cin>>this->filename;
            }
        }
        else
        {
            cout<<"Wrong input !"<<endl;
            this->Control_Data = "Start";
        }

    }
 

}

