#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#define MAXN 1002
#define MAXL 101
#define oo 1000000000
ifstream fin("PRINT.IN");
int DOXAU[MAXN][MAXN];
int C[MAXN];//luu chieu dai cac tu
int A[MAXN][MAXL];
bool first;
    
void test(){
    string str,substr;
    stringstream ss;
    int L,W,i,j,k,temp;        
    int n=0;//so tu
    cin>>L>>W;
    cin.ignore();
    
    while(true){
        getline(cin,str);
        if(!str.length())
            break;
        ss<<str;
        while(ss>>substr)
            C[++n]=substr.length();
        ss.clear();
    }
    
    for(i=1;i<=n;i++){
        fill(A[i],A[i]+MAXL,oo);    
        fill(DOXAU[i],DOXAU[i]+MAXN,-1);
    }
    A[0][0]=0;
    for(i=1;i<=n;i++)
        A[0][i]=A[0][i-1]+W*W*W;
        
    for(i=1;i<=n+1;i++){
        first=true;
        for(j=i-1;j<=n;j++){
            if(i==j+1)
                 DOXAU[i][j]=W*W*W;  //dong trong
            else{
                 if(first)
                    temp=C[j];
                 else
                    temp+=C[j]+1;
                 first=false;
                 if((W-temp)*(W-temp)*(W-temp)<0)
                     break;
                 else
                     DOXAU[i][j]=(W-temp)*(W-temp)*(W-temp);
            }
        }
    }
    //lap cong thuc quy hoach dong
    //A[i][j]=min{A[k][j-1]+do xau tren 1 dong (tu thu k+1 -> tu thu i)}
    for(j=1;j<=L;j++)
        for(i=1;i<=n;i++)            //cach tinh toi uu cho i tu tren j dong
            for(k=0;k<=i;k++)
                 if(DOXAU[k+1][i]!=-1&&A[i][j]>A[k][j-1]+DOXAU[k+1][i])
                      A[i][j]=A[k][j-1]+DOXAU[k+1][i];
    if(A[n][L]==oo)
        cout<<-1<<endl;
    else    
        cout<<A[n][L]<<endl; 
}

int main(){
    int T;
    cin>>T;
    while(T--)
        test();
    //system("pause");
    return 0;
}

