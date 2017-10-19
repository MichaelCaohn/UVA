#include <stdio.h>
#define maxn 23
int n;
int a[maxn]={0};
int leftn,k,m,a_1=1,a_2=-1;
int go(int p,int d,int l)
{
    while(l--)
    {
        do{p=(p+d+n-1)%n+1;}
        while(a[p]==0);
    }
    return p;
}
int main()
{
    while(scanf("%d%d%d",&n,&k,&m)==3&&n)
    {
        int p_1=n,p_2=1;
        leftn=n;
        for(int i=1;i<=n;i++)
            a[i]=i;
        while(leftn)
        {
            p_1=go(p_1,a_1,k);
            p_2=go(p_2,a_2,m);
            printf("%3d",p_1);
            leftn--;
            if(p_1!=p_2)
            {
                printf("%3d",p_2);
                leftn--;
            }
            a[p_1]=a[p_2]=0;
            if(leftn)
                printf(",");
        }
        printf("\n");
    }
}