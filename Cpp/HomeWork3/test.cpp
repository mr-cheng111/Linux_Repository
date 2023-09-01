#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char* stringToCharStar(string str);
int main()
{

    char s[1024] = "你好！            程允杰杰";
    cout << s << endl;


    return 0;
}

char* stringToCharStar(string str) 
{
    char* c = new char[str.length() + 1];
    strcpy(c, str.c_str());
    return c;
}