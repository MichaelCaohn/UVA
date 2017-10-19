#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

struct node {
    int r, c;
    int di;
    node(int r=0, int c=0, int dir=0):r(r),c(c),di(dir) {}
};

char* dirs = "NESW";
char* turns = "FLR";

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

char name[1000];
char temp[5];
int map[10][10][4][3];
int d[10][10][4];
node father[10][10][4];
int x0, y0, xt, yt;
char dir_s[10], dir;

vector <node> ve;

int inside(int r, int c){
    return (r <= 9 && r >= 1 && c <= 9 && c >= 1);
}
int to_pos(char c){
    return strchr(dirs, c) - dirs;
}
int to_dir(char c){
    return strchr(turns, c) - turns;
}
node deter(node& front, int i){
    int q = front.di;
    if(i == 1)
        q = (front.di + 3) % 4;
    if(i == 2)
        q = (front.di + 1) % 4;
    return node(front.r + dr[q], front.c + dc[q], q);
}
void print_path(node front){
    ve.clear();
    while(1){
        ve.push_back(front);
        if(d[front.r][front.c][front.di] == 0)
            break;
        front = father[front.r][front.c][front.di];
    }
    ve.push_back(node(x0, y0, to_pos(dir)));
    int count = 0;
    for(int i = ve.size() -1; i >= 0; i--){
        if(count % 10 == 0)
            printf(" ");
        printf(" (%d,%d)", ve[i].r, ve[i].c);
        if(++count % 10 == 0)
            printf("\n");
    }
    if(ve.size() % 10 != 0)
        printf("\n");
}
void bfs(){
    queue  <node> que;
    memset(d, -1, sizeof(d));
    node first (x0 + dr[to_pos(dir)], y0 + dc[to_pos(dir)], to_pos(dir));
    que.push(first);
    d[first.r][first.c][first.di] = 0;
    while(!que.empty()){
        node front = que.front();
        que.pop();
        if(front.r == xt && front.c == yt){
            print_path(front);
            return;
        }
        for(int i = 0; i < 3; i++){
            node v = deter(front, i);
            if(map[front.r][front.c][front.di][i] && inside(v.r, v.c) && d[v.r][v.c][v.di] < 0){
                father[v.r][v.c][v.di] = front;
                d[v.r][v.c][v.di] = d[front.r][front.c][front.di] + 1;
                que.push(v);
            }
        }
    }
    printf("  No Solution Possible\n");
}
int main(){
    while(scanf("%s%d%d%s%d%d", name, &x0, &y0, dir_s, &xt, &yt) == 6) {
        dir = dir_s[0];
        char a0, a1;
        memset(map, 0, sizeof(map));
        int x1, y1;
        while (scanf("%d", &x1) == 1 && x1) {
            scanf("%d", &y1);
            while (scanf("%s", temp) == 1 && temp[0] != '*') {
                a0 = temp[0];
                for (int i = 1; i < strlen(temp); i++) {
                    a1 = temp[i];
                    map[x1][y1][to_pos(a0)][to_dir(a1)] = 1;
                }
            }
        }
        /*cout << name << endl;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (map[i][j][k][l]) {
                            printf("[%d][%d][%d][%d]\n", i, j, k, l);
                        }
                    }
                }
            }
        }*/
        printf("%s\n", name);
        bfs();
    }
    return 0;
}