/*#include <stdio.h>
#include <string.h>

int main(){
    int store[6][2];
    int check[6][3], temp, swap, j, k, flag = 0, tar, w;
    while(scanf("%d", &store[0][0]) != EOF){
        memset(check, 0, sizeof(check));
        j = 1;
        scanf("%d", &store[0][1]);
        if(store[0][0] > store[0][1]){
            swap = store[0][0];
            store[0][0] = store[0][1];
            store[0][1] = swap;
        }
        check[0][0] = store[0][0];
        check[0][1] = store[0][1];
        for(int i = 1; i < 6; i++){
            scanf("%d %d", &store[i][0], &store[i][1]);
            if(store[i][0] > store[i][1]){
                swap = store[i][0];
                store[i][0] = store[i][1];
                store[i][1] = swap;
            }
            for(k = 0; k < 6; k++){
                if(store[i][0] == check[k][0] && store[i][1] == check[k][1]){
                    check[k][2]++;
                    break;
                }
            }
            if(k == 6){
                check[j][0] = store[i][0];
                check[j][1] = store[i][1];
                j++;
            }
        }
        k = 0;
        w = 0;
        for(int a = 0; a < 3; a++){
            temp = check[k][w];
            for(j = 0; j < 3; j++){
                if(temp == check[j][0] && k != j){
                    check[k][w] = -100;
                    k = j;
                    w = 1;
                    break;
                }
                if(temp == check[j][1] && k != j){
                    check[k][w] = -100;
                    k = j;
                    w = 0;
                    break;
                }
            }
            if(j == 3){
                flag = 1;
                break;
            }
        }
        if((check[0][2] == 1 && check[1][2] == 1 && check[2][2] == 1 && flag == 0) || (check[0][2] == 5 && flag == 0) || (check[0][2] == 2 && check[1][2] == 2 && flag == 0)){
            printf("POSSIBLE\n");
        }
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
                struct face{
                    int x, y;
                }a[6];
                bool check()
{
    if(memcmp(a, a+1, sizeof(face)) || memcmp(a+2, a+3, sizeof(face)) || memcmp(a+4, a+5, sizeof(face))) return false;
    if(a[0].x!=a[2].x || a[0].y!= a[4].x || a[2].y!=a[4].y) return false;
    // 排好序之后，就有固定的方法来判断是否可以组成立方体（有时候排序能适当的优化解决问题的方法）
    return true;
}
int main()
{
    while(cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> a[2].x >> a[2].y >> a[3].x >> a[3].y >> a[4].x >> a[4].y >> a[5].x >> a[5].y){
        for(int i = 0; i < 6; ++i)
            if(a[i].x < a[i].y)
                swap(a[i].x, a[i].y);
        sort(a, a+6, [](const face a, const face b) {return a.x==b.x ? (a.y > b.y) : (a.x > b.x);});
        printf("%s\n", check() ? "POSSIBLE" : "IMPOSSIBLE");
    }
    return 0;
}