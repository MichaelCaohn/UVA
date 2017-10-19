#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;
int main(){
    map<LL, int> mp;
    priority_queue <LL, vector<LL> , greater<LL> > q;
    q.push(1);
    mp[1] = 1;
    int count = 0;
    while(1){
        LL t = q.top();
        q.pop();
        count++;
        if(count == 1500){
            printf("The 1500'th ugly number is %lld.\n", t);
            break;
        }
        if(mp[2*t] != 1){
            mp[2*t] = 1;
            q.push(2*t);
        }
        if(mp[3*t] != 1){
            mp[3*t] = 1;
            q.push(3*t);
        }
        if(mp[5*t] != 1){
            mp[5*t] = 1;
            q.push(5*t);
        }
    }
    return 0;
}