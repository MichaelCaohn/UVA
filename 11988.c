#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int maxn = 100000 + 5;
int last, cur, neext[maxn];
char s[maxn];
int main(){//重新创建一个数组来将链表信息存储起来
    while(scanf("%s", s + 1) == 1){
        int n = strlen(s + 1);
        last = cur = 0;
        neext[0] = 0;
        for(int i = 1; i <= n; i++){
            char ch = s[i];
            if(ch == '[')
                cur = 0;
            else if(ch == ']')
                cur = last;
            else{
                neext[i] = neext[cur];
                neext[cur] = i;
                if(cur == last)
                    last = i;
                cur = i;
            }
        }
        for(int i = neext[0]; i != 0; i = neext[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}