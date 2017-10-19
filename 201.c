#include <iostream>

using namespace std;

int H[10][10];
int V[10][10];

void check(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            printf("%d ", H[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            printf("%d ", V[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(){
    int n, m;
    int x, y;
    int num = 1;
    char c, buff;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        scanf("%c", &buff);
        for(int i = 0; i < m; i++){
            scanf("%c%d%d", &c, &x, &y);
            scanf("%c", &buff);
            if(c == 'H'){
                H[x][y] = 1;
            }
            if(c == 'V'){
                V[y][x] = 1;
            }
        }
        //check(n);
        if(num != 1)
            printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", num);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            int count = 0;
            for(int x0 = 1; (x0 + i) <= n; x0++){
                for(int y0 = 1; (y0 + i) <= n; y0++){
                    int flag = 1;
                    for(int po = y0; po < y0 + i; po++){
                        if(!H[x0][po]||!H[x0 + i][po]){
                            flag = 0;
                            break;
                        }
                    }
                    for(int po = x0; po < x0 + i; po++){
                        if(!V[po][y0]||!V[po][y0 + i]){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag)
                        count++;
                }
            }
            if(count)
                printf("%d square (s) of size %d\n", count, i);
            sum += count;
        }
        if(!sum)
            printf("No completed squares can be found.\n");
        num++;
    }
    return 0;
}