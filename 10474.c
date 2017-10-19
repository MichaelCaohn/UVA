#include <iostream>
#include <algorithm>

using namespace std;

int maxn  = 10000;
int pos(int a[], int find, int N){
    int get = 0;
    for(int i = 0; i < N; i++){
        if(a[i] == find){
            get = i + 1;
            break;
        }
    }
    return get;
}

int main(){
    int N, Q, find, kase = 1;
    int a[maxn];
    while(scanf("%d%d", &N, &Q) != EOF && N != 0){
        for(int i = 0; i < N; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a + N);
        printf("CASE# %d:\n", kase);
        kase++;
        for(int j = 0; j < Q; j++){
            scanf("%d", &find);
            int k = pos(a, find, N);
            if(k == 0)
                printf("%d not found\n", find);
            else
                printf("%d found at %d\n", find, k);
        }
    }
    return 0;
}