#include<iostream>
//#include<windows.h>
#include<sstream>
#include<vector>
using namespace std;

void loop()
{
     for(int i=0;i<2000000000;i++)
          for(int j=0;j<2000000000;j++);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //int start = ::GetTickCount();
    string s;
    int t;
    cin>>t;
    cin.ignore();
    for(int k=0;k<t;k++)
    {
        getline(cin,s);
        stringstream ss;
        ss<<s;
        vector<int> V;
        
        string ns;
        while(ss>>ns)
        {
            V.push_back(ns.length());
        }
        if(V.size()==0)
        {
            k--;
            continue;
        }
        int nL=0;
        int L = -1;
        int MaxL = 0;
        for(int i=0;i<V.size();i++)
        {
            if(L!=V[i])
            {
                 L = V[i];
                 nL = 1;
            }
            else
            {
                nL++;
            }
            MaxL = max(MaxL,nL);
        }
        cout<<MaxL<<endl;
        ss.clear();                     
    }
    
    //cout<<"Time: " << (::GetTickCount() - start)*0.001<<" s"<<endl;
    //loop();
    return 0;
}
