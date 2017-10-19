#include <iostream>
#include <stack>
#include <cstring>
#include <string.h>

using namespace std;
const int maxn =110;
char ori[maxn][maxn];
int go[maxn][maxn];
int cnt, m, n;

void dfs(int x, int y, int id){
    if(x < 0 || x >= m || y < 0 || y >= n || ori[x][y] != '@' || go[x][y] != 0)
        return;
    go[x][y] = id;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i != 0 || j != 0)
                dfs(x + i, y + j, id);
        }
    }
}
int main(){
    while(scanf("%d%d", &m, &n) && m != 0){
        memset(go, 0, sizeof(go));
        cnt = 0;
        getchar();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf("%c", &ori[i][j]);
            }
            getchar();
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ori[i][j] == '@' && go[i][j] == 0){
                    dfs(i, j, ++cnt);
                }
            }
        }
        printf("%d\n", cnt);
        /*printf("\n");
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                printf("%c ", ori[i][j]);
            }
            printf("\n");
        }*/
    }
}