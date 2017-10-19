#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main(){
    int arr[20];
    int kase, nu;
    string s;
    set <string> check;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d", &nu);
        for(int i = 0; i < nu; i++){
            scanf("%d", &arr[i]);
        }
        /*for(int i = 0; i < nu; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");*/
        int count =1000;
        while(count--){
            s = "";
            for(int i = 0; i < nu; i++){
                s += (" " + to_string(arr[i]));
            }
            //cout << s << endl;
            if(check.count(s)){
                printf("LOOP\n");
                check.clear();
                break;
            }
            if(!check.count(s)){
                check.insert(s);
            }
            int flag = 0;
            for(int i = 0; i < nu; i++){
                if(arr[i] != 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                printf("ZERO\n");
                check.clear();
                break;
            }
            int temp = arr[0];
            for(int i = 0; i < nu; i++){
                if(i != nu - 1)
                    arr[i] = abs(arr[i] - arr[i + 1]);
                else
                    arr[i] = abs(arr[i] - temp);
            }
        }
    }
    return 0;
}