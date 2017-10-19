#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
const int maxn = 105;
int n;
double x[maxn*2];
struct Building{
    int id;
    double x, y, w, d, h;
    bool operator < (const Building& rhs) const{
        return (x < rhs.x) || (x == rhs.x && y < rhs.y);
    }
}b[maxn];
bool cover(int i, double mx){
    return b[i].x <= mx && b[i].x + b[i].w >= mx;
}
bool visible(int i, double mx){
    if(!cover(i, mx))
        return false;
    for(int k = 0; k < n; k++){
        if(b[k].y < b[i].y && b[k].h >= b[i].h && cover(k, mx))
            return false;
    }
    return true;
}
int main(){
    int count = 0;
    while(scanf("%d", &n) == 1&& n){
        for(int i = 0; i < n; i++){
            scanf("%lf%lf%lf%lf%lf", &b[i].x, &b[i].y, &b[i].w, &b[i].d, &b[i].h);
            b[i].id = i + 1;
            x[i*2] = b[i].x;
            x[i*2 + 1] = b[i].x + b[i].w;
        }
        cout<<endl;
        /*for(int i=0;i<n;i++)
            cout<<b[i].id<<" "<<b[i].x<<" "<<b[i].y<<" "<<b[i].h<<" "<<b[i].d<<endl;*/
        sort(b, b+n);
        sort(x, x + 2*n);
        int m = unique(x, x + 2*n) - x;
        if(count++)
            printf("\n");
        printf("For map #%d, the visible buildings are numbered as follows:\n%d", count, b[0].id);
        for(int i = 1; i < n; i++){
            int q = 0;
            for(int j = 0; j < m - 1; j++)
                if(visible(i, (x[j] + x[j + 1])/2)){
                    q = 1;
                    break;
                }
            if(q)
                printf(" %d", b[i].id);
        }
        printf("\n");
    }
    return 0;
}
