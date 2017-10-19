#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    char c[128][64];
    int n, len;
    while(scanf("%d", &n) != EOF && n != 0){
       for(int i = 0; i < n; i++)
           scanf("%s", c[i]);
        len = strlen(c[0]);
        printf("------------------------------------------------------------\n");
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(strcmp(c[i], c[j]) > 0){
                    char temp[64];
                    strcpy(temp, c[i]);
                    strcpy(c[i], c[j]);
                    strcpy(c[j], temp);
                }
            }
        }
        //sort(c, c + n);
        for(int i = 0; i < n; i++){
            if(strlen(c[i]) > len)
                len = strlen(c[i]);
        }
        int col = 62 / (len + 2);
        int row = ceil(1.0* n / col);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i + j * row < n)
                    printf("%s", c[i + j * row]);
                else
                    continue;
                for(int k = 0; k < len - strlen(c[i + j * row]); k++)
                    printf(" ");
                if(j != col - 1 && (j + 1) * row + i < n)
                    printf("  ");
            }
            printf("\n");
        }
    }
    return 0;
}