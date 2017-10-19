#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

map <int, set<int>> check;
set<int> dic;
int or_not(double line){
    long long sum;
    for(set <int> :: iterator it = dic.begin(); it != dic.end(); it++){
        sum = 0;
        for(set<int> :: iterator iit = check[*it].begin(); iit != check[*it].end(); iit++){
            sum += *iit;
        }
        if(line != (double)sum/check[*it].size())
            return 0;
    }
    return 1;
}
int main(){
    int nu;
    scanf("%d", &nu);
    while(nu--){
        int count;
        scanf("%d", &count);
        while(count--){
            int x1, y1;
            scanf("%d %d", &x1, &y1);
            if(check.find(y1) == check.end()){
                set <int> s;
                s.insert(x1);
                dic.insert(y1);
                check[y1] = s;
            }
            else{
                check[y1].insert(x1);
            }
        }
        double line;
        long long sum = 0;
        set <int> ::iterator at;
        at = dic.begin();
        for(set <int> :: iterator pt = check[*at].begin(); pt != check[*at].end(); pt++){
            sum += *pt;
        }
        line =  (double)sum / check[*at].size();
        //printf("%lf\n", line);
        if(or_not(line))
            printf("YES\n");
        else
            printf("NO\n");
        check.clear();
        dic.clear();
        /*for(set <int> :: iterator it = dic.begin(); it != dic.end(); it++){
            for(set<int> :: iterator iit = check[*it].begin(); iit != check[*it].end(); iit++){
                printf("%d %d\n", *iit, *it);
            }
        }
        check.clear();
        dic.clear();
        printf("\n");*/
    }
    return 0;
}