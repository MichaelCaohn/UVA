#include <iostream>
#include <cstring>

using namespace std;
char board[9][9];
int all[64][5];
void allow(char turn, int l){
    int pos = 0;
    memset(all, 0, sizeof(all));
    char tar;
    if(l%2 == 1){
        if(turn == 'W')
            tar = 'B';
        else
            tar = 'W';
    }
    else{
        if(turn == 'W'){
            turn = 'B';
            tar = 'W';
        }
        else{
            turn = 'W';
            tar = 'B';
        }
    }
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            if(board[i][j] == '-'){
                if(board[i][j + 1] == tar){
                    for(int k = j + 1; k < 9; k++){
                        if(board[i][k] == '-')
                            break;
                        else if(board[i][k] == turn){
                            if(all[pos - 1][0] != i || all[pos - 1][1] != j){
                                all[pos][0] = i;
                                all[pos][1] = j;
                                all[pos][2] = i;
                                all[pos][3] = k;
                                all[pos][4] = 1;
                                //printf("(%d,%d) ", i, j);
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if(board[i][j - 1] == tar){
                    for(int k = j - 1; k >= 1; k--){
                        if(board[i][k] == '-')
                            break;
                        else if(board[i][k] == turn){
                            if(all[pos - 1][0] != i || all[pos - 1][1] != j){
                                all[pos][0] = i;
                                all[pos][1] = j;
                                all[pos][2] = i;
                                all[pos][3] = k;
                                all[pos][4] = 2;
                                //printf("(%d,%d) ", i, j);
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if(board[i + 1][j] == tar){
                    for(int k = i + 1; k < 9; k++){
                        if(board[k][j] == '-')
                            break;
                        else if(board[k][j] == turn){
                            if(all[pos - 1][0] != i || all[pos - 1][1] != j){
                                all[pos][0] = i;
                                all[pos][1] = j;
                                all[pos][2] = k;
                                all[pos][3] = j;
                                all[pos][4] = 3;
                                //printf("(%d,%d) ", i, j);
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if(board[i - 1][j] == tar){
                    for(int k = i - 1; k >= 1; k--){
                        if(board[k][j] == '-')
                            break;
                        else if(board[k][j] == turn){
                            if(all[pos - 1][0] != i || all[pos - 1][1] != j){
                                all[pos][0] = i;
                                all[pos][1] = j;
                                all[pos][2] = k;
                                all[pos][3] = j;
                                all[pos][4] = 4;
                                //printf("(%d,%d) ", i, j);
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if(board[i + 1][j + 1] == tar){
                    for(int k = 1; k + i < 9 && k + j < 9; k++){
                        if(board[i + k][j + k] == '-')
                            break;
                        else if(board[i + k][j + k] == turn){
                            if(all[pos - 1][0] != i || all[pos - 1][1] != j){
                                all[pos][0] = i;
                                all[pos][1] = j;
                                all[pos][2] = k;
                                all[pos][3] = 1;
                                all[pos][4] = 5;
                                //printf("(%d,%d) ", i, j);
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if(board[i - 1][j - 1] == tar){
                    for(int k = 1; i - k > 0 && j - k > 0; k++){
                        if(board[i - k][j - k] == '-')
                            break;
                        else if(board[i - k][j - k] == turn){
                            if(all[pos - 1][0] != i || all[pos - 1][1] != j){
                                all[pos][0] = i;
                                all[pos][1] = j;
                                all[pos][2] = k;
                                all[pos][3] = 1;
                                all[pos][4] = 6;
                                //printf("(%d,%d) ", i, j);
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if(board[i + 1][j - 1] == tar){
                    for(int k = 1; i + k < 9 && j - k > 0; k++){
                        if(board[i + k][j - k] == '-')
                            break;
                        else if(board[i + k][j - k] == turn){
                            if(all[pos - 1][0] != i || all[pos - 1][1] != j){
                                all[pos][0] = i;
                                all[pos][1] = j;
                                all[pos][2] = k;
                                all[pos][3] = 1;
                                all[pos][4] = 7;
                                //printf("(%d,%d) ", i, j);
                                pos++;
                            }
                            break;
                        }
                    }
                }
                if(board[i - 1][j + 1] == tar){
                    for(int k = 1; i - k > 0 && j + k < 9; k++){
                        if(board[i - k][j + k] == '-')
                            break;
                        else if(board[i - k][j + k] == turn){
                            if(all[pos - 1][0] != i || all[pos - 1][1] != j){
                                all[pos][0] = i;
                                all[pos][1] = j;
                                all[pos][2] = k;
                                all[pos][3] = 1;
                                all[pos][4] = 8;
                                //printf("(%d,%d) ", i, j);
                                pos++;
                            }
                            break;
                        }
                    }
                }
            }
            else
                continue;
        }
    }
    if(all[0][4] == 0)
        printf("No legal move.\n");
}
void printallow(){
    int i = 0;
    while(all[i][4] != 0){
        if(all[i + 1][4] != 0)
            printf("(%d,%d) ", all[i][0], all[i][1]);
        else
            printf("(%d,%d)", all[i][0], all[i][1]);
        i++;
    }
    if(i != 0)
        printf("\n");
}
void count(){
    int w = 0, b = 0;
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            if(board[i][j] == 'B')
                b++;
            if(board[i][j] == 'W')
                w++;
        }
    }
    printf("Black - %2d White - %2d\n", b, w);
}
int mov(char turn, int x0, int y0, int *l){
    int i = 0, found = 0;
    if(*l %2 == 0){
        if(turn == 'W')
            turn = 'B';
        else
            turn = 'W';
    }
    while(all[i][4] != 0){
        if(all[i][0] == x0 && all[i][1] == y0){
            if(all[i][4] == 1){
                for(int j = all[i][1]; j <= all[i][3]; j++){
                    board[all[i][0]][j] = turn;
                    found = 1;
                }
            }
            else if(all[i][4] == 2){
                for(int j = all[i][1]; j >= all[i][3]; j--){
                    board[all[i][0]][j] = turn;
                    found = 1;
                }
            }
            else if(all[i][4] == 3){
                for(int j = all[i][0]; j <= all[i][2]; j++){
                    board[j][all[i][1]] = turn;
                    found = 1;
                }
            }
            else if(all[i][4] == 4){
                for(int j = all[i][0]; j >= all[i][2]; j--){
                    board[j][all[i][1]] = turn;
                    found = 1;
                }
            }
            else if(all[i][4] == 5){
                for(int j = 0; j <= all[i][2]; j++){
                    board[all[i][0] + j][all[i][1] + j] = turn;
                    found = 1;
                }
            }
            else if(all[i][4] == 6){
                for(int j = 0; j <= all[i][2]; j++){
                    board[all[i][0] - j][all[i][1] - j] = turn;
                    found = 1;
                }
            }
            else if(all[i][4] == 7){
                for(int j = 0; j <= all[i][2]; j++){
                    board[all[i][0] + j][all[i][1] - j] = turn;
                    found = 1;
                }
            }
            else if(all[i][4] == 8){
                for(int j = 0; j <= all[i][2]; j++){
                    board[all[i][0] - j][all[i][1] + j] = turn;
                    found = 1;
                }
            }
        }
        if(found == 1)
            break;
        i++;
    }
    return found;
}
void finalmov(char turn, int x0, int y0, int* l){
    if(mov(turn, x0, y0, l) == 0){
        *l = *l + 1;
        allow(turn, *l);
        mov(turn, x0, y0, l);
    }
    count();
}
void check(){
    int i = 0;
    while(all[i][4] != 0){
        printf("%d %d %d %d %d\n", all[i][0], all[i][1], all[i][2], all[i][3], all[i][4]);
        i++;
    }
}
void print(){
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main(){
    int num;
    char turn, act;
    char x0, y0;
    scanf("%d", &num);
    memset(board, '-', sizeof(board));
    getchar();
    while(num){
        int l = 0;
        for(int i = 1; i < 9; i++){
            for(int j = 1; j < 9; j++)
                scanf("%c", &board[i][j]);
            getchar();
        }
        //print();
        scanf("%c", &turn);
        //printf("%c\n", turn);
        getchar();
        while(scanf("%c", &act) != EOF){
            if(act == 'Q'){
                //printf("%c\n", act);
                print();
                break;
            }
            if(act == 'M'){
                scanf("%c%c", &x0, &y0);
                //printf("%c%c%c\n", act, x0, y0);
                finalmov(turn, x0 - '0', y0 - '0', &l);
                getchar();
                print();
            }
            if(act == 'L'){
                //printf("%c\n", act);
                getchar();
                l++;
                allow(turn, l);
                printallow();
            }
        }
        num--;
        getchar();
    }
    return 0;
}