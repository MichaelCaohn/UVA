#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main(){
    int t, kase = 1;
    while(scanf("%d", &t) && t != 0){
        map <int, int> team;
        for(int i = 0; i < t; i++){
            int n, x;
            scanf("%d", &n);
            for(int j = 0; j < n; j++){
                scanf("%d", &x);
                team[x] = i;
            }
        }
        queue<int> q, q2[1010];
        printf("Scenario #%d\n", kase++);
        while(1){
            int x;
            char cmd[20];
            scanf("%s", cmd);
            if(cmd[0] == 'S')
                break;
            else if(cmd[0] == 'E'){
                scanf("%d", &x);
                int t = team[x];
                if(q2[t].empty())
                    q.push(x);
                q2[t].push(x);
            }
            else if(cmd[0] == 'D'){
                int t = q.front();
                printf("%d\n", q2[t].front());
                q2[t].pop();
                if(q2[t].empty())
                    q.pop();
            }
        }
        printf("\n");
    }
    return 0;
}