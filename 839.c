#include <iostream>

using namespace std;

int solve(int &w){
    int w1, w2, d1, d2, b1 = 1, b2 = 1;
    scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
    if(w1 == 0)
        b1 = solve(w1);
    if(w2 == 0)
        b2 = solve(w2);
    w = w1 + w2;//实时更新子节点的两个值的和
    return b1 && b2 && (w1*d1 == w2*d2);
}
int main(){
    int no, w = 0;
    scanf("%d", &no);
    while(no--){
        int flag = solve(w);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
        if(no)
            printf("\n");
    }
    return 0;
}