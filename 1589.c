#include <iostream>

using namespace std;
char board[11][10];
struct command{
    char c;
    int x1, y1;
}cmd[20];

void setboard(){
    memset(board, 'D', sizeof(board));
    for(int i = 1; i <= 3; i++){
        for(int j = 4; j <= 6; j++){
            board[i][j] = 'S';
        }
    }
}
void safeset(int n){
    struct command temp, pre = cmd[0];
    for(int i = 0; i < n; i++){
        if(cmd[i].c == 'C')
            pre = cmd[i];
    }
    for(int i = 0; i < n; i++){
        if(cmd[i].c == 'R' || cmd[i].c == 'G'){
            int xut = 0, ylt = 0, xdt = 10, yrt = 9;
            for(int j = 0; j < n; j++){
                if(cmd[j].y1 == cmd[i].y1){
                    if(cmd[j].x1 > xut && cmd[j].x1 < cmd[i].x1)
                        xut = cmd[j].x1;
                    if(cmd[j].x1 < xdt && cmd[j].x1 > cmd[i].x1)
                        xdt = cmd[j].x1;
                }
                if(cmd[j].x1 == cmd[i].x1){
                    if(cmd[j].y1 < cmd[i].y1 && cmd[j].y1 > ylt)
                        ylt = cmd[j].y1;
                    if(cmd[j].y1 > cmd[i].y1 && cmd[j].y1 < yrt)
                        yrt = cmd[j].y1;
                }
            }
            for(int j = xut; j <= xdt; j++)
                board[j][cmd[i].y1] = 'D';
            for(int j = ylt; j<= yrt; j++)
                board[cmd[i].x1][j] = 'D';
            board[cmd[i].x1][cmd[i].y1] = 'S';
        }
        if(cmd[i].c == 'H'){
            int left = 0, right = 0, top = 0, down = 0;
            for(int j = 0; j < n; j++){
                if(cmd[i].y1 + 1 == cmd[j].y1)
                    right = 1;
                if(cmd[i].y1 - 1 == cmd[j].y1)
                    left =1;
                if(cmd[i].x1 - 1 == cmd[j].x1)
                    top = 1;
                if(cmd[i].x1 + 1 == cmd[j].x1)
                    down = 1;
            }
            if(right != 1){
                board[cmd[i].x1 + 1][cmd[i].y1 + 2] = 'D';
                board[cmd[i].x1 - 1][cmd[i].y1 + 2] = 'D';
            }
            if(left != 1){
                board[cmd[i].x1 + 1][cmd[i].y1 - 2] = 'D';
                board[cmd[i].x1 - 1][cmd[i].y1 - 2] = 'D';
            }
            if(top != 1){
                board[cmd[i].x1 - 2][cmd[i].y1 + 1] = 'D';
                board[cmd[i].x1 - 2][cmd[i].y1 - 1] = 'D';
            }
            if(down != 1){
                board[cmd[i].x1 + 2][cmd[i].y1 + 1] = 'D';
                board[cmd[i].x1 + 2][cmd[i].x1 - 1] = 'D';
            }
        }
        if(cmd[i].c == 'C'){
            int l1 = 0, l2 = 0, t1 = 0, t2 = 0, d1 = 10, d2 = 10, r1 = 9, r2 = 9;
            for(int j = 0; j < n; j++){
                if(cmd[j].y1 == cmd[i].y1){
                    if(cmd[j].x1 < cmd[i].x1 && cmd[j].x1 > t1){
                        t2 = t1;
                        t1 = cmd[j].x1;
                    }
                    else if(cmd[j].x1 < cmd[i].x1 && cmd[j].x1 > t2)
                         t2 = cmd[j].x1;
                    if(cmd[j].x1 < d1 && cmd[j].x1 > cmd[i].x1){
                        d2 = d1;
                        d1 = cmd[j].x1;
                    }
                    else if(cmd[j].x1 > cmd[i].x1 && cmd[j].x1 > d2)
                        d2 = cmd[j].x1;
                }
                if(cmd[j].x1 == cmd[i].x1){
                    if(cmd[j].y1 < cmd[i].y1 && cmd[j].y1 > l1){
                        l2 = l1;
                        l1 = cmd[j].y1;
                    }
                    else if(cmd[j].y1 < cmd[i].y1 && cmd[j].y1 > l2)
                        l2 = cmd[j].y1;
                    if(cmd[j].y1 < r1 && cmd[j].y1 > cmd[i].y1){
                        r2 = r1;
                        r1 = cmd[j].y1;
                    }
                    else if(cmd[j].y1 > cmd[i].y1 && cmd[j].y1 > r2)
                        r2 = cmd[j].y1;
                }
            }
            for(int j = t2 + 1; j <= t1; j++)
                board[j][cmd[i].y1] = 'D';
            for(int j = d1 + 1; j <= d2; j++)
                board[j][cmd[i].y1] = 'D';
            for(int j = l2 + 1; j <= l1; j++)
                board[cmd[i].x1][j] = 'D';
            for(int j = r1 + 1; j <= r2; j++)
                board[cmd[i].x1][j] = 'D';
        }
    }
}
int check(int x0, int y0){
    if(board[x0 - 1][y0] == 'D' && board[x0 + 1][y0] == 'D' && board[x0][y0 - 1] == 'D' && board[x0][y0 + 1] == 'D')
        return 0;
    else
        return 1;
}
void correctboard(int n){
    for(int i = 0; i < n; i++){
        board[cmd[i].x1][cmd[i].y1] = cmd[i].c;
    }
}
int main(){
    int n, x0, y0;
    char c;
    while(scanf("%d%d%d", &n, &x0, &y0) != EOF && n != 0){
        memset(cmd, 0, sizeof(cmd));
        for(int i = 0; i < n; i++){
            scanf("%c", &c);
            scanf("%c", &cmd[i].c);
            scanf("%d%d", &cmd[i].x1, &cmd[i].y1);
        }
        /*setboard();
        correctboard(n);
        for(int i = 1; i < 11; i++){
            for(int j = 1; j < 10; j++){
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        setboard();
        safeset(n);
        //correctboard(n);
        /*for(int i = 1; i < 11; i++){
            for(int j = 1; j < 10; j++){
                    printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
        if(check(x0,y0) == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}