#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;
struct Array{
    int x;
    int y;
}collect[32];
int main(){
    int n;
    scanf("%d", &n);
    char ch;
    int x, y;
    while(n--){
        getchar();
        scanf("%c%d%d", &ch, &x, &y);
        collect[ch - 'A'].x = x;
        collect[ch - 'A'].y = y;
        //printf("%d    %d\n", collect[ch - 'A'].x, collect[ch - 'A'].y);
    }
    char s[100];
    while(scanf("%s", s) != EOF){
        int count = 0, flag = 0;
        stack <Array> st;
        int k = strlen(s);
        for(int i = 0; i < k; i++){
            if(s[i] == ')'){
                Array one, two;
                two = st.top();
                st.pop();
                one = st.top();
                st.pop();
                if(one.y != two.x){
                    flag = 1;
                    break;
                }
                count += one.x*one.y*two.y;
                one.y = two.y;
                st.push(one);
            }
            else if(s[i] == '(')
                continue;
            else
                st.push(collect[s[i] - 'A']);
        }
        if(flag)
            printf("error\n");
        else
            printf("%d\n", count);
    }
    return 0;
}