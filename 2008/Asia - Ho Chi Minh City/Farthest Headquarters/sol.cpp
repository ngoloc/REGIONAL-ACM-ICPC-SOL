#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#define INF 1000000000

struct gpoint
{
   double x;
   double y;
   double dis;
   double coeff;
};

gpoint G[30001];
gpoint M[30001];
int nG,nM;
gpoint GG[30001];
gpoint GM[30001];
int nGG,nGM;

double Distance(gpoint p1,gpoint p2)
{
     return sqrt((long double)(p2.x-p1.x)*(long double)(p2.x-p1.x)+(long double)(p2.y-p1.y)*(long double)(p2.y-p1.y));
}

int compare(const void* p1,const void* p2)
{
    gpoint* a = (gpoint*)p1;
    gpoint* b = (gpoint*)p2;
    if(a->coeff<b->coeff)
        return 1;
    if(a->coeff>b->coeff)
        return -1;
    if(a->dis>b->dis)
       return 1;
    if(a->dis<b->dis)
       return -1;
    return 0;
}

long double CCW(gpoint a,gpoint b,gpoint c)
{
    return (long double)(b.y - a.y)*(long double)(c.x - a.x) + (long double)(a.x - b.x)*(long double)(c.y - a.y);
}

void GrahamScan(gpoint S[],int nS,gpoint GS[],int& nGS)
{
    nGS = 0;
    double minY = INF;
    double left;
    int pos;
    for(int i=1;i<=nS;i++)
       if(minY>S[i].y)
       {
           minY = S[i].y;
           pos = i;
           left = S[i].x;
       }
       else if(minY == S[i].y && left>S[i].x)
            {
                  minY = S[i].y;
                  pos = i;
                  left = S[i].x;
            }
    swap(S[1],S[pos]);
    for(int i=2;i<=nS;i++)
    {
       S[i].dis = Distance(S[i],S[1]);
       S[i].coeff = (S[i].x-S[1].x)/S[i].dis;
    }
    GS[++nGS] = S[1];
    if(nS == 1)
        return;
    qsort(S+2,nS-1,sizeof(gpoint),compare);
    GS[++nGS] = S[2];
    for(int i=3;i<=nS;i++)
    {
        while(nGS>=2 && CCW(GS[nGS-1],GS[nGS],S[i])>=0)
            nGS--;
        GS[++nGS] = S[i];
    }
}

void process()
{
    nG = nM = 0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        if(c==0)
        {
             M[++nM].x = x;
             M[nM].y = y;
        }
        else
        {
             G[++nG].x = x;
             G[nG].y = y;
        }
    }
    GrahamScan(G,nG,GG,nGG);
    GrahamScan(M,nM,GM,nGM);
    double ret = 0;
    for(int i=1;i<=nGG;i++)
        for(int j=1;j<=nGM;j++)
            if(ret<Distance(GG[i],GM[j]))
               ret = Distance(GG[i],GM[j]);
    cout<<(int)ret<<endl;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
        process();
    return 0;    
}

