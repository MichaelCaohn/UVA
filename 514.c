#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;

int main(){
    int num, indi;
    int check[1010];
    while(scanf("%d", &num) && num){
        while(scanf("%d", &indi) && indi) {
            memset(check, sizeof(check), 0);
            check[0] = indi;
            for (int i = 1; i < num; i++) {
                scanf("%d", &check[i]);
            }
            /*for (int i = 0; i < num; i++) {
                printf("%d ", check[i]);
            }
            printf("\n");*/
            int no = 1, pos = 0;
            int flag = 1;
            stack <int> s;
            while(pos < num){
                if(no == check[pos]){
                    no++;
                    pos++;
                }
                else if(!s.empty() && s.top() == check[pos]){
                    s.pop();
                    pos++;
                }
                else if(no <= num){
                    s.push(no);
                    no++;
                }
                else{
                   flag = 0;
                    break;
                }
            }
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");
    }
    return 0;
}