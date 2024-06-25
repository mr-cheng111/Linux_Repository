// #include <stdio.h>
// #include <algorithm>
// #include <string>
// #include <iostream>
// #include "opencv2/opencv.hpp"

// using namespace cv;
// using namespace std;

// int main(int argc,char **argv)
// {
//     cv::Mat img1 = imread("Test_Pic.jpg",cv::ImreadModes::IMREAD_COLOR);
//     if(img1.empty())
//     {
//         cout << "Can't open the img."<<endl;
//         return 0;
//     }
//     else
//     {
//         cout << "Pic continuous flag:" <<img1.isContinuous()<<endl;
//         img1.convertTo(img1,CV_8U);
//         resize(img1,img1,cv::Size(1080,720),0,0);
//         cout << "Pic continuous flag:" <<img1.isContinuous()<<endl;
//     }
//     imshow("",img1);
//     cout << img1.channels() << endl;
//     cout <<  hex << img1.at<int8_t>(100,100*img1.channels()) << endl;
//     for(int i = 0 ; i < img1.rows; i ++)
//     {
//         for(int i = 0 ; i < img1.rows; i ++)
//         {
//             //img1.at(i,j,);
//         }
//     }

//     waitKey(0);
    
//     return 0;
// }


#include <iostream>
using namespace std;

struct NodeList
{
    int num;
    NodeList *next;
    NodeList(int x) : num(x) {};
};

int main() 
{
    int n = 0,i = 1;
    while(cin >> n)
    {
        NodeList *Data = new NodeList(0);
        NodeList *Data_Head = Data;

        while(i < n)
        {
            Data->next = new NodeList(i);
            Data = Data->next;
            i++;
        }
        i = 1;

        Data->next = Data_Head;
        Data = Data_Head;

        while(Data->num != Data->next->num)
        {
            Data->next->next = Data->next->next->next;
            Data = Data->next->next;
        }

        cout << Data->num << endl;
    }

    return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <array>


// using namespace std;

// int main() 
// {
//     string s;
//     std::vector<string> S;

//     while(cin >> s)
//     {    
//         int j = 0;
    
//         for(int i = 0 ; i < s.length(); i++)
//         {
//             if(*(s.c_str() + i) == ' ' || *(s.c_str() + i) == '\n' )
//             {
//                 const char *s_begin = s.c_str() + j;
//                 string Temp(s_begin,i - j);
//                 S.push_back(Temp);
//                 j = i + 1;
//             }
//         }

//         const char *s_begin = s.c_str() + j;
//         string Temp(s_begin,s.length() - j);
//         S.push_back(Temp);
        
//         vector<string>str;
//         while(S.size() > 0)
//         {
//             string Data = S.back();
//             std::array<int,26> Code1 = {0};
//             std::array<int,26> Code2 = {0};
//             string temp_str;
//             for(int i = 0; i < Data.length(); i++)
//             {
//                 if(*(Data.c_str() + i) >= 'a' && *(Data.c_str() + i) <= 'z')
//                 {
//                     if(Code1.at(*(Data.c_str() + i) - 'a') == false)
//                     {
//                         Code1.at(*(Data.c_str() + i) - 'a') = true;
//                         temp_str.push_back(*(Data.c_str() + i));
//                     }
//                 }
//                 else if(*(Data.c_str() + i) >= 'A' && *(Data.c_str() + i) <= 'Z')
//                 {
//                     if(Code2.at(*(Data.c_str() + i) - 'A') == false)
//                     {
//                         Code2.at(*(Data.c_str() + i) - 'A') = true;
//                         temp_str.push_back(*(Data.c_str() + i));
//                     }
//                 }
//             }
//             str.push_back(temp_str);
//             S.pop_back();
//         }

//         while(str.size() > 0)
//         {
//             cout << string(str.back().c_str(),str.back().size()) << endl;
//             str.pop_back();
//         }
//     }

//     return 0;
// }
// // 64 位输出请用 printf("%lld")