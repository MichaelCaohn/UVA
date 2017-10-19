#include <iostream>
#include <string>
#include <string.h>

using namespace std;
int G[1010][1010];

int meet(){
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            if(G[i][j] != 0)
                return 0;
        }
    }
    return 1;
}
int main(){
    int count;
    while(scanf("%d", &count) && count){
        int org, tar;
        memset(G, 0, sizeof(G));
        while(count--){
            scanf("%d%d" ,&org, &tar);
            G[org][tar]++;
            G[tar][org]--;
        }
        if(meet())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}