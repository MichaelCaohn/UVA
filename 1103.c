#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string dict[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
char tab[256][256];
char alp[8] = {'W', 'A', 'K', 'J', 'S', 'D'};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int h, w, cnt;
void dfs1(int x, int y){
    if(x < 0 || x > h + 1 || y < 0 || y > w + 1 || tab[x][y] != '0')
        return;
    tab[x][y] = '-';
    for(int i = 0; i < 4; i++)
        dfs1(x + dx[i], y + dy[i]);
}

void dfs2(int x, int y){
    if(x < 0 || x > h + 1 || y < 0 || y > w + 1 || tab[x][y] != '1')
        return;
    tab[x][y] = '-';
    for(int i = 0; i < 4; i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(tab[x1][y1] == '0'){
            cnt++;
            dfs1(x1, y1);
        }
        else
            dfs2(x1, y1);
    }
}
int main(){
    int kase = 0;
    while(scanf("%d%d", &h, &w) && h != 0){
        w *= 4;
        string tar, fin;
        memset(tab, '0', sizeof(tab));
        for(int i = 1; i <= h; i++){
            cin >> tar;
            int k = tar.length();
            string temp = "";
            int p;
            for(int j = 0; j < k; j++){
                if(tar[j] >= 'a' )
                    p = tar[j] - 'a' + 10;
                else
                    p = tar[j] - '0';
                temp = temp + dict[p];
            }
            memcpy(tab[i] + 1, temp.c_str(), w);
        }
        /*for(int i = 0; i <= h; i++){
            for(int j = 0; j <= w; j++){
                printf("%c", tab[i][j]);
            }
            printf("\n");
        }*/
        dfs1(0, 0);
        vector <char> v;
        /*printf("\n");
        for(int i = 0; i <= h; i++){
            for(int j = 0; j <= w; j++){
                printf("%c", tab[i][j]);
            }
            printf("\n");
        }*/
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                if(tab[i][j] == '1'){
                    cnt = 0;
                    fin = "";
                    dfs2(i, j);
                    v.push_back(alp[cnt]);
                    /*fin = fin + string(alp[cnt]);
                    cout << fin  << " " << cnt << endl;
                    printf("%c", alp[cnt]);*/
                }
            }
        }
        printf("Case %d: ", ++kase);
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            printf("%c", v[i]);
        }
        printf("\n");
    }
}