#include <iostream>
#include <cstring>
using namespace std;
int set[32][32];
int find(int a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(set[i][j] == a)
                return i;
        }
    }
}
void inti(int a, int n){
    int pos = find(a, n);
    int y;
    for(int i = 0; i < n; i++)
        if(set[pos][i] == a){
            y = i + 1;
            break;
        }
    while(set[pos][y] != -1){
        set[set[pos][y]][0] = set[pos][y];
        set[pos][y] = -1;
        y++;
    }
}
void movea_to_b(int a, int b, int n){
    int posa = find(a, n), posb = find(b, n), ya, yb;
    for(int i = 0; i < n; i++)
        if(set[posa][i] == a){
            ya = i;
            break;
        }
    for(int i = 0; i < n; i++)
        if(set[posb][i] == -1){
            yb = i;
            break;
        }
    while(set[posa][ya] != -1){
        set[posb][yb++] = set[posa][ya];
        set[posa][ya++] = -1;
    }
}
int notsame(int a, int b, int n){
    int re = 0;
    int posa, posb;
    posa = find(a, n);
    posb = find(b, n);
    if(posa == posb)
        re = 1;
    return re;
}
int main(){
    int n;
    scanf("%d", &n);
    int a, b;
    char str1[10], str2[10];
    memset(set, -1, sizeof(set));
    for(int i = 0; i < n; i++){
        set[i][0] = i;
    }
    while(1){
        scanf("%s", str1);
        if(str1[0] == 'q')
            break;
        scanf("%d%s%d", &a, str2, &b);
        if(str1[0] == 'm'){
            if(str2[1] == 'n') {
                if(!notsame(a, b, n)){
                    inti(a, n);
                    inti(b, n);
                    movea_to_b(a, b, n);
                }
            }
            else{
                if(!notsame(a, b, n)){
                    inti(a, n);
                    movea_to_b(a, b, n);
                }
            }
        }
        else{
            if(str2[1] == 'n'){
                if(!notsame(a, b, n)){
                    inti(b, n);
                    movea_to_b(a, b, n);
                }
            }
            else{
                if(!notsame(a, b, n))
                    movea_to_b(a, b, n);
            }
        }
        getchar();
    }
    for(int i = 0; i < n; i++){
        printf("%d:", i);
        for(int j = 0; j < n; j++){
            if(set[i][j] == -1)
                break;
            printf(" %d", set[i][j]);
        }
        printf("\n");
    }
    return 0;
}