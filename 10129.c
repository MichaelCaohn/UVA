#include<iostream>
#include <string.h>
#include <cstring>
using namespace std;
const int maxn = 1005;
int sub_nu;
int colle[maxn][maxn], vis[maxn], in[maxn], out[maxn];

void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < maxn; i++){
        if(colle[u][i]>0){
            colle[u][i]--;
            colle[i][u]--;
            dfs(i);
        }
    }
}
bool check_dfs(){
    for(int i = 0; i < maxn; i++){
        if(in[i] + out[i]){
            //printf(" %d %d %d\n", i, in[i] + out[i], vis[i]);
            if(vis[i] == 0)
                return false;
        }
    }
    return true;
}
bool check_euler(){
    int start = 0;
    int end = 0;
    for(int i = 0; i < maxn; i++){
        if(in[i] != out[i]){
            if(in[i] == out[i] + 1 && end == 0)
                end = 1;
            else if(in[i] == out[i] - 1 && start == 0)
                start = 1;
            else
                return false;
        }
    }
    return true;
}

int main(){
    int nu, star;
    scanf("%d", &nu);
    while(nu--){
        scanf("%d", &sub_nu);
        memset(colle, 0, sizeof(colle));
        memset(vis, 0, sizeof(vis));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for(int i = 0; i < sub_nu; i++){
            char f[10005];
            scanf("%s", f);
            int u = f[0] - 'a';
            int v = f[strlen(f) - 1] - 'a';
            colle[u][v]++;
            colle[v][u]++;
            in[u]++;
            out[v]++;
            star = u;
        }
        /*for(int i = 0; i < sub_nu; i++){
            printf("%s\n", colle[i]);
        }
        printf("\n");*/
        dfs(star);
        if(check_euler() && check_dfs())
            printf("Ordering is possible.\n");
        else
            printf("The door cannot be opened.\n");
    }
}