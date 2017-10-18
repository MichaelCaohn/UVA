#include <stdio.h>
#include <string.h>
struct element{
    char *s;
    int c;
};
int main(){
    struct element a[6];
    int bottle[9], min, pos;
    a[0].s = "BCG";
    a[1].s = "BGC";
    a[2].s = "CBG";
    a[3].s = "CGB";
    a[5].s = "GCB";
    a[4].s = "GBC";
    memset(bottle, sizeof(bottle), 0);
    while(scanf("%d", &bottle[0]) != EOF){
        for(int i = 1; i < 9; i++){
            scanf("%d", &bottle[i]);
        }
        a[0].c = bottle[3] + bottle[6] + bottle[2] + bottle[8] + bottle[4] + bottle[1];
        a[1].c = bottle[1] + bottle[2] + bottle[3] + bottle[5] + bottle[6] + bottle[7];
        a[2].c = bottle[0] + bottle[1] + bottle[4] + bottle[5] + bottle[6] + bottle[8];
        a[3].c = bottle[0] + bottle[1] + bottle[3] + bottle[5] + bottle[7] + bottle[8];
        a[5].c = bottle[0] + bottle[2] + bottle[3] + bottle[4] + bottle[7] + bottle[8];
        a[4].c = bottle[0] + bottle[2] + bottle[4] + bottle[5] + bottle[6] + bottle[7];
        min = a[0].c;
        pos = 0;
        for(int i = 1; i < 6; i++){
            if(min > a[i].c){
                min = a[i].c;
                pos = i;
            }
        }
        printf("%s %d\n", a[pos].s, a[pos].c);
    }
    return 0;
}