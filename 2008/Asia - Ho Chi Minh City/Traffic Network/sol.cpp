#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 10001
#define INF 1000000000

struct node{
     int v;
     int val;
};

int h[MAX];
int sh[MAX];
bool dx[MAX];

vector<node> S[MAX];
vector<node> T[MAX];
int SA[MAX];
int TA[MAX];

void UpdateHeap(int v,int d[],int h[],int sh[],int& shmax){
     int child,parent;
     if(!sh[v]){
          if(!shmax){
             h[++shmax]=v;
             sh[v]=shmax;
             return;
          }
          
          h[++shmax]=v;
          sh[v]=shmax;
          child=shmax;
          parent=shmax/2;
     }
     else{
          child=sh[v];
          parent=sh[v]/2;     
     }
     
     while(parent>0&&d[h[child]]<d[h[parent]]){
          swap(h[child],h[parent]);
          sh[h[parent]]=parent;
          sh[h[child]]=child;
          child=parent;
          parent/=2;
     }
}

int DeHeap(int d[],int h[],int sh[],int& shmax){
     int parent,leftchild,rightchild,child;
     int minnode=h[1];
     swap(h[1],h[shmax]);
     sh[h[1]]=1;
     sh[h[shmax]]=shmax;
     shmax--;
     if(!shmax)
          return minnode;
          
     parent=1;
     leftchild=parent*2;
     rightchild=parent*2+1;
     if(rightchild>shmax||d[h[rightchild]]>d[h[leftchild]])
        child=leftchild;
     else
        child=rightchild;
        
     while(child<=shmax&&d[h[parent]]>d[h[child]]){
        swap(h[parent],h[child]);
        sh[h[parent]]=parent;
        sh[h[child]]=child;
        parent=child;
        leftchild=parent*2;
        rightchild=parent*2+1;
        if(rightchild>shmax||d[h[rightchild]]>d[h[leftchild]])
            child=leftchild;
        else
            child=rightchild;
     }
     return minnode;
}

void dijkstra(vector<node> E[],int n,int s,int d[]){
    int shmax=0;
    int minnode;
    fill(h,h+MAX,0);
    fill(sh,sh+MAX,0);
    fill(dx,dx+MAX,false);
    for(int i=1;i<=n;i++){
        if(i==s)
           d[i]=0;
        else
           d[i]=INF;
        UpdateHeap(i,d,h,sh,shmax);
    }
    
    while(shmax>0){
       minnode=DeHeap(d,h,sh,shmax);
       dx[minnode]=true;
       for(vector<node>::iterator it=E[minnode].begin();it!=E[minnode].end();it++){
           if(!dx[it->v]&&d[it->v]>d[minnode]+it->val){
               d[it->v]=d[minnode]+it->val;
               UpdateHeap(it->v,d,h,sh,shmax);
           }
       }
    }
}

void process()
{
    int n,m,k,s,t;
    scanf("%d%d%d%d%d",&n,&m,&k,&s,&t);
    for(int i=0;i<MAX;i++)
    {   
        S[i].clear();
        T[i].clear();
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,c;
        node tmp;
        scanf("%d%d%d",&u,&v,&c);
        tmp.v = v;
        tmp.val = c;
        S[u].push_back(tmp);
        tmp.v = u;
        T[v].push_back(tmp);
    }

    dijkstra(S,n,s,SA);
    dijkstra(T,n,t,TA);
    int Min = SA[t];
    for(int i=1;i<=k;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        Min = min(Min,SA[u]+c+TA[v]);
        Min = min(Min,SA[v]+c+TA[u]);
    }
    if(Min==INF)
        cout<<-1<<endl;
    else
        cout<<Min<<endl;
}

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
        process();
    return 0;
}

