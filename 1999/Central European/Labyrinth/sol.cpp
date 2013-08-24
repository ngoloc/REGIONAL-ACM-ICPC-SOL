#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("mecung.in");
#define MAX 1001

int LOANG(char C[MAX][MAX],int m,int n,int xcu,int ycu,int x,int y,int& best){
    int i,Max=0,temp,h1,h2,h3,h4;
    int h[4];
    h[0]=h[1]=h[2]=h[3]=0;
    if(x-1>=1&&x-1!=xcu&&C[x-1][y]=='.'){
        temp=LOANG(C,m,n,x,y,x-1,y,best);
        h[0]=temp;
        if(Max<temp)
           Max=temp;
    }
    if(x+1<=m&&x+1!=xcu&&C[x+1][y]=='.'){
        temp=LOANG(C,m,n,x,y,x+1,y,best);
        h[1]=temp;
        if(Max<temp)
           Max=temp;
    }
    if(y-1>=1&&y-1!=ycu&&C[x][y-1]=='.'){
        temp=LOANG(C,m,n,x,y,x,y-1,best);
        h[2]=temp;
        if(Max<temp)
           Max=temp;
    }
    if(y+1<=n&&y+1!=ycu&&C[x][y+1]=='.'){
        temp=LOANG(C,m,n,x,y,x,y+1,best);
        h[3]=temp;
        if(Max<temp)
           Max=temp;
    }
    sort(h,h+4);
    if(best<h[2]+h[3])
       best=h[2]+h[3];
    return Max+1;
}

void proccess(){
    int i,j,n,m,x,y,best=0,found=false;//m dong, n cot
    char C[MAX][MAX];
    cin>>n>>m;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            cin>>C[i][j];
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
            if(C[i][j]=='.'){
               x=i;
               y=j;
               found=true;
               break;
            }
        if(found)
            break;
    }
    if(found)
        LOANG(C,m,n,-1,-1,x,y,best);
    cout<<"Maximum rope length is "<<best<<"."<<endl;
}

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        proccess();                
    }                               
//    system("pause");
    return 0;
}

