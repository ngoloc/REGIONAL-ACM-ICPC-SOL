#include<iostream>
#include<string>
using namespace std;

bool dividable(string s,int n)
{
    int r = 0;
    for(int i=0;i<s.length();i++)
    {
        r = r*10 + s[i] - '0';
        r = r%n;
    }
    if(r==0)
       return true;
    return false;
}

void process()
{
    int n;
    cin>>n;
    string patt="";
    string s;
    while(patt.length()<200)
    {
       patt+="6";
       s = patt;
       if(dividable(s,n))
       {
           cout<<s<<endl;
           return;
       }
       for(int i=0;i<s.length();i++)
       {    s[i] = '8';
           if(dividable(s,n))
           {
               cout<<s<<endl;
               return;
           }
       }
    }
    cout<<-1<<endl;
}

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
        process();
    //system("pause");
    return 0;
}

