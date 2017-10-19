#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    queue <int> s;
    int nu, count;
    while(scanf("%d", &nu) && nu){
        if(nu == 1){
            printf("Discarded cards:\nRemaining card: 1\n");
            continue;
        }
        for(int i = 1; i <= nu; i++){
            s.push(i);
        }
        count = 1;
        while(1){
            if(s.size() == 1){
                printf("\nRemaining card: %d\n", s.front());
                s.pop();
                break;
            }
            else{
                if(count % 2 == 1){
                    if(count == 1){
                        printf("Discarded cards: %d", s.front());
                        s.pop();
                    }
                    else{
                        printf(", %d", s.front());
                        s.pop();
                    }
                }
                else{
                    int temp = s.front();
                    s.pop();
                    s.push(temp);
                }
            }
            count++;
        }
    }
    return 0;
}