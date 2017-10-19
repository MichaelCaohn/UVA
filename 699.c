#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
using namespace std;
int sum[1000];
void build(int pos){
    int v;
    scanf("%d", &v);
    if(v == -1)
        return;
    sum[pos] += v;
    build(pos - 1);
    build(pos + 1);
}
int init(){
    int v;
    scanf("%d", &v);
    memset(sum, 0, sizeof(sum));
    if(v == -1)
        return 0;
    int pos = 500;
    sum[pos] = v;
    build(pos - 1);
    build(pos + 1);
    return 1;
}
int main(){
    int kase = 1;
    while(init()){
        int p = 0;
        while(sum[p] == 0)
            p++;
        printf("Case %d:\n%d", kase++, sum[p++]);
        while(sum[p] != 0)
            printf(" %d", sum[p++]);
        printf("\n\n");
    }
    return 0;
}