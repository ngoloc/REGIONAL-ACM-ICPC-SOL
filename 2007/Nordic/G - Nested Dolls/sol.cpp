#include<iostream>
using namespace std;
#define MAX 20001
struct doll{
    int w;
    int h;
};

int compare(const void* ele1,const void* ele2){
    doll x=*(doll*) ele1;
    doll y=*(doll*) ele2;
    if(x.h<y.h) return 1;
    if(x.h==y.h&&x.w>y.w) return 1;
    if(x.h==y.h&&x.w==y.w) return 0;
    return -1;
}

int BS(int begin,int end,int value,int A[]){
    if(begin==end)
        return begin;
    int mid=(begin+end)/2;
    if(A[mid]<=value)
        return BS(mid+1,end,value,A);
    else
        return BS(begin,mid,value,A);
}

void proccess(){
    doll C[MAX];
    int A[MAX];
    int n,tA=0;
    
    int i,pos;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&C[i].w,&C[i].h);
    qsort(C+1,n,sizeof(doll),compare);
    A[++tA]=C[1].w;
    for(i=2;i<=n;i++){
        pos=BS(1,tA,C[i].w,A);
        if(C[i].w>=A[pos])//khong tim thay vi tri thich hop
            A[++tA]=C[i].w;
        else
            A[pos]=C[i].w;
    }
    printf("%d\n",tA); 
}

int main(){
    int T;
    cin>>T;
    while(T--)
        proccess();
    return 0;
}

