#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int round, meet;
    int win, lose, len, flag, chance, appear;
    char ori[100], cmp[100];
    while(scanf("%d", &round) != EOF && round != -1){
        printf("Round %d\n", round);
        scanf("%s %s", ori, cmp);
        len = strlen(ori);
        chance = 7;
        win = lose = 0;
        for(int i = 0; i < strlen(cmp); i++){
            flag = 1;
            appear = 0;
            for(int k = 0; k < i; k++){
                if(cmp[k] == cmp[i]){
                    appear = 1;
                    break;
                }
            }
            if(appear)
                continue;
            for(int j = 0; j < strlen(ori); j++){
                if(ori[j] == cmp[i]){
                    len--;
                    ori[j] = ' ';
                    flag = 0;
                }
            }
            if(flag){
                chance--;
            }
            if(len == 0){
                win = 1;
                break;
            }
            if(chance == 0){
                lose = 1;
                break;
            }
        }
        if(win){
            printf("You win.\n");
        }
        else if(lose){
            printf("You lose.\n");
        }
        else
            printf("You chickened out.\n");
    }
    return 0;
}